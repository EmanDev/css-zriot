#ifndef _HACKS_CALL_OFFSET_H
#define _HACKS_CALL_OFFSET_H

/**
* Calls a virtual function by its offset.
*
* @param entity			Index of the entity.
* @param windows		Windows offset.
* @param linux			Linux offset.
* @param calltype		Type to call, see Hacks_CallType.
* @param returntype		Return type, see  Hacks_ReturnType.
* @param[x] argtype		Datatype of argument, see Hacks_Param.
* @param[y] arg			Argument for function.
* @return				If there was a failure in the function, it will return -1,
*						 otherwise see Hacks_ReturnType.
*/

static cell_t sm_Hacks_Call_Offset(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 5 || pParams[0] % 2 == 0)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_Offset: Not enough parameters");
		return -1;
	}

	edict_t *pEntity = NULL;
	CBaseEntity *pBase = NULL;
	CCollisionProperty *pCollision = NULL;
	IPhysicsObject *pPhysics = NULL;

#ifdef WIN32
	int iOffset = pParams[2];
#else
	int iOffset = pParams[3];
#endif

	int iType = pParams[4];

	if(iType == HACKS_CTYPE_GAMERULES)
	{
		if(!g_pGameRules && !(g_pGameRules = GetGameRules()))
		{
			if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_Offset: Could not get gamerules pointer");
			return -1;
		}
	}
	else if(iType == HACKS_CTYPE_EVENTQUEUE)
	{
		if(!g_pEventQueue && !(g_pEventQueue = GetEventQueue()))
		{
			if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Could not get eventqueue pointer");
			return -1;
		}
	}
	else if(!(pEntity = engine->PEntityOfEntIndex(pParams[1])) || !pEntity->GetUnknown() || !(pBase = pEntity->GetUnknown()->GetBaseEntity()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_Offset: Could not get entity (%d)", pParams[1]);
		return -1;
	}

	int iReturn = pParams[5];
	int iArgs = (pParams[0] - 5) / 2;

	if(iType == HACKS_CTYPE_COLLISIONPROP && !(pCollision = pBase->CollisionProp()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_Offset: Could not net collisionprop");
		return -1;
	}
	else if(iType == HACKS_CTYPE_PHYSICSOBJECT && !(pPhysics = pBase->VPhysicsGetObject()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_Offset: Could not net physicsobject");
		return -1;
	}

	void *pAddr = NULL;

	if(iType == HACKS_CTYPE_COLLISIONPROP) pAddr = pCollision;
	else if(iType == HACKS_CTYPE_PHYSICSOBJECT) pAddr = pPhysics;
	else if(iType == HACKS_CTYPE_GAMERULES) pAddr = g_pGameRules;
	else if(iType == HACKS_CTYPE_EVENTQUEUE) pAddr = g_pEventQueue;
	else pAddr = pBase;

	if(iArgs == 0)
	{
		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_0_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_0(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_0(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_0(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_0(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 1)
	{
		HACKS_PARAMS(1, 6);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_1_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_1(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_1(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_1(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_1(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 2)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_2_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_2(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_2(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_2(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_2(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 3)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_3_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_3(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_3(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_3(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_3(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 4)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);
		HACKS_PARAMS(4, 12);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_4_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_4(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_4(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_4(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_4(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 5)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);
		HACKS_PARAMS(4, 12);
		HACKS_PARAMS(5, 14);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_5_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_5(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_5(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_5(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_5(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 6)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);
		HACKS_PARAMS(4, 12);
		HACKS_PARAMS(5, 14);
		HACKS_PARAMS(6, 16);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_6_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_6(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_6(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_6(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_6(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 7)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);
		HACKS_PARAMS(4, 12);
		HACKS_PARAMS(5, 14);
		HACKS_PARAMS(6, 16);
		HACKS_PARAMS(7, 18);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_7_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_7(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_7(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_7(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_7(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 8)
	{
		HACKS_PARAMS(1, 6);
		HACKS_PARAMS(2, 8);
		HACKS_PARAMS(3, 10);
		HACKS_PARAMS(4, 12);
		HACKS_PARAMS(5, 14);
		HACKS_PARAMS(6, 16);
		HACKS_PARAMS(7, 18);
		HACKS_PARAMS(8, 20);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			VFUNC_8_VOID(pAddr, iOffset);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			VFUNC_8(pAddr, iOffset, int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			VFUNC_8(pAddr, iOffset, float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			VFUNC_8(pAddr, iOffset, edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			VFUNC_8(pAddr, iOffset, CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}

	return -1;
}

#endif
