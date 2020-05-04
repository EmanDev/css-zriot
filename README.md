# Counter-Strike: Source Zombie Riot Mod
A pre-configured Zombie Riot Mod for Counter-Strike: Source.

This work contains source files that needs to compiled and has a pre-configured extract-to-install archive of Zombie Riot Mod for Counter-Strike Source.

## Configuration Changes (Notable Changes)

Note: Check for the commits if you want to track changes between files. Check out [Changelog](changelog.md) for all changes.

1. Replace SDKCall with 

   >src\zriot\offsets.inc

   > Offsets.inc
   >
   > Remove: Lines 190-193

   ```php
   if (tHUD == INVALID_HANDLE)
           return;
       
       SDKCall(hTerminateRound, delay, reason);
   ```

   > Added as Line 194

   ```php
   CS_TerminateRound(delay, CSRoundEndReason:reason, false);
   ```

2. Updated Hellknight skin because of errors

3. Configured maps for Zombie Riot Mod

   > css-zriot\css-zombieriot\cfg\sourcemod\zombieriot\zombieriot.cfg

   ````c++
   // Darkens the map (0: Disable)
   zriot_dark "1"
   
   // The darkness of the map,  a being the darkest,  z being extremely bright when zriot_dark is 1 (n: Default)
   zriot_dark_level "a"
   
   // The sky the map will have when zriot_dark is 1
   zriot_dark_sky "sky_borealis01"
   ````

4. More...

## Releases

Latest **Releases** can be found in the link below. 

Search Queries: 

+ (Pre-Configured) Counter-Strike Source Zombie Riot v1.9.1b
+ (Pre-Configured with Snapshots) Counter-Strike Source Zombie Riot v1.9.1b

> https://emandev.github.io/downloads.html

## Requirements

I recommend the following to be able to use CSS:ZRiot Mod on your server.

1. Counter-Strike: Source Dedicated Server
2. SourceMod (Latest)
3. MetaMod Source (Latest)
4. Hacks Extension

## Installation

Extract the latest archive from the releases to your cstrike directory of your Counter-Strike: Source Dedicated Server. Always use the recommended requirements, otherwise use the css-zriot-with-snapshots version if you faced errors.

Installation Video: [How to install Zombie Riot Mod on your Counter-Strike: Source Dedicated Server](https://www.youtube.com/watch?v=4M97oxkSdJk)

## Uninstallation

If you want to remove the mod, there are two methods.

1. Automatic (Recommended)

   Use my [Counter-Strike: Source Zombie Riot Mod Uninstaller v2.0](https://github.com/EmanDev/CSS-Zriot-Mod-Uninstaller-v2) to automatically removed the mods. Then verify server files.

2. Manual (If the Automatic Method doesn't work properly)

   Delete the following folders in your Counter-Strike: Source Dedicated Server

   > Counter-Strike Source Dedicated Server\cstrike\\**addons**
   >
   > Counter-Strike Source Dedicated Server\cstrike\cfg\\**sourcemod**
   >
   > Counter-Strike Source Dedicated Server\cstrike\\**materials**
   >
   > Counter-Strike Source Dedicated Server\cstrike\\**models**
   >
   > Counter-Strike Source Dedicated Server\cstrike\\**sound**

   Then verify server files by opening SteamCMD with these parameters.

   ```bash
   steamcmd.exe +login anonymous +app_update 232330 validate +quit
   ```

## Snapshots

This section only notes snapshots of working SourceMod and MetaMod Source with ZRiot Mod. Only use these builds if the latest SourceMod and MetaMod Source doesn't work with the plugin anymore.

1. SourceMod: sourcemod-1.8.0-git5967
2. MetaMod Source: mmsource-1.10.6-git946
