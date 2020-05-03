#include "extension.h"

bool StrEqual(const char *pStr1, const char *pStr2)
{
	if(pStr1 && pStr2) return (V_stricmp(pStr1, pStr2) == 0);
	return false;
}

const char *StrArgs(const char *pStr, ...)
{
	va_list List;
	static char szStr[MAX_STR_LENGTH];

	va_start(List, pStr);
	V_vsnprintf(szStr, sizeof(szStr), pStr, List);
	va_end(List);

	return szStr;
}

const char *StrNextToken(char *pToken, const char *pStr, char sep)
{
	int i = 0;

	if(!pStr || *pStr == '\0')
	{
		*pToken = '\0';
		return pStr;
	}

	while(*pStr != sep && *pStr != '\0')
	{
		if(++i < MAX_STR_LENGTH) *pToken++ = *pStr;
		*pStr++;
	}

	*pToken = '\0';

	return (*pStr == '\0') ? pStr : ++pStr;
}

int Str2Sig(const char *pOld, unsigned char *pNew)
{
	int iPos = 0, iLength = 0;
	char szToken[MAX_STR_LENGTH];

	while(pOld && *pOld != '\0' && iPos <= MAX_STR_LENGTH)
	{
		pOld = StrNextToken(szToken, pOld, ' ');
		pNew[iPos++] = (unsigned char)strtol(szToken, NULL, 16);
		iLength++;
	}

	pNew[iPos] = '\0';

	return iLength;
}

int GetHookFromID(int iID)
{
	int iCount = g_Hacks.m_Hooks.Count();

	for(int i = 0; i < iCount; i++)
	{
		if(g_Hacks.m_Hooks[i].iID == iID)
			return i;
	}

	return -1;
}

KeyValues *LoadKeyValuesFromFile(const char *pFilename)
{
	KeyValues *pKV = new KeyValues("");
	FILE *pFile = fopen(pFilename, "rb");

	if(pFile)
	{
		char *pBuffer;
		long lSize = 0;

		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);

		if((pBuffer = (char *)malloc(sizeof(char) * lSize)))
		{
			fread(pBuffer, 1, lSize, pFile);
			if(!pKV->LoadFromBuffer("", pBuffer)) pKV = NULL;
			free(pBuffer);
		}

		fclose(pFile);

		return pKV;
	}

	return NULL;
}

int GetConfigOffset(KeyValues *pAll, KeyValues *pGame, const char *pName)
{
	KeyValues *pValue;

	if((pGame && (pValue = pGame->FindKey(pName))) || (pAll && (pValue = pAll->FindKey(pName))))
	{
#ifdef WIN32
		if((pValue = pValue->FindKey("windows")))
			return pValue->GetInt();
#else
		if((pValue = pValue->FindKey("linux")))
			return pValue->GetInt();
#endif
	}

	return -1;
}

typedescription_t *FindFieldByName(datamap_t *pDMap, const char *pField)
{
	if(!pDMap) return NULL;

	int iCount = pDMap->dataNumFields;

	for(int i = 0; i < iCount; i++)
	{
		typedescription_t *pTD = &pDMap->dataDesc[i];

		if(pTD->fieldType == FIELD_VOID) continue;

		if(pTD->fieldType == FIELD_EMBEDDED)
		{
			typedescription_t *ret = FindFieldByName(pTD->td, pField);
			if(ret) return ret;
		}

		if(!V_stricmp(pTD->fieldName, pField)) return pTD;
	}

	if(pDMap->baseMap) return FindFieldByName(pDMap->baseMap, pField);

	return NULL;
}

datamap_t *GetDataMap(CBaseEntity *pBase)
{
	if(g_Hacks.m_iOffsetDataMap != -1)
	{
		VFUNC_0(pBase, g_Hacks.m_iOffsetDataMap, datamap_t *);
		return ret;
	}

	return NULL;
}

int GetDataMapOffset(datamap_t *pDMap, const char *pField)
{
	typedescription_t *pTD = FindFieldByName(pDMap, pField);
	if(pTD) return pTD->fieldOffset[0];
	return -1;
}

int GetImpulse(CBaseEntity *pBase)
{
	static int iOffset = -1;
	if(iOffset == -1 ) iOffset = GetDataMapOffset(GetDataMap(pBase), "m_nImpulse");
	if(iOffset != -1 ) return *(int *)((char *)pBase + iOffset);
	return -1;
}

CEventQueue *GetEventQueue(void)
{
	void *pAddr = NULL;
	CEventQueue *pEventQueue = NULL;

	if(pAddr != NULL)
	{
#ifdef WIN32
		unsigned char szSig[MAX_STR_LENGTH];
		int iLength = Str2Sig(g_Hacks.m_szEventQueue, szSig);

		if((pAddr = g_Hacks.SigSymFind("g_EventQueue", szSig, iLength)))
			V_memcpy(&pEventQueue, (char *)pAddr, sizeof(char *));
#else
		if((pAddr = g_Hacks.SigSymFind("g_EventQueue", g_Hacks.m_szEventQueue)))
			pEventQueue = (CEventQueue *)pAddr;
#endif
	}

	return pEventQueue;
}

CGameRules *GetGameRules(void)
{
	void *pAddr = NULL;
	CGameRules *pGameRules = NULL;

#ifdef WIN32
	unsigned char szSig[MAX_STR_LENGTH];
	int iLength = Str2Sig(g_Hacks.m_szGameRules, szSig);

	if((pAddr = g_Hacks.SigSymFind("g_pGameRules", szSig, iLength)))
	{
		V_memcpy(&pGameRules, (char *)pAddr, sizeof(char *));
		pGameRules = *(CGameRules **)pGameRules;
	}
#else
	if((pAddr = g_Hacks.SigSymFind("g_pGameRules", g_Hacks.m_szGameRules)))
	{
		pGameRules = *(CGameRules **)pAddr;
	}
#endif

	return pGameRules;
}

// Thx to BAILOPAN for that :)

void MemProtect(void *pAddr, int iLength, int iProt)
{
#ifdef WIN32
	DWORD old_prot;
	VirtualProtect(pAddr, iLength, iProt, &old_prot);
#else
	void *pAddr2 = (void *)ALIGN(pAddr);
	mprotect(pAddr2, sysconf(_SC_PAGESIZE), iProt);
#endif
}

