#pragma once
#include "RenderManager.h"
#include "Image.h"

//

struct ShieldsManager
{
	ShieldsManager();

	static const unsigned int shieldsAmount = 5;

	void Initialize(Image& spritesheetImage_in);
	void Render(RenderManager& renderManager);
};
