#pragma once
#include "Entity.h"
#include "Frog.h"

//A combination of struct that handles the logic of reacting on player's death/success as well as HUD elements

struct LivesManager
{
	LivesManager();

	static const unsigned int livesAmount = 5;
	int livesLeft = 4; //Since this value is used as index, the count starts from 0

	Entity lives[livesAmount];

	void DeleteLife(bool died, Frog& frog_in);
	void Initialize(Image& spritesheetImage_in);
	void InitializeEntity(Image& spritesheetImage_in, Entity& entity_in, float x_in);
	void Render(RenderManager& renderManager);
};
