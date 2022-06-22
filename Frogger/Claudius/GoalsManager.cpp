#include "GoalsManager.h"

GoalsManager::GoalsManager()
{
	
}

void GoalsManager::Initialize(Image& spritesheetImage_in)
{
	float x = 12;
	float y = 16;

	for (int i = 0; i < goalsAmount; i++)
	{
		goals[i].Initialize(spritesheetImage_in, x, y);
		x += 84;
	}
}

void GoalsManager::Render(RenderManager& renderManager)
{
	for (int i = 0; i < goalsAmount; i++)
	{
		goals[i].Render(renderManager);
	}
}
