```
1.3.0.0 (07/01/07)
	- Removed Hacks_FindSendPropOffs (FindSendPropOffs already searches recursive)
	- Added 3 new natives (Hacks_CreatePatch, Hacks_Patch & Hacks_Unpatch)
	- Added the ability to call CEventQueue & CGameRules functions
1.2.0.0 (06/15/07)
	- Added 2 new functions that you can hook (ImpulseCommands & PlayerRunCommand)
	- Added 2 new natives (Hacks_AddDownload & Hacks_FindSendPropOffs)
- Added 1 new paramter (Hacks_CallType) to Hacks_Call_Offset (so plugins needs to be edit to use this version)
	- Added IPhysicsObject support to Hacks_CallType & Hacks_Param
	- Changed the args of TraceAttack
1.1.0.0 (06/14/07)
	- Added new natives to hook virtual functions
	- Changed some enums
1.0.0.0 (06/11/07)
- First release
```