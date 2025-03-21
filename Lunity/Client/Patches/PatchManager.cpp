#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

//Actor
#include "Actor/SetRotHook.h"
//Player
#include "Player/NormalTickHook.h"
//Localplayer
#include "LocalPlayer/SetYHeadRotHook.h"
//ClientInstance
#include "ClientInstance/UpdateHook.h"
//Global or Unknown
#include "Global/KeyPressHook.h"
#include "Global/MouseActionHook.h"
//MeshHelpers
#include "MeshHelpers/RenderMeshHook.h"
//ScreenView
#include "ScreenView/SetupAndRenderHook.h"
//SurvivalMode
// #include "SurvivalMode/TickHook.h"

void PatchManager::ApplyAll()
{
	/* Input hooking */
	PatchManager::ApplyPatch(new KeyPressHook());
	PatchManager::ApplyPatch(new MouseActionHook());

	/* ClientInstance reference receiver hook */
	PatchManager::ApplyPatch(new UpdateHook());

	/* Graphics hooking */
	PatchManager::ApplyPatch(new SetupAndRenderHook());

	/* Both patches are needed for changing where LP is facing */
	PatchManager::ApplyPatch(new SetYHeadRotHook()); // This func has head & camera math
	PatchManager::ApplyPatch(new SetRotHook()); // This has for up & down rotation which is shared across the whole body, however only the head moves.

	/* Tick hook */
	//PatchManager::ApplyPatch(new TickHook());
	PatchManager::ApplyPatch(new NormalTickHook());
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
        PatchManager::patches->push_back(toAdd);
        Utils::DebugF("Successfully applied \'" + toAdd->GetName() + "\' patch!");
    }
    else
    {
        Utils::DebugF("Failed to apply patch: " + toAdd->GetName());
    }
}

auto PatchManager::RemoveAll() -> bool {
	for(auto patch : *PatchManager::patches) {
		PatchManager::RemovePatch(patch);
	}
	return true;
}
auto PatchManager::RemovePatch(class IPatch* toRemove) -> bool {
	delete toRemove;
	return true;
}