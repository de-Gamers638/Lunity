#ifndef LUNITY_UTILS_MINECRAFTRENDERER
#define LUNITY_UTILS_MINECRAFTRENDERER

#include "Math.h"
#include "../Client/Bridge/MinecraftUIRenderContext.h"
#include <string>

//A MinecraftUIRenderContext wrapper
class MinecraftRenderer {
	MinecraftUIRenderContext* renderContext;
public:
	MinecraftRenderer(MinecraftUIRenderContext* renderContext);

	/* Text drawing wrappers */
	void DrawString(std::string text, Vector2<float> position);
	void DrawString(std::string text, Vector2<float> position, Color color);
	void DrawString(std::string text, Vector2<float> position, Color color, float scale);
};

#endif /* LUNITY_UTILS_MINECRAFTRENDERER */
