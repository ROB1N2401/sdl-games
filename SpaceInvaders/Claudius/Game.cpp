#include "Game.h"
#include <assert.h>
#include "ResourceManager.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"

Game::Game(ResourceManager& resourceManager, SoundManager& soundManager) : resourceManager(resourceManager), soundManager(soundManager)
{
	if (!resourceManager.LoadImageFromFile(spritesheetImage, "../Assets/Spritesheet.png"))
		return;
	if (!resourceManager.LoadSoundFromFile(notes[0], "../Assets/note1.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(notes[1], "../Assets/note2.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(notes[2], "../Assets/note3.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(notes[3], "../Assets/note4.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(invaderKilled, "../Assets/invaderkilled.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(playerKilled, "../Assets/playerkilled.wav"))
		return;
	if (!resourceManager.LoadSoundFromFile(shoot, "../Assets/shoot.wav"))
		return;
	if (!resourceManager.LoadFontFromFile(font, "../Assets/test.ttf", 16))
		return;

	soundManager.SetSoundVolume(notes[0], 30);
	soundManager.SetSoundVolume(notes[1], 30);
	soundManager.SetSoundVolume(notes[2], 30);
	soundManager.SetSoundVolume(notes[3], 30);
	soundManager.SetSoundVolume(invaderKilled, 30);
	soundManager.SetSoundVolume(playerKilled, 30);
	soundManager.SetSoundVolume(shoot, 30);

	InitializeSideBounds();
	hud.Initialize(spritesheetImage, font);
	player.Initialize(spritesheetImage);
	enemiesManager.Initialize(spritesheetImage, notes[0], notes[1], notes[2], notes[3]);
	for (int i = 0; i < shieldsAmount; i++)
	{
		float x = 48 + 92 * static_cast<float>(i); float y = 384;
		shields[i].Initialize(spritesheetImage, x, y);
	}
}

Game::~Game()
{                                                                            
}

bool Game::Enter(int& width, int& height, std::string& title)
{
	width = 448;
	height = 512;
	title = "Space Invaders";
	return true;
}


bool Game::Update(float dt)
{	
	if (enemiesManager.enemiesLeft >= 0 && player.isControllable)
	{
		CheckOnLivesLeft();
		CheckOnEnemiesLeft();

		enemiesManager.Update(dt, spritesheetImage, projectilesManager, soundManager);
		player.Update(dt);
		projectilesManager.Update(dt);
		for (int i = 0; i < shieldsAmount; i++)
		{
			shields[i].Update(dt);
		}

		CheckBoundsCollision();
		CheckEnemiesCollision();
		CheckPlayerCollision();
		CheckShieldCollision();
	}

	return isRunning;
}

void Game::Render(RenderManager& renderManager)
{
	hud.Render(renderManager);
	player.Render(renderManager);
	enemiesManager.Render(renderManager);
	projectilesManager.Render(renderManager);
	for (int i = 0; i < shieldsAmount; i++)
	{
		shields[i].Render(renderManager);
	}
	for (int i = 0; i < 2; i++)
	{
		sideBounds[i].Render(renderManager);
	}
}

void Game::OnKeyDown(KeyCode key)
{
	CheckOnQuit(key);
	player.OnKeyDown(key);
}

void Game::OnKeyUp(KeyCode key)
{
	player.OnKeyUp(key, spritesheetImage, shoot, soundManager, projectilesManager);
}

#pragma region Collision Handling

void Game::CheckBoundsCollision()
{
	for (int i = 0; i < projectilesManager.projectiles.size(); i++)
	{
		if (projectilesManager.projectiles[i].transform.GetPosition().y <= 0 || projectilesManager.projectiles[i].transform.GetPosition().y >= 463)
		{
			projectilesManager.projectiles[i].selfDestructProtocol.StartCountdown(projectilesManager.projectiles[i].collider);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < enemiesManager.enemiesInTotal; j++)
		{
			if (CollisionManager::CheckCollision(enemiesManager.allEnemies[j].collider, sideBounds[i].collider))
			{
				enemiesManager.shouldMoveDown = true;
				break;
			}
		}
	}
}

void Game::CheckEnemiesCollision()
{
	for (int i = 0; i < projectilesManager.projectiles.size(); i++)
	{
		for (int j = 0; j < enemiesManager.enemiesInTotal; j++)
		{
			if (CollisionManager::CheckCollision(enemiesManager.allEnemies[j].collider, projectilesManager.projectiles[i].collider))
			{
				hud.UpdateScore(enemiesManager.allEnemies[j].points);
				soundManager.PlaySound(invaderKilled, 0);
				enemiesManager.enemiesLeft--;
				if (enemiesManager.enemiesLeft <= 0)
				{
					hud.InstantiateVictory();
				}
				projectilesManager.projectiles[i].selfDestructProtocol.StartCountdown(projectilesManager.projectiles[i].collider);
				enemiesManager.allEnemies[j].selfDestructProtocol.StartCountdown(enemiesManager.allEnemies[j].collider);
			}
		}
	}
}

void Game::CheckPlayerCollision()
{
	for (int i = 0; i < projectilesManager.projectiles.size(); i++)
	{
		if (CollisionManager::CheckCollision(player.collider, projectilesManager.projectiles[i].collider))
		{
			soundManager.PlaySound(playerKilled, 0);
			hud.LoseLife();
			projectilesManager.projectiles[i].selfDestructProtocol.StartCountdown(projectilesManager.projectiles[i].collider);
			player.selfDestructProtocol.StartCountdown(player.collider);
		}
	}

	for (int i = 0; i < enemiesManager.enemiesInTotal; i++)
	{
		if (CollisionManager::CheckCollision(enemiesManager.allEnemies[i].collider, player.collider))
		{
			soundManager.PlaySound(playerKilled, 0);
			player.selfDestructProtocol.StartCountdown(player.collider);
			hud.InstantiateLoss();
			hud.livesLeft = 0;
		}
	}
}

void Game::CheckShieldCollision()
{
	for (int i = 0; i < projectilesManager.projectiles.size(); i++)
	{
		for (int j = 0; j < shieldsAmount; j++)
		{
			if (CollisionManager::CheckCollision(projectilesManager.projectiles[i].collider, shields[j].collider))
			{
				projectilesManager.projectiles[i].selfDestructProtocol.StartCountdown(projectilesManager.projectiles[i].collider);
			}
		}
	}

	for (int i = 0; i < enemiesManager.enemiesInTotal; i++)
	{
		for (int j = 0; j < shieldsAmount; j++)
		{
			if (CollisionManager::CheckCollision(enemiesManager.allEnemies[i].collider, shields[j].collider))
			{
				shields[j].Destroy();
			}
		}
	}
}

#pragma endregion

#pragma region Other

void Game::CheckOnQuit(KeyCode key)
{
	if (key == KeyCode::ESCAPE)
		isRunning = false;
}

void Game::InitializeSideBounds()
{
	float x = 0;
	for (int i = 0; i < 2; i++)
	{
		sideBounds[i].sprite.SetImage(spritesheetImage);
		sideBounds[i].transform.SetPosition(x, 0.f);
		sideBounds[i].collider.SetPosition(static_cast<int>(sideBounds[i].transform.GetPosition().x), static_cast<int>(sideBounds[i].transform.GetPosition().y));
		sideBounds[i].collider.SetSize(25, 512);
		x += 423;
	}
}

void Game::CheckOnLivesLeft()
{
	if (hud.livesLeft <= 0)
		player.isControllable = false;
}

void Game::CheckOnEnemiesLeft()
{
	if (enemiesManager.enemiesLeft <= 0)
	{
		player.isControllable = false;
	}
}
#pragma endregion