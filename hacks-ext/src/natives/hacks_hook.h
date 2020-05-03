#ifndef _HACKS_CALL_HOOK_H
#define _HACKS_CALL_HOOK_H

/**
* Hooks a virtual function.
*
* @param entity		Index of the entity.
* @param type		Type of the function, see Hacks_HookType.
* @param handler	Your function that will be called on hooking.
* @param post		True for post operation, false for pre operation.
* @return			HookID, that's needed to unhook.
*/

static cell_t sm_Hacks_Hook(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 4)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Hook: Not enough parameters");
		return -1;
	}

	int iEntity = pParams[1];
	int iType = pParams[2];
	bool bPost = pParams[4];

	IPluginFunction *pFunc = pCtx->GetFunctionById(pParams[3]);

	if(!pFunc)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Hook: Could not find handler function");
		return -1;
	}

	edict_t *pEntity = engine->PEntityOfEntIndex(pParams[1]);
	CBaseEntity *pBase = NULL;

	if((!pEntity || !pEntity->GetUnknown()) || !(pBase = pEntity->GetUnknown()->GetBaseEntity()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Hook: Could not get entity (%d)", iEntity);
		return -1;
	}

	bool bAdd = true;
	int iCount = g_Hacks.m_Hooks.Count();

	for(int i = 0; i < iCount; i++)
	{
		if(g_Hacks.m_Hooks[i].iType == iType && g_Hacks.m_Hooks[i].pBase == pBase && g_Hacks.m_Hooks[i].bPost == bPost)
		{
			bAdd = false;
			break;
		}
	}

	g_Hacks.m_Hooks.AddToTail();
	g_Hacks.m_Hooks[iCount].iID = g_Hacks.m_iCurHookID++;
	g_Hacks.m_Hooks[iCount].iType = iType;
	g_Hacks.m_Hooks[iCount].iEntity = iEntity;
	g_Hacks.m_Hooks[iCount].pBase = pBase;
	g_Hacks.m_Hooks[iCount].pFunc = pFunc;
	g_Hacks.m_Hooks[iCount].bPost = bPost;

	if(bAdd)
	{
		if(iType == HACKS_HTYPE_SPAWN) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Spawn_Hook, pBase, &g_Hacks, &CHacks::Spawn_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Spawn_Hook, pBase, &g_Hacks, &CHacks::Spawn, bPost); }
		} else if(iType == HACKS_HTYPE_TRACEATTACK) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(TraceAttack_Hook, pBase, &g_Hacks, &CHacks::TraceAttack_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(TraceAttack_Hook, pBase, &g_Hacks, &CHacks::TraceAttack, bPost); }
		} else if(iType == HACKS_HTYPE_ONTAKEDAMAGE) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(OnTakeDamage_Hook, pBase, &g_Hacks, &CHacks::OnTakeDamage_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(OnTakeDamage_Hook, pBase, &g_Hacks, &CHacks::OnTakeDamage, bPost); }
		} else if(iType == HACKS_HTYPE_EVENT_KILLED) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Event_Killed_Hook, pBase, &g_Hacks, &CHacks::Event_Killed_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Event_Killed_Hook, pBase, &g_Hacks, &CHacks::Event_Killed, bPost); }
		} else if(iType == HACKS_HTYPE_STARTTOUCH) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(StartTouch_Hook, pBase, &g_Hacks, &CHacks::StartTouch_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(StartTouch_Hook, pBase, &g_Hacks, &CHacks::StartTouch, bPost); }
		} else if(iType == HACKS_HTYPE_TOUCH) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Touch_Hook, pBase, &g_Hacks, &CHacks::Touch_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Touch_Hook, pBase, &g_Hacks, &CHacks::Touch, bPost); }
		} else if(iType == HACKS_HTYPE_ENDTOUCH) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(EndTouch_Hook, pBase, &g_Hacks, &CHacks::EndTouch_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(EndTouch_Hook, pBase, &g_Hacks, &CHacks::EndTouch, bPost); }
		} else if(iType == HACKS_HTYPE_UPDATEONREMOVE) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(UpdateOnRemove_Hook, pBase, &g_Hacks, &CHacks::UpdateOnRemove_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(UpdateOnRemove_Hook, pBase, &g_Hacks, &CHacks::UpdateOnRemove, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_CANUSE) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_CanUse_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanUse_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_CanUse_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanUse, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_DROP) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_Drop_Hook, pBase, &g_Hacks, &CHacks::Weapon_Drop_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_Drop_Hook, pBase, &g_Hacks, &CHacks::Weapon_Drop, bPost); }
		} else if(iType == HACKS_HTYPE_WEAPON_CANSWITCHTO) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_CanSwitchTo_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanSwitchTo_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(Weapon_CanSwitchTo_Hook, pBase, &g_Hacks, &CHacks::Weapon_CanSwitchTo, bPost); }
		} else if(iType == HACKS_HTYPE_COMMITSUICIDE) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(CommitSuicide_Hook, pBase, &g_Hacks, &CHacks::CommitSuicide_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(CommitSuicide_Hook, pBase, &g_Hacks, &CHacks::CommitSuicide, bPost); }
		} else if(iType == HACKS_HTYPE_IMPULSECOMMANDS) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(ImpulseCommands_Hook, pBase, &g_Hacks, &CHacks::ImpulseCommands_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(ImpulseCommands_Hook, pBase, &g_Hacks, &CHacks::ImpulseCommands, bPost); }
		} else if(iType == HACKS_HTYPE_PLAYERRUNCOMMAND) {
			if(bPost) { SH_ADD_MANUALHOOK_MEMFUNC(PlayerRunCommand_Hook, pBase, &g_Hacks, &CHacks::PlayerRunCommand_Post, bPost); }
			else { SH_ADD_MANUALHOOK_MEMFUNC(PlayerRunCommand_Hook, pBase, &g_Hacks, &CHacks::PlayerRunCommand, bPost); }
		}

		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Hook: Added hook for %d (Type: %d)", iEntity, iType);
	}

	return g_Hacks.m_Hooks[iCount].iID;
}

#endif
