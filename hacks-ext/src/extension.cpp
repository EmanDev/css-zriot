#include "extension.h"
#include "hook_decl.h"

IServerGameDLL					*serverdll = NULL;
INetworkStringTableContainer	*networkstringtable = NULL;
CEventQueue						*g_pEventQueue = NULL;
CGameRules						*g_pGameRules = NULL;

CHacks g_Hacks;

SMEXT_LINK(&g_Hacks);

bool CHacks::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	GET_V_IFACE_ANY(serverFactory, serverdll, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
	GET_V_IFACE_CURRENT(engineFactory, networkstringtable, INetworkStringTableContainer, INTERFACENAME_NETWORKSTRINGTABLESERVER);
	return true;
}

bool CHacks::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
	SigSymInit();

	g_pShareSys->AddNatives(myself, hacks_natives);

	KeyValues *pConfig = LoadKeyValuesFromFile(StrArgs("%s/configs/hacks.ext.cfg", smutils->GetSourceModPath()));

	if(pConfig)
	{
		int iOffset = 0;

		KeyValues *pLog = pConfig->FindKey("log");
		if(pLog) m_bLog = (pLog->GetInt() == 1) ? true : false;

		KeyValues *pAll = pConfig->FindKey("*");
		KeyValues *pGame = pConfig->FindKey(smutils->GetGameFolderName());

		m_iOffsetDataMap = GetConfigOffset(pAll, pGame, "GetDataDescMap");

		if((iOffset = GetConfigOffset(pAll, pGame, "Spawn")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Spawn_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "TraceAttack")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(TraceAttack_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "OnTakeDamage")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(OnTakeDamage_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "Event_Killed")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Event_Killed_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "StartTouch")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(StartTouch_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "Touch")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Touch_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "EndTouch")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(EndTouch_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "UpdateOnRemove")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(UpdateOnRemove_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "Weapon_CanUse")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Weapon_CanUse_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "Weapon_Drop")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Weapon_Drop_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "Weapon_CanSwitchTo")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(Weapon_CanSwitchTo_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "CommitSuicide")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(CommitSuicide_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "ImpulseCommands")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(ImpulseCommands_Hook, iOffset, 0, 0); }
		if((iOffset = GetConfigOffset(pAll, pGame, "PlayerRunCommand")) != -1)
		{ SH_MANUALHOOK_RECONFIGURE(PlayerRunCommand_Hook, iOffset, 0, 0); }

		KeyValues *pValue;

		if((pGame && (pValue = pGame->FindKey("g_EventQueue"))) || (pAll && (pValue = pAll->FindKey("g_EventQueue"))))
		{
#ifdef WIN32
			if((pValue = pValue->FindKey("windows")))
				V_strncpy(m_szEventQueue, pValue->GetString(), MAX_STR_LENGTH);
#else
			if((pValue = pValue->FindKey("linux")))
				V_strncpy(m_szEventQueue, pValue->GetString(), MAX_STR_LENGTH);
#endif
		}

		if((pGame && (pValue = pGame->FindKey("g_pGameRules"))) || (pAll && (pValue = pAll->FindKey("g_pGameRules"))))
		{
#ifdef WIN32
			if((pValue = pValue->FindKey("windows")))
				V_strncpy(m_szGameRules, pValue->GetString(), MAX_STR_LENGTH);
#else
			if((pValue = pValue->FindKey("linux")))
				V_strncpy(m_szGameRules, pValue->GetString(), MAX_STR_LENGTH);
#endif
		}

		if(m_bLog) smutils->LogMessage(myself, "Loaded config file (hacks.ext.cfg)");

		pConfig->Clear();
	}

	m_iCurHookID = 0;
	m_iCurPatchID = 0;

	return true;
}

#include "natives/hacks_call.h"
#include "natives/hacks_call_noentity.h"
#include "natives/hacks_call_offset.h"
#include "natives/hacks_find.h"
#include "natives/hacks_hook.h"
#include "natives/hacks_unhook.h"
#include "natives/hacks_adddownload.h"
#include "natives/hacks_createpatch.h"
#include "natives/hacks_patch.h"
#include "natives/hacks_unpatch.h"

const sp_nativeinfo_t hacks_natives[] = 
{
	{"Hacks_Call",				sm_Hacks_Call},
	{"Hacks_Call_Offset",		sm_Hacks_Call_Offset},
	{"Hacks_Call_NoEntity",		sm_Hacks_Call_NoEntity},
	{"Hacks_Find",				sm_Hacks_Find},
	{"Hacks_Hook",				sm_Hacks_Hook},
	{"Hacks_Unhook",			sm_Hacks_Unhook},
	{"Hacks_AddDownload",		sm_Hacks_AddDownload},
	{"Hacks_CreatePatch",		sm_Hacks_CreatePatch},
	{"Hacks_Patch",				sm_Hacks_Patch},
	{"Hacks_Unpatch",			sm_Hacks_Unpatch},
	{NULL,						NULL},
};

