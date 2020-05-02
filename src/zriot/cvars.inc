/**
 * ====================
 *     Zombie Riot
 *   File: cvars.inc
 *   Author: Greyscale
 * ====================
 */

enum ZRiotSettings
{
    Handle:CVAR_ENABLE,
    Handle:CVAR_NOBLOCK,
    Handle:CVAR_FREEZE,
    Handle:CVAR_BOTQUOTA_SILENT,
    Handle:CVAR_REGRESSION,
    Handle:CVAR_FIRST_RESPAWN,
    Handle:CVAR_RESPAWN,
    Handle:CVAR_ZOMBIETEAM,
    Handle:CVAR_ZOMBIEMAX,
    Handle:CVAR_HUD,
    Handle:CVAR_TARGETING,
    Handle:CVAR_ROUNDFADE,
    Handle:CVAR_RAGDOLL_REMOVE,
    Handle:CVAR_NAPALM,
    Handle:CVAR_NAPALM_TIME,
    Handle:CVAR_DARK,
    Handle:CVAR_DARK_LEVEL,
    Handle:CVAR_DARK_SKY,
    Handle:CVAR_CASHFILL,
    Handle:CVAR_CASHAMOUNT
}

new gCvars[ZRiotSettings];

CreateCvars()
{
    gCvars[CVAR_ENABLE]                =    CreateConVar("zriot_enable", "1", "Enable ZombieRiot gameplay (0: Disable)");
    gCvars[CVAR_REGRESSION]            =    CreateConVar("zriot_regression", "1", "If the zombies win the round, the game will regress one day (0: Disable)");
    gCvars[CVAR_NOBLOCK]               =    CreateConVar("zriot_noblock", "1", "Prevents zombies from getting stuck in each other (0: Disable)");
    gCvars[CVAR_FREEZE]                =    CreateConVar("zriot_freeze", "10", "Time, in seconds, to freeze zombies at round start to allow humans to get set up (0: Disable)");
    gCvars[CVAR_BOTQUOTA_SILENT]       =    CreateConVar("zriot_botquota_silent", "1", "Blocks join/leave text for bots (0: Disable)");
    gCvars[CVAR_FIRST_RESPAWN]         =    CreateConVar("zriot_first_respawn", "10", "Amount of time to wait before spawning a player into the game for the first time (0: Disable)");
    gCvars[CVAR_RESPAWN]               =    CreateConVar("zriot_respawn", "30", "Amount of time each human has to wait before they will respawn into the game (0: Disable)");
    gCvars[CVAR_ZOMBIETEAM]            =    CreateConVar("zriot_zombieteam", "t", "Which team zombie's will be on (t: Terrorist ct: Counter-Terrorist)");
    gCvars[CVAR_ZOMBIEMAX]             =    CreateConVar("zriot_zombiemax", "12", "The max amount of zombies spawned at one time");
    gCvars[CVAR_HUD]                   =    CreateConVar("zriot_hud", "1", "Enable persistent display of the HUD which displays day, zombies left, and humans left (0: Disable)");
    gCvars[CVAR_TARGETING]             =    CreateConVar("zriot_targeting", "1", "Enables a system that tracks damage done to each zombie, and shows you each one's current health (0: Disable)");
    gCvars[CVAR_ROUNDFADE]             =    CreateConVar("zriot_roundfade", "0", "Player's screens fade blue if humans win, red if zombies in, and black in any other case (0: Disable)");
    gCvars[CVAR_RAGDOLL_REMOVE]        =    CreateConVar("zriot_ragdoll_remove", "20", "The time, in seconds, before the ragdoll of dead zombies will be deleted (0: Disable)");
    gCvars[CVAR_NAPALM]                =    CreateConVar("zriot_napalm", "1", "Turns grenades into napalm grenades that light zombies on fire (0: Disable)");
    gCvars[CVAR_NAPALM_TIME]           =    CreateConVar("zriot_napalm_time", "20", "How long the zombie burns when zr_napalm is 1");
    gCvars[CVAR_DARK]                  =    CreateConVar("zriot_dark", "0", "Darkens the map (0: Disable)");
    gCvars[CVAR_DARK_LEVEL]            =    CreateConVar("zriot_dark_level", "a", "The darkness of the map,  a being the darkest,  z being extremely bright when zriot_dark is 1 (n: Default)");
    gCvars[CVAR_DARK_SKY]              =    CreateConVar("zriot_dark_sky", "sky_borealis01", "The sky the map will have when zriot_dark is 1");
    gCvars[CVAR_CASHFILL]              =    CreateConVar("zriot_cashfill", "1", "Enable the mod to set the players cash to zriot_cashamount (0: Disabled)");
    gCvars[CVAR_CASHAMOUNT]            =    CreateConVar("zriot_cashamount", "12000", "How much money players will have when they spawn when zriot_cashfill is 1");
    
    HookConVarChange(gCvars[CVAR_ENABLE], EnableHook);
    
    AutoExecConfig(true, "zombieriot", "sourcemod/zombieriot");
}

HookCvars()
{
    SetConVarBool(FindConVar("mp_autoteambalance"), false);
    SetConVarInt(FindConVar("mp_limitteams"), 0);
    
    HookConVarChange(FindConVar("mp_autoteambalance"), AutoTeamBalanceHook);
    HookConVarChange(FindConVar("mp_limitteams"), LimitTeamsHook);
    
    HookConVarChange(gCvars[CVAR_ZOMBIETEAM], ZombieTeamHook);
    
    HookConVarChange(FindConVar("mp_restartgame"), RestartGameHook);
}

UnhookCvars()
{
    UnhookConVarChange(FindConVar("mp_autoteambalance"), AutoTeamBalanceHook);
    UnhookConVarChange(FindConVar("mp_limitteams"), LimitTeamsHook);
    
    UnhookConVarChange(gCvars[CVAR_ZOMBIETEAM], ZombieTeamHook);
    
    UnhookConVarChange(FindConVar("mp_restartgame"), RestartGameHook);
}

public EnableHook(Handle:convar, const String:oldValue[], const String:newValue[])
{
    new bool:enable = bool:StringToInt(newValue);
    
    if (enable)
    {
        FindMapSky();
        
        HookEvents();
        HookCvars();
        
        ServerCommand("bot_kick");
        
        gDay = 0;
        
        TerminateRound(3.0, Game_Commencing);
    }
    else
    {
        ZRiotEnd();
    }
}

public AutoTeamBalanceHook(Handle:convar, const String:oldValue[], const String:newValue[])
{
    SetConVarBool(convar, false);
}

public LimitTeamsHook(Handle:convar, const String:oldValue[], const String:newValue[])
{
    SetConVarInt(convar, 0);
}

public ZombieTeamHook(Handle:convar, const String:oldValue[], const String:newValue[])
{
    if (StrEqual(newValue, "t", false) || StrEqual(newValue, "ct", false))
    {
        UpdateTeams();
    }
}

public RestartGameHook(Handle:convar, const String:oldValue[], const String:newValue[])
{
    gDay = 0;
    
    ResetZombies(true);
}