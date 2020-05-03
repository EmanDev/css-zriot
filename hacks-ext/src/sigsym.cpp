#include "extension.h"

#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif

void CHacks::SigSymInit(void)
{
	engine->GetGameDir(m_szBin, sizeof(m_szBin));

#ifdef WIN32
	V_strcat(m_szBin, "\\bin\\server.dll", sizeof(m_szBin));

	m_pBase = 0;
	m_iLength = 0;

	MODULEENTRY32 modent;
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;

	if((hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId())) == INVALID_HANDLE_VALUE)
	{
		if(m_bLog) smutils->LogMessage(myself, "CreateToolhelp32Snapshot failed\n");
		return;
	}

	modent.dwSize = sizeof(MODULEENTRY32);

	if(!Module32First(hModuleSnap, &modent))
	{
		if(m_bLog) smutils->LogMessage(myself, "Module32First failed\n");
		CloseHandle(hModuleSnap);
		return;
	}

	do {
		if(StrEqual(modent.szExePath, m_szBin))
		{
			m_pBase = modent.modBaseAddr;
			m_iLength = modent.modBaseSize;
			break;
		}
	} while(Module32Next(hModuleSnap, &modent));

	CloseHandle(hModuleSnap);

	if(!m_pBase)
	{
		if(m_bLog) smutils->LogMessage(myself, "Could not find server module\n");
		return;
	}
#else
	V_strcat(m_szBin, "/bin/server_i486.so", sizeof(m_szBin));
#endif
}

#ifdef WIN32
void *CHacks::SigSymFind(const char *pName, const unsigned char *pSig, int iLength)
#else
void *CHacks::SigSymFind(const char *pName, const char *pSym)
#endif
{
#ifdef WIN32
	int i = 0, iPos = 0, iHeight = 0;
	unsigned char *pBase = m_pBase;
	unsigned char *pEnd = m_pBase + m_iLength;

	while(pBase < pEnd) 
	{
		for(i = 0; i < iLength; i++)
		{
			if(i >= iHeight) iHeight++;
			if(iPos + i >= (int)m_iLength) break;
			if(pSig[i] != '*' && pSig[i] != pBase[i]) break;
		}

		if(i == iLength)
		{
			if(m_bLog) smutils->LogMessage(myself, "Found function %s at %p", pName, pBase);
			return (void *)pBase;
		}

		pBase++;
		iPos++;
	}

	if(m_bLog) smutils->LogMessage(myself, "Could not find function %s (Failed at height: %d)", pName, iHeight);
#else
	void *pAddr = NULL;
	void *pHandle = dlopen(m_szBin, RTLD_NOW);

	if(!pHandle)
	{
		if(m_bLog) smutils->LogMessage(myself, "Could not find server module");
	}
	else if((pAddr = dlsym(pHandle, pSym)))
	{
		dlclose(pHandle);
		if(m_bLog) smutils->LogMessage(myself, "Found function %s at %p", pName, pAddr);
		return pAddr;
	}

	if(m_bLog) smutils->LogMessage(myself, "Could not find function %s", pName);
#endif

	return NULL;
}
