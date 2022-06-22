#pragma once
#include "Entity.h"
#include "Keycode.h"
#include "SoundManager.h"
#include "ProjectilesManager.h"

//A struct for player which also contains logic for handling player's input

struct Player : Entity
{
	Player();
	~Player();

	static const int speed = 200;
	static const int spriteOffset = 32;
	static const int shotCooldown = 1;
	float timer = shotCooldown;
	int delta_x = 0;
	int spritePos_y = 0;
	bool isMoving = false;
	bool isControllable = true;
	SelfDestructProtocol selfDestructProtocol;
	

	virtual void Initialize(Image& spritesheetImage_in) final;
	virtual void Update(float dt) final;

	void Shoot(Image& spritesheetImage_in, Sound& sound_in, ProjectilesManager& projectilesManager_in, SoundManager& soundManager_in);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key, Image& spritesheetImage_in, Sound& sound_in, SoundManager& soundManager_in, ProjectilesManager& projectilesManager_in);
};
