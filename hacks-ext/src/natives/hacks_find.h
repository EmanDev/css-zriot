#ifndef _HACKS_FIND_H
#define _HACKS_FIND_H

/**
* Scans for a function in the memory.
*
* @param name			Name of the function (e.g. "CBaseAnimating::Ignite").
* @param signature		Signature to scan for (Windows). 2A = wildcard
*						 (e.g. "56 8B 74 24 0C 83 FE FF 57 8B 7C 24 0C 74 25 8B")
* @param symbol			Symbol to scan for (Linux).
* @return				CallID, that's needed to call the function.
*/

static cell_t sm_Hacks_Find(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 3)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Find: Not enough parameters");
		return 1;
	}

	void *pAddr = NULL;
	char *pName = NULL;
	char *pSigSym = NULL;

	pCtx->LocalToString(pParams[1], &pName);

#ifdef WIN32
	pCtx->LocalToString(pParams[2], &pSigSym);

	unsigned char szSig[MAX_STR_LENGTH];
	int iLength = Str2Sig(pSigSym, szSig);

	if((pAddr = g_Hacks.SigSymFind(pName, szSig, iLength)))
	{
		g_Hacks.m_Addrs.AddToTail(pAddr);
		return g_Hacks.m_Addrs.Count() - 1;
	}
#else
	pCtx->LocalToString(pParams[3], &pSigSym);

	if((pAddr = g_Hacks.SigSymFind(pName, pSigSym)))
	{
		g_Hacks.m_Addrs.AddToTail(pAddr);
		return g_Hacks.m_Addrs.Count() - 1;
	}
#endif

	return -1;
}

#endif
