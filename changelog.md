### Changelog
Note: Changelog contains list of changes from the original archive of the mod.
1. Replace SDKCall with a new TerminateRound signature.

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

2. Updated Hellknight skin because of errors.

3. Configured maps for Zombie Riot Mod.

   > css-zriot\css-zombieriot\cfg\sourcemod\zombieriot\zombieriot.cfg

   ````c++
   // Darkens the map (0: Disable)
   zriot_dark "1"
   
   // The darkness of the map,  a being the darkest,  z being extremely bright when zriot_dark is 1 (n: Default)
   zriot_dark_level "a"
   
   // The sky the map will have when zriot_dark is 1
   zriot_dark_sky "sky_borealis01"
   ````

4. Integrated hacks-ext in sourcemod.

   > Added configs\hacks.ext.cfg
   >
   > Added extensions\hacks.ext.dll
   >
   > Added extensions\hacks.ext.so
   >
   > Added scripting\include\hacks.ini

5. Improved zombie count in days.txt

   > addons\sourcemod\configs\zriot\days.txt

   ```C++
   "days"
   {
   	"Outbreak"
   	{
   		"count"			"25"
   		"healthboost"		"0"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Uprising"
   	{
   		"count"			"35"
   		"healthboost"		"50"
   		"respawn"		"0"
   		"deaths_before_zombie"	"0"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Riot!"
   	{
   		"count"			"75"
   		"healthboost"		"75"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Rampage"
   	{
   		"count"			"150"
   		"healthboost"		"100"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Surge"
   	{
   		"count"			"225"
   		"healthboost"		"150"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Storm"
   	{
   		"count"			"275"
   		"healthboost"		"125"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"600.0"
   		"fademax"		"800.0"
   	}
   
   	"Containment"
   	{
   		"count"			"350"
   		"healthboost"		"150"
   		"respawn"		"1"
   		"deaths_before_zombie"	"2"
   		"fademin"		"300.0"
   		"fademax"		"500.0"
   	}
   
   	"Final Stand"
   	{
   		
   		"count"			"3"
   		"healthboost"		"300"
   		"respawn"		"0"
   		"deaths_before_zombie"	"0"
   		"fademin"		"400.0"
   		"fademax"		"600.0"
   		"zombieoverride"	"hellknight"
   	}
   }
   ```

6. Disabled weapon restrictions.
7. Increase max zombie spawned at one time to 15.
8. Increased maximum capacity of ammo to 1000.
9. Reserved...