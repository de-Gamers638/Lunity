#ifndef GUARD_Player
#define GUARD_Player
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "Mob.h"
struct Player : public Mob {
	/* Fields */
	char padding_4840[3004];
	class GameMode* gameMode;
	/* Virtuals */
	/* Functions */
};
#endif