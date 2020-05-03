#ifndef _HACKS_ADDDOWNLOAD_H
#define _HACKS_ADDDOWNLOAD_H

/**
* Adds a file to be force downloaded (cleared every map change).
*
* @param ...		Each argument = One file that will be added.
* @noreturn
*/

static cell_t sm_Hacks_AddDownload(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 1)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_AddDownload: Not enough parameters");
		return -1;
	}

	INetworkStringTable *pDownloadables = networkstringtable->FindTable("downloadables");

	if(!pDownloadables)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_AddDownload: Could not find downloadables");
		return -1;
	}

	char *pStr = NULL;
	bool bSave = engine->LockNetworkStringTables(false);

	for(int i = 1; i <= pParams[0]; i++)
	{
		pCtx->LocalToString(pParams[i], &pStr);
		pDownloadables->AddString(pStr);
	}

	engine->LockNetworkStringTables(bSave);

	return 1;
}

#endif
