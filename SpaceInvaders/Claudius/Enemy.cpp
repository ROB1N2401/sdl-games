#include "Enemy.h"

void Enemy::Initialize(Image& spritesheetImage_in, EnemyType enemyType_in, float x_in, float y_in)
{
	selfDestructProtocol.timeToDestroy = 0.5;
	transform.SetPosition(x_in, y_in);
	sprite.SetImage(spritesheetImage_in);
	enemyType = enemyType_in;
	switch (enemyType)
	{
	case EnemyType::Squid:
	{
		points = 30;
		collider.SetSize(16, 16);
		sprite.SetSource(32, 0, 32, 32);
		spritePos_x = 32;
	}
	break;

	case EnemyType::Crab:
	{
		points = 20;
		collider.SetSize(22, 16);
		sprite.SetSource(0, 0, 32, 32);
		spritePos_x = 0;
	}
	break;

	case EnemyType::Octopus:
	{
		points = 10;
		collider.SetSize(24, 16);
		sprite.SetSource(64, 0, 32, 32);
		spritePos_x = 64;
	}
	break;

	default: break;
	}
}

void Enemy::Update(float dt)
{
	if (selfDestructProtocol.isToDestroy)
	{
		isAllowedToShoot = false;
		sprite.SetSource(96, 96, 0, 0);
	}
	else if (selfDestructProtocol.countdownStarted)
	{
		selfDestructProtocol.timeElapsed += dt;
		int explosionPos_y = spritePos_y + spriteOffset * 2;
		sprite.SetSource(spritePos_x, explosionPos_y, 32, 32);
		if (selfDestructProtocol.timeElapsed >= selfDestructProtocol.timeToDestroy)
		{
			selfDestructProtocol.Destroy();
		}
	}
	else
	{
		switch (enemyType)
		{
		case EnemyType::Squid:
		{
			collider.SetPosition(static_cast<int>(transform.GetPosition().x + 8.f), static_cast<int>(transform.GetPosition().y + 8.f));
		}
		break;

		case EnemyType::Crab:
		{
			collider.SetPosition(static_cast<int>(transform.GetPosition().x + 6.f), static_cast<int>(transform.GetPosition().y + 8.f));
		}
		break;

		case EnemyType::Octopus:
		{
			collider.SetPosition(static_cast<int>(transform.GetPosition().x + 4.f), static_cast<int>(transform.GetPosition().y + 8.f));
		}
		break;

		default: break;
		}
		sprite.SetSource(spritePos_x, spritePos_y, 32, 32);
	}
}

void Enemy::Shoot(Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in)
{
	projectilesManager_in.Spawn(spritesheetImage_in, ProjectileType::Enemy, transform.GetPosition().x, transform.GetPosition().y + 12);
}

void Enemy::MakeAStep(Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in, bool down)
{
	if (!down)
	{
		transform.ChangePosition(delta_x * direction, 0);
	}
	else
	{
		direction *= (-1);
		transform.ChangePosition(delta_x * direction, delta_y);
	}
	
	int x = rand() % 100;
	if (x < chanceToShoot && isAllowedToShoot)
	{
		Shoot(spritesheetImage_in, projectilesManager_in);
	}


	if (spritePos_y == 0)
	{
		spritePos_y += spriteOffset;
	}
	else
	{
		spritePos_y -= spriteOffset;
	}
}

/*
		//animation
		sprite.SetSource(spritePos_x, spritePos_y, 32, 32);
		if (spritePos_y == 0)
		{
			spritePos_y += spriteOffset;
		}
		else
		{
			spritePos_y -= spriteOffset;
		}
*/