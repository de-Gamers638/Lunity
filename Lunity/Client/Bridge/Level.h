#ifndef GUARD_Level
#define GUARD_Level
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct Level {
	/* Fields */
	char padding_112[112];
	std::vector<Player*> players;
	char padding_9952[9816];
	std::vector<Actor*> actors;
	/* Virtuals */
	/* Functions */
};
#endif