#ifndef _UTILS_H
#define _UTILS_H

bool StrEqual(const char *pStr1, const char *pStr2);

const char *StrArgs(const char *pStr, ...);

const char *StrNextToken(char *pToken, const char *pStr, char sep);

int Str2Sig(const char *pOld, unsigned char *pNew);

int GetHookFromID(int iID);

KeyValues *LoadKeyValuesFromFile(const char *pFilename);

int GetConfigOffset(KeyValues *pAll, KeyValues *pGame, const char *pName);

typedescription_t *FindFieldByName(datamap_t *pDMap, const char *pField);

datamap_t *GetDataMap(CBaseEntity *pBase);

int GetDataMapOffset(datamap_t *pDMap, const char *pField);

int GetImpulse(CBaseEntity *pBase);

CEventQueue *GetEventQueue(void);

CGameRules *GetGameRules(void);

void MemProtect(void *pAddr, int iLength, int iProt);

#endif
