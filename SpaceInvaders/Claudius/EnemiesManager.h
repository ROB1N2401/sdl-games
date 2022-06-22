#pragma once
#include "SoundManager.h"
#include "Image.h"
#include "Enemy.h"
#include "Sound.h"

//A struct representing a collection of all enemies, as well as controlling them

struct EnemiesManager
{
	EnemiesManager();

	static const unsigned int enemiesInRow = 11;
	static const unsigned int rowsInTotal = 5;
	static const int enemiesInTotal = enemiesInRow * rowsInTotal;
	static const int delta_x = 4;
	static const int delta_y = 16;
	float stepTime = 1.5;
	float stepTimeDelta = stepTime / 5.f;
	float timeElapsed = 0;
	bool shouldMoveDown = false;
	int enemiesLeft = enemiesInTotal;
	int stage1 = 11;
	int stage2 = 22;
	int stage3 = 44;
	int currentNote = 0;

	Sound notes[4];
	Enemy squids[enemiesInRow];
	Enemy crabs1[enemiesInRow];
	Enemy crabs2[enemiesInRow];
	Enemy octopuses1[enemiesInRow];
	Enemy octopuses2[enemiesInRow];
	Enemy allEnemies[enemiesInRow * 5];

	void Initialize(Image& spritesheetImage_in, Sound& note1, Sound& note2, Sound& note3, Sound& note4);
	void Render(RenderManager& renderManager);
	void Update(float dt, Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in, SoundManager& soundManager_in);
};
