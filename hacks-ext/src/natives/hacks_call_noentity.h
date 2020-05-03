#ifndef _HACKS_CALL_NOENTITY_H
#define _HACKS_CALL_NOENTITY_H

/**
* Calls a previously scanned function, but without an entity.
*
* @param callid			The returned callid from Hacks_Find.
* @param returntype		Return type, see Hacks_ReturnType.
* @param[x] argtype		Datatype of argument, see Hacks_Param.
* @param[y] arg			Argument for function.
* @return				If there was a failure in the function, it will return -1,
*						 otherwise see Hacks_ReturnType.
*/

static cell_t sm_Hacks_Call_NoEntity(IPluginContext *pCtx, const cell_t *pParams)
{
	if(pParams[0] < 2 || pParams[0] % 2 != 0)
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Call_NoEntity: Not enough parameters");
		return -1;
	}

	int iIndex = pParams[1];

	if(!g_Hacks.m_Addrs.IsValidIndex(iIndex))
	{
		if(g_Hacks.m_bLog) smutils->LogMessage(myself, "Hacks_Call_NoEntity: Invalid callid (%d)", iIndex);
		return -1;
	}

	int iReturn = pParams[2];
	int iArgs = (pParams[0] - 2) / 2;

	if(iArgs == 0)
	{
		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_0_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_0(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_0(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_0(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_0(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 1)
	{
		HACKS_PARAMS(1, 3);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_1_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_1(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_1(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_1(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_1(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 2)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_2_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_2(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_2(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_2(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_2(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 3)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_3_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_3(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_3(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_3(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_3(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 4)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);
		HACKS_PARAMS(4, 9);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_4_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_4(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_4(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_4(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_4(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 5)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);
		HACKS_PARAMS(4, 9);
		HACKS_PARAMS(5, 11);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_5_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_5(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_5(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_5(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_5(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 6)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);
		HACKS_PARAMS(4, 9);
		HACKS_PARAMS(5, 11);
		HACKS_PARAMS(6, 13);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_6_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_6(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_6(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_6(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_6(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 7)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);
		HACKS_PARAMS(4, 9);
		HACKS_PARAMS(5, 11);
		HACKS_PARAMS(6, 13);
		HACKS_PARAMS(7, 15);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_7_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_7(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_7(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_7(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_7(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}
	else if(iArgs == 8)
	{
		HACKS_PARAMS(1, 3);
		HACKS_PARAMS(2, 5);
		HACKS_PARAMS(3, 7);
		HACKS_PARAMS(4, 9);
		HACKS_PARAMS(5, 11);
		HACKS_PARAMS(6, 13);
		HACKS_PARAMS(7, 15);
		HACKS_PARAMS(8, 17);

		if(iReturn == HACKS_RTYPE_VOID)
		{
			FUNC_NOENTITY_8_VOID(g_Hacks.m_Addrs[iIndex]);
			return 0;
		}
		else if(iReturn == HACKS_RTYPE_INT)
		{
			FUNC_NOENTITY_8(g_Hacks.m_Addrs[iIndex], int);
			return ret;
		}
		else if(iReturn == HACKS_RTYPE_EDICT)
		{
			FUNC_NOENTITY_8(g_Hacks.m_Addrs[iIndex], edict_t *);
			if(ret == NULL) return -1;
			return engine->IndexOfEdict(ret);
		}
		else if(iReturn == HACKS_RTYPE_ENTITY)
		{
			FUNC_NOENTITY_8(g_Hacks.m_Addrs[iIndex], CBaseEntity *);
			if(ret == NULL) return -1;
			return ret->entindex();
		}
		else if(iReturn == HACKS_RTYPE_FLOAT)
		{
			FUNC_NOENTITY_8(g_Hacks.m_Addrs[iIndex], float);
			return sp_ftoc(ret);
		}
	}

	return -1;
}

#endif
