#include "Projectile.h"

void Projectile::Initialize(Image& spritesheetImage_in, ProjectileType projectileType_in, float x_in, float y_in)
{
	selfDestructProtocol.timeToDestroy = 0.5;
	transform.SetPosition(x_in, y_in + 2.f);
	sprite.SetImage(spritesheetImage_in);
	collider.SetSize(6, 14);
	projectileType = projectileType_in;
	switch (projectileType)
	{
	case ProjectileType::Player:
	{
		direction = -1;
		spritePos_x = 224;
	}
	break;

	case ProjectileType::Enemy:
		{
		direction = 1;
		spritePos_x = 256;
		}
		break;

	default: break;
	}
	sprite.SetSource(spritePos_x, spritePos_y, 32, 32);
}

void Projectile::Update(float dt)
{
	if (selfDestructProtocol.countdownStarted)
	{
		selfDestructProtocol.timeElapsed += dt;
		sprite.SetSource(224, 64, 32, 32);
		if (selfDestructProtocol.timeElapsed >= selfDestructProtocol.timeToDestroy)
		{
			selfDestructProtocol.Destroy();
		}
	}
	else
	{
		if (spritePos_y == 0)
		{
			spritePos_y += spriteOffset;
		}
		else
		{
			spritePos_y -= spriteOffset;
		}
		sprite.SetSource(spritePos_x, spritePos_y, 32, 32);
		transform.ChangePosition(0, speed * dt * direction);
		collider.SetPosition(static_cast<int>(transform.GetPosition().x + 13), static_cast<int>(transform.GetPosition().y + 9));
	}
}
