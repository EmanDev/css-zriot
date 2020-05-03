#ifndef _HACKS_CREATEPATCH_H
#define _HACKS_CREATEPATCH_H

/**
 * Creates a patch that you can use with Hacks_Patch/Hacks_Unpatch
 *
 * @param callid			The returned callid from Hacks_Find.
 * @param windows_bytes		New Bytes (eg "C2 08 00")
 * @param windows_offset	Offset (addr to patch = func_addr + offset)
 * @param linux_bytes
 * @param linux_offset
 * @return					PatchID, that's needed to patch/unpatch.
 */

static cell_t sm_Hacks_CreatePatch(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 5)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_CreatePatch: Not enough parameters");
		return -1;
	}

	int iIndex = pParams[1];

	if(!g_Hacks.m_Addrs.IsValidIndex(iIndex))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_CreatePatch: Invalid callid (%d)", iIndex);
		return -1;
	}

	g_Hacks.m_Patches.AddToTail();

	char *pPatch = NULL;

#ifdef WIN32
	pCtx->LocalToString(pParams[2], &pPatch);
	g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iLength = Str2Sig(pPatch, g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].szNew);
	g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iOffset = pParams[3];
#else
	pCtx->LocalToString(pParams[4], &pPatch);
	g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iLength = Str2Sig(pPatch, g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].szNew);
	g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iOffset = pParams[5];
#endif

	g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].pAddr = (unsigned char *)g_Hacks.m_Addrs[iIndex] + g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iOffset;

	for(int i = 0; i < g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].iLength; i++)
		g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].szOld[i] = g_Hacks.m_Patches[g_Hacks.m_iCurPatchID].pAddr[i];

	return g_Hacks.m_iCurPatchID++;
}

#endif
