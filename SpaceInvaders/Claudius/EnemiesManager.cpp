#include "EnemiesManager.h"

EnemiesManager::EnemiesManager()
{

}

void EnemiesManager::Initialize(Image& spritesheetImage_in, Sound& note1, Sound& note2, Sound& note3, Sound& note4)
{
	notes[0] = note1;
	notes[1] = note2;
	notes[2] = note3;
	notes[3] = note4;

	float x, y;
	x = 27;  y = 96;
	for (int i = 0; i < enemiesInRow; i++)
	{
		squids[i].Initialize(spritesheetImage_in, EnemyType::Squid, x, y);
		x += 34;
	}
	x = 27;  y = 128;
	for (int i = 0; i < enemiesInRow; i++)
	{
		crabs1[i].Initialize(spritesheetImage_in, EnemyType::Crab, x, y);
		x += 34;
	}
	x = 27;  y = 160;
	for (int i = 0; i < enemiesInRow; i++)
	{
		crabs2[i].Initialize(spritesheetImage_in, EnemyType::Crab, x, y);
		x += 34;
	}
	x = 27;  y = 192;
	for (int i = 0; i < enemiesInRow; i++)
	{
		octopuses1[i].Initialize(spritesheetImage_in, EnemyType::Octopus, x, y);
		x += 34;
	}
	x = 27;  y = 224;
	for (int i = 0; i < enemiesInRow; i++)
	{
		octopuses2[i].Initialize(spritesheetImage_in, EnemyType::Octopus, x, y);
		octopuses2[i].isAllowedToShoot = true;
		x += 34;
	}

	for (int i = 0; i < enemiesInTotal; i++)
	{
		for (int j = 0; j < enemiesInRow; j++)
		{
			allEnemies[j] = squids[j];
		}
		for (int j = 0; j < enemiesInRow; j++)
		{
			allEnemies[enemiesInRow + j] = crabs1[j];
		}
		for (int j = 0; j < enemiesInRow; j++)
		{
			allEnemies[enemiesInRow * 2 + j] = crabs2[j];
		}
		for (int j = 0; j < enemiesInRow; j++)
		{
			allEnemies[enemiesInRow * 3 + j] = octopuses1[j];
		}
		for (int j = 0; j < enemiesInRow; j++)
		{
			allEnemies[enemiesInRow * 4 + j] = octopuses2[j];
		}
	}
}

void EnemiesManager::Render(RenderManager& renderManager)
{
	for (int i = 0; i < enemiesInTotal; i++)
	{
		allEnemies[i].Render(renderManager);
	}
}

void EnemiesManager::Update(float dt, Image& spritesheetImage_in, ProjectilesManager& projectilesManager_in, SoundManager& soundManager_in)
{
	if (enemiesLeft < enemiesInTotal - stage1)
	{
		if (enemiesLeft < enemiesInTotal - stage2)
		{
			if (enemiesLeft < enemiesInTotal - stage3)
			{
				stepTime = stepTimeDelta;
			}
			else stepTime = stepTimeDelta * 3.f;
		}
		else stepTime = stepTimeDelta * 4.f;
	}

	timeElapsed += dt;
	for (int i = 0; i < enemiesInTotal - enemiesInRow; i++)
	{
		if (!allEnemies[i].selfDestructProtocol.isToDestroy && allEnemies[i + 11].selfDestructProtocol.isToDestroy)
			allEnemies[i].isAllowedToShoot = true;
	}

	if (timeElapsed > stepTime)
	{
		timeElapsed = 0;

		soundManager_in.PlaySound(notes[currentNote], 0);
		if (currentNote < 3)
			currentNote++;
		else currentNote = 0;

		for (int i = 0; i < enemiesInTotal; i++)
		{
			allEnemies[i].MakeAStep(spritesheetImage_in, projectilesManager_in, shouldMoveDown);
		}
		if (shouldMoveDown)
			shouldMoveDown = false;
	}

	for (int i = 0; i < enemiesInTotal; i++)
	{
		allEnemies[i].Update(dt);
	}
}
