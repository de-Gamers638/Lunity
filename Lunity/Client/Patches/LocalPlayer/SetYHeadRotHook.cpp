#include  "SetYHeadRotHook.h"

#include "../../Events/LocalPlayer/HeadRotYEvent.h"

void __fastcall SetYHeadRotHook::SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, Actor* camera) {
	PLH::FnCast(funcOriginal, &SetYHeadRotHookCallback_1_17_10_4)(localPlayer, camera);
	HeadRotYEvent event(localPlayer, camera);
	EventRegistry::GetInstance()->DispatchEvent(&event);
	// ClientInstance* client = Utils::GetClientInstance();
	// LocalPlayer* lPlayer = client->ClientPlayer();
	// if(lPlayer) {
	// 	float rot = lPlayer->YHeadRot();
	// 	lPlayer->YHeadRot(0);
	// }
}

SetYHeadRotHook::SetYHeadRotHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? ?? BA"), -1));
}

auto SetYHeadRotHook::Apply() -> bool {
	return this->AutoPatch(&SetYHeadRotHookCallback_1_17_10_4, &funcOriginal);
}