#ifndef _HACKS_UNHOOK_H
#define _HACKS_UNHOOK_H

/**
* Unhooks a virtual function.
*
* @param hookid		The returned hookid from Hacks_Hook.
* @noreturn
*/

static cell_t sm_Hacks_Unhook(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 1)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Unhook: Not enough parameters");
		return -1;
	}

	int iID = pParams[1];
	int iIndex = GetHookFromID(iID);

	if(iIndex == -1)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Unhook: Invalid hookid (%d)", iID);
		return -1;
	}

	bool bRemove = true;
	int iCount = g_Hacks.m_Hooks.Count();

	for(int i = 0; i < iCount; i++)
	{
		if(g_Hacks.m_Hooks[i].iID != iID && g_Hacks.m_Hooks[i].iType == g_Hacks.m_Hooks[iIndex].iType && g_Hacks.m_Hooks[i].pBase == g_Hacks.m_Hooks[iIndex].pBase && g_Hacks.m_Hooks[i].bPost == g_Hacks.m_Hooks[iIndex].bPost)
		{
			bRemove = false;
			break;
		}
	}

	if(bRemove)
	{
		int iType = g_Hacks.m_Hooks[iIndex].iType;
		int iEntity = g_Hacks.m_Hooks[iIndex].iEntity;
		CBaseEntity *pBase = g_Hacks.m_Hooks[iIndex].pBase;
		bool bPost = g_Hacks.m_Hooks[iIndex].bPost;

		if(iType == HACKS_HTYPE_SPAWN) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Spawn_Hook, pBase, &g_Hacks, &CHacks::Spawn_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Spawn_Hook, pBase, &g_Hacks, &CHacks::Spawn, bPost); }
		} else if(iType == HACKS_HTYPE_TRACEATTACK) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(TraceAttack_Hook, pBase, &g_Hacks, &CHacks::TraceAttack_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(TraceAttack_Hook, pBase, &g_Hacks, &CHacks::TraceAttack, bPost); }
		} else if(iType == HACKS_HTYPE_ONTAKEDAMAGE) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(OnTakeDamage_Hook, pBase, &g_Hacks, &CHacks::OnTakeDamage_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(OnTakeDamage_Hook, pBase, &g_Hacks, &CHacks::OnTakeDamage, bPost); }
		} else if(iType == HACKS_HTYPE_EVENT_KILLED) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Event_Killed_Hook, pBase, &g_Hacks, &CHacks::Event_Killed_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Event_Killed_Hook, pBase, &g_Hacks, &CHacks::Event_Killed, bPost); }
		} else if(iType == HACKS_HTYPE_STARTTOUCH) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(StartTouch_Hook, pBase, &g_Hacks, &CHacks::StartTouch_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(StartTouch_Hook, pBase, &g_Hacks, &CHacks::StartTouch, bPost); }
		} else if(iType == HACKS_HTYPE_TOUCH) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Touch_Hook, pBase, &g_Hacks, &CHacks::Touch_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Touch_Hook, pBase, &g_Hacks, &CHacks::Touch, bPost); }
		} else if(iType == HACKS_HTYPE_ENDTOUCH) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(EndTouch_Hook, pBase, &g_Hacks, &CHacks::EndTouch_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(EndTouch_Hook, pBase, &g_Hacks, &CHacks::EndTouch, bPost); }
		} else if(iType == HACKS_HTYPE_UPDATEONREMOVE) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(UpdateOnRemove_Hook, pBase, &g_Hacks, &CHacks::UpdateOnRemove_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(UpdateOnRemove_Hook, pBase, &g_Hacks, &CHacks::UpdateOnRemove, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_CANUSE) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_CanUse_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanUse_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_CanUse_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanUse, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_DROP) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_Drop_Hook, pBase, &g_Hacks, &CHacks::Weapon_Drop_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_Drop_Hook, pBase, &g_Hacks, &CHacks::Weapon_Drop, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_CANSWITCHTO) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_CanSwitchTo_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanSwitchTo_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(Weapon_CanSwitchTo_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanSwitchTo, bPost); }
		} else if(iType == HACKS_HTYPE_COMMITSUICIDE) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(CommitSuicide_Hook, pBase, &g_Hacks, &CHacks::CommitSuicide_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(CommitSuicide_Hook, pBase, &g_Hacks, &CHacks::CommitSuicide, bPost); }
		} else if(iType == HACKS_HTYPE_IMPULSECOMMANDS) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(ImpulseCommands_Hook, pBase, &g_Hacks, &CHacks::ImpulseCommands_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(ImpulseCommands_Hook, pBase, &g_Hacks, &CHacks::ImpulseCommands, bPost); }
		} else if(iType == HACKS_HTYPE_PLAYERRUNCOMMAND) {
			if(bPost) { SH_REMOVE_MANUALHOOK_MEMFUNC(PlayerRunCommand_Hook, pBase, &g_Hacks, &CHacks::PlayerRunCommand_Post, bPost); }
			else { SH_REMOVE_MANUALHOOK_MEMFUNC(PlayerRunCommand_Hook, pBase, &g_Hacks, &CHacks::PlayerRunCommand, bPost); }
		}

		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Unhook: Removed hook for %d (Type: %d)", iEntity, iType);
	}

	g_Hacks.m_Hooks.Remove(iIndex);

	return 1;
}

#endif
