#ifndef _HOOK_DECL_H
#define _HOOK_DECL_H

SH_DECL_MANUALHOOK0_void(Spawn_Hook, 23 + VTABLE_OFFSET, 0, 0);
SH_DECL_MANUALHOOK3_void(TraceAttack_Hook, 58 + VTABLE_OFFSET, 0, 0, const CTakeDamageInfo &, const Vector &, CGameTrace *);
SH_DECL_MANUALHOOK1(OnTakeDamage_Hook, 60 + VTABLE_OFFSET, 0, 0, int, const CTakeDamageInfo &);
SH_DECL_MANUALHOOK1_void(Event_Killed_Hook, 62 + VTABLE_OFFSET, 0, 0, const CTakeDamageInfo &);
SH_DECL_MANUALHOOK1_void(StartTouch_Hook, 88 + VTABLE_OFFSET, 0, 0, CBaseEntity *);
SH_DECL_MANUALHOOK1_void(Touch_Hook, 89 + VTABLE_OFFSET, 0, 0, CBaseEntity *);
SH_DECL_MANUALHOOK1_void(EndTouch_Hook, 90 + VTABLE_OFFSET, 0, 0, CBaseEntity *);
SH_DECL_MANUALHOOK0_void(UpdateOnRemove_Hook, 95 + VTABLE_OFFSET, 0, 0);
SH_DECL_MANUALHOOK1(Weapon_CanUse_Hook, 216 + VTABLE_OFFSET, 0, 0, bool, CBaseCombatWeapon *);
SH_DECL_MANUALHOOK3_void(Weapon_Drop_Hook, 219 + VTABLE_OFFSET, 0, 0, CBaseCombatWeapon *, const Vector *, const Vector *);
SH_DECL_MANUALHOOK1(Weapon_CanSwitchTo_Hook, 222 + VTABLE_OFFSET, 0, 0, bool, CBaseCombatWeapon *);
SH_DECL_MANUALHOOK0_void(CommitSuicide_Hook, 356 + VTABLE_OFFSET, 0, 0);
SH_DECL_MANUALHOOK0_void(ImpulseCommands_Hook, 297 + VTABLE_OFFSET, 0, 0);
SH_DECL_MANUALHOOK2_void(PlayerRunCommand_Hook, 346 + VTABLE_OFFSET, 0, 0, CUserCmd *, IMoveHelper *);

#endif
