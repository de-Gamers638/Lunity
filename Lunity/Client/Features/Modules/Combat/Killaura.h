#ifndef LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA
#define LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA

#include "../../Module.h"
#include "../../../Events/Listener.h"
#include "../../../Events/EventHandler.h"

class Killaura : public Module {
public:
	Killaura();
	void OnEnable() override;
	void OnDisable() override;

	void onActorRotateEvent(ActorRotateEvent& event) override;
	void onRenderEvent(RenderEvent& event) override;
        void onPlayerTickEvent(PlayerTickEvent& event) override;
};



#endif /* LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA */
