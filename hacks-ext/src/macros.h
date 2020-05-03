#ifndef _MACROS_H
#define _MACROS_H

#ifdef WIN32
#define VTABLE_OFFSET 0
#define FUNC_FAST __fastcall 
#define FUNC_TYPE , void *
#define FUNC_VALUE , 0
#else
#define VTABLE_OFFSET 1
#define FUNC_FAST
#define FUNC_TYPE
#define FUNC_VALUE
#endif

#define FUNC_0(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE);

#define FUNC_0_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE);

#define FUNC_1(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1);

#define FUNC_1_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1);

#define FUNC_2(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2);

#define FUNC_2_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2);

#define FUNC_3(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3);

#define FUNC_3_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3);

#define FUNC_4(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4);

#define FUNC_4_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4);

#define FUNC_5(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5);

#define FUNC_5_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5);

#define FUNC_6(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define FUNC_6_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define FUNC_7(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define FUNC_7_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define FUNC_8(t, p, a, r) \
	typedef r (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

#define FUNC_8_VOID(t, p, a) \
	typedef void (FUNC_FAST*func)(t FUNC_TYPE, void *, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(p FUNC_VALUE, pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

//=====================================================================

#define FUNC_NOENTITY_0(a, r) \
	typedef r(*func)(void); \
	func thisfunc = (func)a; \
	r ret = thisfunc();

#define FUNC_NOENTITY_0_VOID(a) \
	typedef void(*func)(void); \
	func thisfunc = (func)a; \
	thisfunc();

#define FUNC_NOENTITY_1(a, r) \
	typedef r(*func)(void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1);

#define FUNC_NOENTITY_1_VOID(a) \
	typedef void(*func)(void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1);

#define FUNC_NOENTITY_2(a, r) \
	typedef r(*func)(void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2);

#define FUNC_NOENTITY_2_VOID(a) \
	typedef void(*func)(void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2);

#define FUNC_NOENTITY_3(a, r) \
	typedef r(*func)(void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3);

#define FUNC_NOENTITY_3_VOID(a) \
	typedef void(*func)(void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3);

#define FUNC_NOENTITY_4(a, r) \
	typedef r(*func)(void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3, pArg4);

#define FUNC_NOENTITY_4_VOID(a) \
	typedef void(*func)(void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3, pArg4);

#define FUNC_NOENTITY_5(a, r) \
	typedef r(*func)(void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5);

#define FUNC_NOENTITY_5_VOID(a) \
	typedef void(*func)(void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5);

#define FUNC_NOENTITY_6(a, r) \
	typedef r(*func)(void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define FUNC_NOENTITY_6_VOID(a) \
	typedef void(*func)(void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define FUNC_NOENTITY_7(a, r) \
	typedef r(*func)(void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define FUNC_NOENTITY_7_VOID(a) \
	typedef void(*func)(void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define FUNC_NOENTITY_8(a, r) \
	typedef r(*func)(void *, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	r ret = thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

#define FUNC_NOENTITY_8_VOID(a) \
	typedef void(*func)(void *, void *, void *, void *, void *, void *, void *, void *); \
	func thisfunc = (func)a; \
	thisfunc(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

//=====================================================================

class CEmpty {};

#ifdef WIN32
#define VFUNC_MAIN \
	void *addr; } u; u.addr = func;
#else
#define VFUNC_MAIN \
	struct { void *addr; intptr_t adjustor; } s; } u; \
	u.s.addr = func; u.s.adjustor = 0;
#endif

#define VFUNC_BEGIN(p, o) \
	void **ptr = *(void ***)&p; \
	void **vtable = *(void ***)p; \
	void *func = vtable[o];

#define VFUNC_0(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)();

#define VFUNC_0_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)();

#define VFUNC_1(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1);

#define VFUNC_1_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1);

#define VFUNC_2(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2);

#define VFUNC_2_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2);

#define VFUNC_3(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3);

#define VFUNC_3_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3);

#define VFUNC_4(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4);

#define VFUNC_4_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4);

#define VFUNC_5(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5);

#define VFUNC_5_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5);

#define VFUNC_6(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define VFUNC_6_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);

#define VFUNC_7(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define VFUNC_7_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);

#define VFUNC_8(p, o, r) \
	VFUNC_BEGIN(p, o) \
	union { r(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	r ret = (r)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

#define VFUNC_8_VOID(p, o) \
	VFUNC_BEGIN(p, o) \
	union { void(CEmpty::*mfpnew)(void *, void *, void *, void *, void *, void *, void *, void *); \
	VFUNC_MAIN \
	(void)(reinterpret_cast<CEmpty*>(ptr)->*u.mfpnew)(pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8);

//=====================================================================

#define HACKS_PARAMS(num, index) \
	cell_t *pType##num = NULL;\
	void *pArg##num = NULL; \
	cell_t *pCell##num = NULL; \
	char *pStr##num = NULL; \
	Vector Vec##num; \
	QAngle Ang##num; \
	edict_t *pEdict##num = NULL; \
	CBaseEntity *pEntity##num = NULL; \
	IPhysicsObject *pPhysics##num = NULL; \
	\
	pCtx->LocalToPhysAddr(pParams[index], &pType##num); \
	\
	if(*pType##num == HACKS_PARAM_NULL) \
{ \
	pArg##num = NULL; \
} \
	else if(*pType##num == HACKS_PARAM_INT || *pType##num == HACKS_PARAM_FLOAT) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	pArg##num = *(void **)pCell##num; \
} \
	else if(*pType##num == HACKS_PARAM_STRING) \
{ \
	pCtx->LocalToString(pParams[index + 1], &pStr##num); \
	pArg##num = (void *)pStr##num; \
} \
	else if(*pType##num == HACKS_PARAM_VECTOR) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	Vec##num.x = sp_ctof(pCell##num[0]); \
	Vec##num.y = sp_ctof(pCell##num[1]); \
	Vec##num.z = sp_ctof(pCell##num[2]); \
	pArg##num = (void *)&Vec##num; \
} \
	else if(*pType##num == HACKS_PARAM_QANGLE) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	Ang##num.x = sp_ctof(pCell##num[0]); \
	Ang##num.y = sp_ctof(pCell##num[1]); \
	Ang##num.z = sp_ctof(pCell##num[2]); \
	pArg##num = (void *)&Ang##num; \
} \
	else if(*pType##num == HACKS_PARAM_EDICT) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	pEdict##num = engine->PEntityOfEntIndex(pCell##num[0]); \
	if(pEdict##num == NULL) \
	return -1; \
	pArg##num = (void *)pEdict##num; \
} \
	else if(*pType##num == HACKS_PARAM_ENTITY) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	pEdict##num = engine->PEntityOfEntIndex(pCell##num[0]); \
	if(pEdict##num == NULL || !pEdict##num->GetUnknown() || (pEntity##num = pEdict##num->GetUnknown()->GetBaseEntity()) == NULL) \
	return -1; \
	pArg##num = (void *)pEntity##num; \
} \
	else if(*pType##num == HACKS_PARAM_PHYSICSOBJECT) \
{ \
	pCtx->LocalToPhysAddr(pParams[index + 1], &pCell##num); \
	pEdict##num = engine->PEntityOfEntIndex(pCell##num[0]); \
	if(pEdict##num == NULL || !pEdict##num->GetUnknown() || (pEntity##num = pEdict##num->GetUnknown()->GetBaseEntity()) == NULL || (pPhysics##num = pEntity##num->VPhysicsGetObject())) \
	return -1; \
	pArg##num = (void *)pPhysics##num; \
}

#endif
