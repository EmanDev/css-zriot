# Counter-Strike: Source Zombie Riot Mod
A pre-configured Zombie Riot Mod for Counter-Strike: Source.

This work contains source files that needs to compiled and has a pre-configured extract-to-install archive of Zombie Riot Mod for Counter-Strike Source.

## Configuration Changes

Note: Check for the commits if you want to track changes between files.

1. Replace SDKCall with 

   ```php
   CS_TerminateRound(delay, CSRoundEndReason:reason, false);
   ```

   in offsets.inc

2. Updated Hellknight skin because of errors

3. Added Zombie Maps

4. Reserved

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