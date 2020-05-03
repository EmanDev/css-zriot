#ifndef _HACKS_UNPATCH_H
#define _HACKS_UNPATCH_H

/**
 * Writes the original bytes to a given address
 *
 * @param patchid			The returned patchid from Hacks_CreatePatch.
 * @noreturn
 */

static cell_t sm_Hacks_Unpatch(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 1)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Unpatch: Not enough parameters");
		return -1;
	}

	int iIndex = pParams[1];

	if(!g_Hacks.m_Patches.IsValidIndex(iIndex))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Unpatch: Invalid patchid (%d)", iIndex);
		return -1;
	}

	MemProtect(g_Hacks.m_Patches[iIndex].pAddr, g_Hacks.m_Patches[iIndex].iLength, PAGE_EXECUTE_READWRITE);
	V_memcpy(g_Hacks.m_Patches[iIndex].pAddr, g_Hacks.m_Patches[iIndex].szOld, g_Hacks.m_Patches[iIndex].iLength);

	return 1;
}

#endif
