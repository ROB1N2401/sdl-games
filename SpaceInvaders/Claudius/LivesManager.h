#pragma once
#include "RenderManager.h"
#include "Entity.h"

struct LivesManager
{
	LivesManager();

	static const unsigned int livesAmount = 3;
	int livesLeft = livesAmount - 1; //Since this value is used as index, the count starts from 0. 

	Entity lives[livesAmount - 1]; //There is always 1 life icon less than there is actually left

	void DeleteLife();
	void Initialize(Image& spritesheetImage_in);
	void InitializeEntity(Image& spritesheetImage_in, Entity& entity_in, float x_in);
	void Render(RenderManager& renderManager);
};
