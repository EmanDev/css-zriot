# Counter-Strike: Source Zombie Riot Mod
A pre-configured Zombie Riot Mod for Counter-Strike: Source.

This work contains source files that needs to compiled and has a pre-configured extract-to-install archive of Zombie Riot Mod for Counter-Strike Source.

## Configuration Changes

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

   ````c#
   // Darkens the map (0: Disable)
   zriot_dark "1"
   
   // The darkness of the map,  a being the darkest,  z being extremely bright when zriot_dark is 1 (n: Default)
   zriot_dark_level "a"
   
   // The sky the map will have when zriot_dark is 1
   zriot_dark_sky "sky_borealis01"
   ````

4. More...

## Releases

No **RELEASES** yet. Always check this section before downloading anything.

## Requirements

I recommend the following to be able to use CSS:ZRiot Mod on your server.

1. Counter-Strike: Source Dedicated Server
2. SourceMod (Latest)
3. MetaMod Source (Latest)
4. Hacks Extension

## Snapshots

This section only notes snapshots of working SourceMod and MetaMod Source with ZRiot Mod. Only use these builds if the latest SourceMod and MetaMod Source doesn't work with the plugin anymore.

1. SourceMod: sourcemod-1.8.0-git5967
2. MetaMod Source: mmsource-1.10.6-git946