/*
Student's name: Fomenko Ivan
Student's mail: Ivan.Fomenko.1327@student.uu.se
Date of hand-in: 26.02.2021
*/

#include "Game.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"

Game::Game(ResourceManager& resourceManager) : m_resourceManager(resourceManager)
{
	resourceManager.LoadImageFromFile(backgroundImage, "../Assets/Background.png");
	resourceManager.LoadImageFromFile(spritesheetImage, "../Assets/Spritesheet.png");
	background.Initialize(backgroundImage);
	water.Initialize(backgroundImage);
	river.Initialize(spritesheetImage);
	frog.Initialize(spritesheetImage);
	traffic.Initialize(spritesheetImage);
	goalsManager.Initialize(spritesheetImage);
	livesManager.Initialize(spritesheetImage);
}

Game::~Game()
{                                                                            
}

bool Game::Enter(int& width, int& height, std::string& title)
{
	width = 400;
	height = 380;
	title = "Frogger";
	return true;
}


bool Game::Update(float dt)
{	
	river.Update(dt);
	traffic.Update(dt);
	frog.Update(dt);

	CheckLogCollision();
	CheckWaterCollision();
	CheckGoalCollision();
	CheckTrafficCollision();
	CheckOnLives();
	

	/*if frog is colliding with log, move frog with log speed/direction*/
	return isRunning;
}

void Game::Render(RenderManager& renderManager)
{
	water.Render(renderManager);
	background.Render(renderManager);
	river.Render(renderManager);
	traffic.Render(renderManager);
	frog.Render(renderManager);
	goalsManager.Render(renderManager);
	livesManager.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key)
{

}

void Game::OnKeyUp(KeyCode key)
{
	CheckOnQuit(key);
	frog.OnKeyUp(key);
}

#pragma region Collision Handling

void Game::CheckTrafficCollision()
{
	for (int i = 0; i < traffic.totalAmount; i++)
	{
		if (CollisionManager::CheckCollision(frog.collider, traffic.cars[i].collider))
		{
			livesManager.DeleteLife(true, frog);
		}
	}
}

void Game::CheckGoalCollision()
{
	for (int i = 0; i < goalsManager.goalsAmount; i++)
	{
		if (CollisionManager::CheckCollision(frog.collider, goalsManager.goals[i].collider))
		{
			goalsManager.goals[i].ChangeState();
			livesManager.DeleteLife(false, frog);
			break;
		}
	}
}

void Game::CheckLogCollision()
{
	for (int i = 0; i < river.rowTotalQ; i++)
	{
		if (CollisionManager::CheckCollision(frog.collider, river.rowTotal[i].collider))
		{
			frog.transform.ChangePosition(river.rowTotal[i].speed, 0.f);
			break;
		}
	}
}

void Game::CheckWaterCollision()
{
	if (CollisionManager::CheckCollision(frog.collider, water.collider))
	{
		bool isInDanger = true;

		for (int i = 0; i < river.rowTotalQ; i++)
		{
			if (CollisionManager::CheckCollision(frog.collider, river.rowTotal[i].collider))
			{
				isInDanger = false;
				break;
			}
		}
		for (int i = 0; i < goalsManager.goalsAmount; i++)
		{
			if (CollisionManager::CheckCollision(frog.collider, goalsManager.goals[i].collider))
			{
				isInDanger = false;
				break;
			}
		}

		if (isInDanger)
		{
			livesManager.DeleteLife(true, frog);
		}
	}
}

bool Game::CheckBounds()
{
	if (frog.transform.GetPosition().x <= -20 || frog.transform.GetPosition().x >= 400 || frog.transform.GetPosition().y >= 360)
		return true;
	else return false;
}

#pragma endregion

#pragma region Other

void Game::CheckOnQuit(KeyCode key)
{
	if (key == KeyCode::ESCAPE)
		isRunning = false;
}

void Game::CheckOnLives()
{
	if (livesManager.livesLeft < 0)
		isRunning = false;
}

#pragma endregion
