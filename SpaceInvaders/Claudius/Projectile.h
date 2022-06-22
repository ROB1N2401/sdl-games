#pragma once
#include "Entity.h"
#include "SelfDestructProtocol.h"

//A struct for in-game projectiles, both enemies' and player's

enum class ProjectileType
{
	Player,
	Enemy
};

struct Projectile : Entity
{
	SelfDestructProtocol selfDestructProtocol;
	ProjectileType projectileType;
	static const int speed = 200;
	static const int spriteOffset = 32;
	int spritePos_x = 0;
	int spritePos_y = 0;
	int direction = 1;

	virtual void Initialize(Image& spritesheetImage_in, ProjectileType projectileType_in, float x_in, float y_in) final;
	virtual void Update(float dt);
};

