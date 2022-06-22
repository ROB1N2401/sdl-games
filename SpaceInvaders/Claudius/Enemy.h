#pragma once
#include "Entity.h"
#include "ProjectilesManager.h"
#include "SelfDestructProtocol.h"

//A struct containing all the data for enemy, describing varuious types of them as well as their behaviour

enum class EnemyType
{
	Squid,
	Crab,
	Octopus
};

struct Enemy : Entity
{
	static const int shotCooldown = 1;
	static const int spriteOffset = 32;
	bool isAllowedToShoot = false;
	float delta_x = 2;
	float delta_y = 34;
	int points = 0;
	int chanceToShoot = 10;
	int direction = 1;
	int spritePos_x = 0;
	int spritePos_y = 0;
	SelfDestructProtocol selfDestructProtocol;
	EnemyType enemyType = EnemyType::Squid;

	virtual void Initialize(Image& spritesheetImage_in, EnemyType enemyType_in, float x_in, float y_in) final;
	virtual void Update(float dt) final;

	void Shoot(Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in);
	void MakeAStep(Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in, bool down);
};
