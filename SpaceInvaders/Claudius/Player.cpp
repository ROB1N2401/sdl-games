#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize(Image& spritesheetImage_in)
{
	selfDestructProtocol.timeToDestroy = 2;
	transform.SetPosition(0, 440);
	collider.SetSize(26, 16);
	sprite.SetImage(spritesheetImage_in);
	sprite.SetSource(128, 0, 32, 32);
}

void Player::Update(float dt)
{
	if (selfDestructProtocol.countdownStarted)
	{
		collider.isActive = false;
		selfDestructProtocol.timeElapsed += dt;
		int explosionPos_y = spritePos_y + spriteOffset;
		sprite.SetSource(128, explosionPos_y, 32, 32);
		if (selfDestructProtocol.timeElapsed >= selfDestructProtocol.timeToDestroy)
		{
			if (isControllable)
			{
				selfDestructProtocol.timeElapsed = 0;
				selfDestructProtocol.countdownStarted = false;
				collider.isActive = true;
				sprite.SetSource(128, 0, 32, 32);
			}
		}
	}
	else
	{
		timer += dt;
		sprite.SetSource(128, 0, 32, 32);
		collider.SetPosition(static_cast<int>(transform.GetPosition().x + 4), static_cast<int>(transform.GetPosition().y + 6));
		if (isMoving)
		{
			if (0 <= transform.GetPosition().x && transform.GetPosition().x <= 420)
			{
				transform.ChangePosition(delta_x * dt, 0);
			}
			else if (transform.GetPosition().x < 0)
			{
				transform.SetPosition(0, 440);
			}
			else if (transform.GetPosition().x > 420)
			{
				transform.SetPosition(420, 440);
			}
		}
	}
}

void Player::Shoot(Image& spritesheetImage_in, Sound& sound_in, ProjectilesManager& projectilesManager_in, SoundManager& soundManager_in)
{
	soundManager_in.PlaySound(sound_in, 0);
	projectilesManager_in.Spawn(spritesheetImage_in, ProjectileType::Player, transform.GetPosition().x, transform.GetPosition().y - 16);
}

void Player::OnKeyDown(KeyCode key)
{
	if (isControllable)
	{
		if (key == KeyCode::LEFT_ARROW)
		{
			isMoving = true;
			delta_x = -speed;
		}
		else if (key == KeyCode::RIGHT_ARROW)
		{
			isMoving = true;
			delta_x = speed;
		}
	}
}

void Player::OnKeyUp(KeyCode key, Image& spritesheetImage_in, Sound& sound_in, SoundManager& soundManager_in, ProjectilesManager& projectilesManager_in)
{
	if (isControllable)
	{
		if (timer > shotCooldown)
		{
			if (key == KeyCode::SPACE)
			{
				Shoot(spritesheetImage_in, sound_in, projectilesManager_in, soundManager_in);
				timer = 0;
			}
		}
		isMoving = false;
	}
}
