#include "extension.h"

bool CHacks::Handler(int iType, CBaseEntity *pBase, bool bPost, int *pResult, int iArg1, int iArg2, int iArg3, int iArg4, int iArg5)
{
	int iEntity = pBase->entindex();
	int iCount = m_Hooks.Count();

	cell_t result = 0;
	bool bSupercede = false;

	for(int i = 0; i < iCount; i++)
	{
		if(m_Hooks[i].iType == iType && m_Hooks[i].pBase == pBase && m_Hooks[i].bPost == bPost)
		{
			m_Hooks[i].pFunc->PushCell(iEntity);
			m_Hooks[i].pFunc->PushCell(iArg1);
			m_Hooks[i].pFunc->PushCell(iArg2);
			m_Hooks[i].pFunc->PushCell(iArg3);
			m_Hooks[i].pFunc->PushCell(iArg4);
			m_Hooks[i].pFunc->PushCell(iArg5);
			m_Hooks[i].pFunc->Execute(&result);

			if(!bSupercede && result != Hacks_Continue)
			{
				bSupercede = true;
				if(pResult) *pResult = result;
			}
		}
	}

	return bSupercede;
}

// Args: 0, 0, 0, 0, 0

void CHacks::Spawn(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);
	if(Handler(HACKS_HTYPE_SPAWN, pBase, false, NULL, 0, 0, 0, 0, 0))
		RETURN_META(MRES_SUPERCEDE);
	RETURN_META(MRES_IGNORED);
}

void CHacks::Spawn_Post(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);
	Handler(HACKS_HTYPE_SPAWN, pBase, true, NULL, 0, 0, 0, 0, 0);
	RETURN_META(MRES_IGNORED);
}

// Args: inflictor, attacker, damage, hitbox, hitgroup

void CHacks::TraceAttack(const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_TRACEATTACK, pBase, false, NULL,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, ptr->hitbox, ptr->hitgroup))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::TraceAttack_Post(const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_TRACEATTACK, pBase, true, NULL,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, ptr->hitbox, ptr->hitgroup);

	RETURN_META(MRES_IGNORED);
}

// Args: inflictor, attacker, damage, damagetype, ammotype

int CHacks::OnTakeDamage(const CTakeDamageInfo &info)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	int iResult = 0;

	if(Handler(HACKS_HTYPE_ONTAKEDAMAGE, pBase, false, &iResult,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, info.m_bitsDamageType, info.m_iAmmoType))
	{ RETURN_META_VALUE(MRES_SUPERCEDE, iResult); }

	RETURN_META_VALUE(MRES_IGNORED, 0);
}

int CHacks::OnTakeDamage_Post(const CTakeDamageInfo &info)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_ONTAKEDAMAGE, pBase, true, NULL,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, info.m_bitsDamageType, info.m_iAmmoType);

	RETURN_META_VALUE(MRES_IGNORED, 0);
}

// Args: inflictor, attacker, damage, damagetype, ammotype

void CHacks::Event_Killed(const CTakeDamageInfo &info)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_EVENT_KILLED, pBase, false, NULL,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, info.m_bitsDamageType, info.m_iAmmoType))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::Event_Killed_Post(const CTakeDamageInfo &info)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_EVENT_KILLED, pBase, true, NULL,
		info.m_hInflictor.GetEntryIndex(), info.m_hAttacker.GetEntryIndex(),
		(int)info.m_flDamage, info.m_bitsDamageType, info.m_iAmmoType);

	RETURN_META(MRES_IGNORED);
}

// Args: other, 0, 0, 0, 0

void CHacks::StartTouch(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_STARTTOUCH, pBase, false, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::StartTouch_Post(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_STARTTOUCH, pBase, true, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0);

	RETURN_META(MRES_IGNORED);
}

// Args: other, 0, 0, 0, 0

void CHacks::Touch(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_TOUCH, pBase, false, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::Touch_Post(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_TOUCH, pBase, true, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0);

	RETURN_META(MRES_IGNORED);
}

// Args: other, 0, 0, 0, 0

void CHacks::EndTouch(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_ENDTOUCH, pBase, false, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::EndTouch_Post(CBaseEntity *pOther)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_ENDTOUCH, pBase, true, NULL,
		(pOther) ? pOther->entindex() : 0, 0, 0, 0, 0);

	RETURN_META(MRES_IGNORED);
}

// Args: 0, 0, 0, 0, 0

void CHacks::UpdateOnRemove(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_UPDATEONREMOVE, pBase, false, NULL, 0, 0, 0, 0, 0))
		RETURN_META(MRES_SUPERCEDE);

	RETURN_META(MRES_IGNORED);
}

void CHacks::UpdateOnRemove_Post(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);
	Handler(HACKS_HTYPE_UPDATEONREMOVE, pBase, true, NULL, 0, 0, 0, 0, 0);
	RETURN_META(MRES_IGNORED);
}

// Args: weapon, 0, 0, 0, 0

bool CHacks::Weapon_CanUse(CBaseCombatWeapon *pWeapon)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	int iResult = 0;

	if(Handler(HACKS_HTYPE_WEAPON_CANUSE, pBase, false, &iResult,
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META_VALUE(MRES_SUPERCEDE, (bool)iResult); }

	RETURN_META_VALUE(MRES_IGNORED, true);
}

bool CHacks::Weapon_CanUse_Post(CBaseCombatWeapon *pWeapon)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_WEAPON_CANUSE, pBase, true, NULL,
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0);

	RETURN_META_VALUE(MRES_IGNORED, true);
}

// Args: weapon, 0, 0, 0, 0

void CHacks::Weapon_Drop(CBaseCombatWeapon *pWeapon, const Vector *pvecTarget, const Vector *pVelocity)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_WEAPON_DROP, pBase, false, NULL, 
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::Weapon_Drop_Post(CBaseCombatWeapon *pWeapon, const Vector *pvecTarget, const Vector *pVelocity)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_WEAPON_DROP, pBase, true, NULL, 
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0);

	RETURN_META(MRES_IGNORED);
}

// Args: weapon, 0, 0, 0, 0

bool CHacks::Weapon_CanSwitchTo(CBaseCombatWeapon *pWeapon)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	int iResult = 0;

	if(Handler(HACKS_HTYPE_WEAPON_CANSWITCHTO, pBase, false, &iResult,
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0))
	{ RETURN_META_VALUE(MRES_SUPERCEDE, (bool)iResult); }

	RETURN_META_VALUE(MRES_IGNORED, true);
}

bool CHacks::Weapon_CanSwitchTo_Post(CBaseCombatWeapon *pWeapon)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_WEAPON_CANSWITCHTO, pBase, true, NULL,
		(pWeapon) ? pWeapon->entindex() : 0, 0, 0, 0, 0);

	RETURN_META_VALUE(MRES_IGNORED, true);
}

// Args: 0, 0, 0, 0, 0

void CHacks::CommitSuicide(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_COMMITSUICIDE, pBase, false, NULL, 0, 0, 0, 0, 0))
		RETURN_META(MRES_SUPERCEDE);

	RETURN_META(MRES_IGNORED);
}

void CHacks::CommitSuicide_Post(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);
	Handler(HACKS_HTYPE_COMMITSUICIDE, pBase, true, NULL, 0, 0, 0, 0, 0);
	RETURN_META(MRES_IGNORED);
}

// Args: impulse, 0, 0, 0, 0

void CHacks::ImpulseCommands(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_IMPULSECOMMANDS, pBase, false, NULL, GetImpulse(pBase), 0, 0, 0, 0))
		RETURN_META(MRES_SUPERCEDE);

	RETURN_META(MRES_IGNORED);
}

void CHacks::ImpulseCommands_Post(void)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_IMPULSECOMMANDS, pBase, true, NULL, GetImpulse(pBase), 0, 0, 0, 0);

	RETURN_META(MRES_IGNORED);
}

// Args: buttons, weapon, forwardmove, sidemove, upmove

void CHacks::PlayerRunCommand(CUserCmd *ucmd, IMoveHelper *moveHelper)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	if(Handler(HACKS_HTYPE_PLAYERRUNCOMMAND, pBase, false, NULL, 
		ucmd->buttons, ucmd->weaponselect, (int)ucmd->forwardmove, 
		(int)ucmd->sidemove, (int)ucmd->upmove))
	{ RETURN_META(MRES_SUPERCEDE); }

	RETURN_META(MRES_IGNORED);
}

void CHacks::PlayerRunCommand_Post(CUserCmd *ucmd, IMoveHelper *moveHelper)
{
	CBaseEntity *pBase = META_IFACEPTR(CBaseEntity);

	Handler(HACKS_HTYPE_PLAYERRUNCOMMAND, pBase, true, NULL, 
		ucmd->buttons, ucmd->weaponselect, (int)ucmd->forwardmove, 
		(int)ucmd->sidemove, (int)ucmd->upmove);

	RETURN_META(MRES_IGNORED);
}

