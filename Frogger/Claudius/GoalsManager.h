#pragma once
#include "Goal.h"

//A collection of goal entities that handles them as well

struct GoalsManager
{
	GoalsManager();

	static const unsigned int goalsAmount = 5;

	Goal goals[goalsAmount];

	void Initialize(Image& spritesheetImage_in);
	void Render(RenderManager& renderManager);
};
