#include  "NormalTickHook.h"

#include "../../Events/PlayerTickEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall NormalTickHook::NormalTickHookCallback_1_17_11_1(Player* player) {
	PlayerTickEvent event(player->gameMode, player, player == Utils::GetClientInstance()->clientPlayer);
	auto listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onPlayerTickEvent(event);
	}
	PLH::FnCast(funcOriginal, &NormalTickHookCallback_1_17_11_1)(player);
}

NormalTickHook::NormalTickHook() : IPatch::IPatch("Player::NormalTick") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 48 8B ?? BE"), 0));
}

auto NormalTickHook::Apply() -> bool {
	return this->AutoPatch(&NormalTickHookCallback_1_17_11_1, &funcOriginal);
}