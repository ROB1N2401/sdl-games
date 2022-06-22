#include "ProjectilesManager.h"

ProjectilesManager::ProjectilesManager()
{
}

void ProjectilesManager::Spawn(Image& spritesheetImage_in, ProjectileType projectileType_in, float x_in, float y_in)
{
	Projectile projectile;
	projectile.Initialize(spritesheetImage_in, projectileType_in, x_in, y_in);
	projectiles.push_back(projectile);
}

void ProjectilesManager::Render(RenderManager& renderManager)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Render(renderManager);
	}
}

void ProjectilesManager::Update(float dt)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Update(dt);
		if (projectiles[i].selfDestructProtocol.isToDestroy)
		{
			projectiles.erase(projectiles.begin()+i);
		}
	}
}
