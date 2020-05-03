### Changelog
Note: Changelog contains list of changes from the original archive of the mod.
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

4. Reserved
