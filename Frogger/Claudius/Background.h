#pragma once
#include "Entity.h"

//A collection of entities that are used to form a backround

struct Background
{
	Entity topBackground;
	Entity middleBackground;
	Entity bottomBackground;

	void Initialize(Image& backgroundImage);
	void Render(RenderManager& renderManager);
};

