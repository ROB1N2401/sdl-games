#pragma once
#include "RenderManager.h"
#include "Image.h"
#include "Projectile.h"

//A struct which collects all of the projectiles currently presented and rendered in the game. Also controls them

struct ProjectilesManager
{
	ProjectilesManager();

	//std::vector<Projectile> playerProjectiles;
	//std::vector<Projectile> enemyProjectiles;
	std::vector<Projectile> projectiles;

	void Spawn(Image& spritesheetImage_in, ProjectileType projectileType_in, float x_in, float y_in);
	void Render(RenderManager& renderManager);
	void Update(float dt);
};
