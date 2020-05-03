#ifndef _EXTENSION_H_
#define _EXTENSION_H_

#ifndef WIN32
#include <sys/mman.h>
#define	PAGE_EXECUTE_READWRITE	PROT_READ|PROT_WRITE|PROT_EXEC
#define	PAGE_SIZE	4096
#define ALIGN(ar)	((long)ar & ~(PAGE_SIZE-1))
#endif

#define Hacks_Continue -54321
#define MAX_STR_LENGTH 1024

#define GAME_DLL
#include "cbase.h"
#include "eventqueue.h"
#include "smsdk_ext.h"
#include "macros.h"
#include "utils.h"

#ifdef GetProp
#undef GetProp
#endif

enum Hacks_HookType
{
	HACKS_HTYPE_SPAWN=0,
	HACKS_HTYPE_TRACEATTACK,
	HACKS_HTYPE_ONTAKEDAMAGE,
	HACKS_HTYPE_EVENT_KILLED,
	HACKS_HTYPE_STARTTOUCH,
	HACKS_HTYPE_TOUCH,
	HACKS_HTYPE_ENDTOUCH,
	HACKS_HTYPE_UPDATEONREMOVE,
	HACKS_HTYPE_WEAPON_CANUSE,
	HACKS_HTYPE_WEAPON_DROP,
	HACKS_HTYPE_WEAPON_CANSWITCHTO,
	HACKS_HTYPE_COMMITSUICIDE,
	HACKS_HTYPE_IMPULSECOMMANDS,
	HACKS_HTYPE_PLAYERRUNCOMMAND
};

enum Hacks_CallType
{
	HACKS_CTYPE_ENTITY=0,
	HACKS_CTYPE_COLLISIONPROP,
	HACKS_CTYPE_PHYSICSOBJECT,
	HACKS_CTYPE_EVENTQUEUE,
	HACKS_CTYPE_GAMERULES
};

enum Hacks_ReturnType
{
	HACKS_RTYPE_VOID=0,
	HACKS_RTYPE_INT,
	HACKS_RTYPE_FLOAT,
	HACKS_RTYPE_EDICT,
	HACKS_RTYPE_ENTITY
};

enum Hacks_Param
{
	HACKS_PARAM_NULL=0,
	HACKS_PARAM_INT,
	HACKS_PARAM_FLOAT,
	HACKS_PARAM_STRING,
	HACKS_PARAM_VECTOR,
	HACKS_PARAM_QANGLE,
	HACKS_PARAM_EDICT,
	HACKS_PARAM_ENTITY,
	HACKS_PARAM_PHYSICSOBJECT
};

struct hook_t
{
	int iID;
	int iType;
	int iEntity;
	CBaseEntity *pBase;
	IPluginFunction *pFunc;
	bool bPost;
};

struct patch_t
{
	unsigned char *pAddr;
	int iOffset;
	unsigned char szOld[MAX_STR_LENGTH];
	unsigned char szNew[MAX_STR_LENGTH];
	int iLength;
};

class CHacks : public SDKExtension
{
// Extension
public:
	virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
	virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late);

	bool m_bLog;
	int m_iOffsetDataMap;
	char m_szGameRules[MAX_STR_LENGTH];
	char m_szEventQueue[MAX_STR_LENGTH];

// Hooks
public:
	bool	 Handler(int iType, CBaseEntity *pBase, bool bPost, int *pResult, int iArg1, int iArg2, int iArg3, int iArg4, int iArg5);
	void	 Spawn(void);
	void	 Spawn_Post(void);
	void	 TraceAttack(const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr);
	void	 TraceAttack_Post(const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr);
	int		 OnTakeDamage(const CTakeDamageInfo &info);
	int		 OnTakeDamage_Post(const CTakeDamageInfo &info);
	void	 Event_Killed(const CTakeDamageInfo &info);
	void	 Event_Killed_Post(const CTakeDamageInfo &info);
	void	 StartTouch(CBaseEntity *pOther);
	void	 StartTouch_Post(CBaseEntity *pOther);
	void	 Touch(CBaseEntity *pOther);
	void	 Touch_Post(CBaseEntity *pOther);
	void	 EndTouch(CBaseEntity *pOther);
	void	 EndTouch_Post(CBaseEntity *pOther);
	void	 UpdateOnRemove(void);
	void	 UpdateOnRemove_Post(void);
	bool	 Weapon_CanUse(CBaseCombatWeapon *pWeapon);
	bool	 Weapon_CanUse_Post(CBaseCombatWeapon *pWeapon);
	void	 Weapon_Drop(CBaseCombatWeapon *pWeapon, const Vector *pvecTarget, const Vector *pVelocity);
	void	 Weapon_Drop_Post(CBaseCombatWeapon *pWeapon, const Vector *pvecTarget, const Vector *pVelocity);
	bool	 Weapon_CanSwitchTo(CBaseCombatWeapon *pWeapon);
	bool	 Weapon_CanSwitchTo_Post(CBaseCombatWeapon *pWeapon);
	void	 CommitSuicide(void);
	void	 CommitSuicide_Post(void);
	void	 ImpulseCommands(void);
	void	 ImpulseCommands_Post(void);
	void	 PlayerRunCommand(CUserCmd *ucmd, IMoveHelper *moveHelper);
	void	 PlayerRunCommand_Post(CUserCmd *ucmd, IMoveHelper *moveHelper);

	uint32 m_iCurHookID;
	CUtlVector<hook_t> m_Hooks;

// Patches
public:
	uint32 m_iCurPatchID;
	CUtlVector<patch_t> m_Patches;

// SigSym
public:
	void SigSymInit(void);
#ifdef WIN32
	void *SigSymFind(const char *pName, const unsigned char *pSig, int iLength);
#else
	void *SigSymFind(const char *pName, const char *pSym);
#endif
	char m_szBin[MAX_STR_LENGTH];
	CUtlVector<void *> m_Addrs;
#ifdef WIN32
	unsigned char *m_pBase;
	size_t m_iLength;
#endif
};

extern IServerGameDLL *serverdll;
extern INetworkStringTableContainer *networkstringtable;
extern CEventQueue *g_pEventQueue;
extern CGameRules *g_pGameRules;
extern CHacks g_Hacks;
extern const sp_nativeinfo_t hacks_natives[];

#endif
