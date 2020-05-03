#ifndef _HACKS_CALL_H
#define _HACKS_CALL_H

/**
* Calls a previously scanned function.
*
* @param entity			Index of the entity.
* @param callid			The returned callid from Hacks_Find.
* @param calltype		Type to call, see Hacks_CallType.
* @param returntype		Return type, see Hacks_ReturnType.
* @param[x] argtype		Datatype of argument, see Hacks_Param.
* @param[y] arg			Argument for function.
* @return				If there was a failure in the function, it will return -1,
*						 otherwise see Hacks_ReturnType.
*/

static cell_t sm_Hacks_Call(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 4 || pParams[0] % 2 != 0)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Not enough parameters");
		return -1;
	}

	edict_t *pEntity = NULL;
	CBaseEntity *pBase = NULL;
	CCollisionProperty *pCollision = NULL;
	IPhysicsObject *pPhysics = NULL;

	int iIndex = pParams[2];
	int iType = pParams[3];

	if(iType == HACKS_CTYPE_GAMERULES)
	{
		if(!g_pGameRules && !(g_pGameRules = GetGameRules()))
		{
			if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Could not get gamerules pointer");
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
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Could not get entity (%d)", pParams[1]);
		return -1;
	}

	if(iType == HACKS_CTYPE_COLLISIONPROP && !(pCollision = pBase->CollisionProp()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Could not net collisionprop");
		return -1;
	}
	else if(iType == HACKS_CTYPE_PHYSICSOBJECT && !(pPhysics = pBase->VPhysicsGetObject()))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Could not net physicsobject");
		return -1;
	}
	else if(!g_Hacks.m_Addrs.IsValidIndex(iIndex))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call: Invalid callid (%d)", iIndex);
		return -1;
	}

	int iReturn = pParams[4];
	int iArgs = (pParams[0] - 4) / 2;

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
			FUNC_0_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_0(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_0(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_0(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_0(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 1)
	{
		HACKS_PARAMS(1, 5);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_1_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_1(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_1(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_1(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_1(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 2)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_2_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_2(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_2(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_2(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_2(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 3)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_3_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_3(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_3(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_3(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_3(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 4)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);
		HACKS_PARAMS(4, 11);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_4_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_4(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_4(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_4(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_4(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 5)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);
		HACKS_PARAMS(4, 11);
		HACKS_PARAMS(5, 13);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_5_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_5(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_5(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_5(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_5(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 6)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);
		HACKS_PARAMS(4, 11);
		HACKS_PARAMS(5, 13);
		HACKS_PARAMS(6, 15);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_6_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_6(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_6(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_6(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_6(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 7)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);
		HACKS_PARAMS(4, 11);
		HACKS_PARAMS(5, 13);
		HACKS_PARAMS(6, 15);
		HACKS_PARAMS(7, 17);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_7_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_7(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_7(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_7(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_7(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}
	else if(iArgs == 8)
	{
		HACKS_PARAMS(1, 5);
		HACKS_PARAMS(2, 7);
		HACKS_PARAMS(3, 9);
		HACKS_PARAMS(4, 11);
		HACKS_PARAMS(5, 13);
		HACKS_PARAMS(6, 15);
		HACKS_PARAMS(7, 17);
		HACKS_PARAMS(8, 19);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_8_VOID(void *, pAddr, g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_8(void *, pAddr, g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_8(void *, pAddr, g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_8(void *, pAddr, g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_8(void *, pAddr, g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
	}

	return -1;
}

#endif
