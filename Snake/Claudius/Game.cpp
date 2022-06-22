#include "Game.h"

Game::Game(ResourceManager& resourceManager) : m_resourceManager(resourceManager)
{
	head.Initialize(140, 140);
	apple.Initialize();
}

Game::~Game()
{
}

bool Game::Enter(int& width, int& height, std::string& title)
{
	width = 1280;
	height = 720;
	title = "Test";
	return true;
}

bool Game::Update(double dt)
{
	timer += dt;

	if (head.transform.GetX() == apple.transform.GetX() && head.transform.GetY() == apple.transform.GetY())
	{
		apple.UpdatePosition();
		tracker++;
		Body body_part;
		body.push_back(body_part);
		if (body.size() == 1)
		{
			body[tracker - 1].Initialize(head.current_x, head.current_y);
		}
		else
		{
			body[tracker - 1].Initialize(body[tracker - 2].current_x, body[tracker - 2].current_y);
		}
	}
	
	if (timer >= velocity)
	{
		head.Update(dt); //change
		for (size_t i = 0; i < tracker; i++)
		{
			if (i == 0)
			{
				body[i].Update(dt, head.current_x, head.current_y);
			}
			else
			{
				body[i].Update(dt, body[i - 1].current_x, body[i - 1].current_y);
			}
		}
		timer = 0;
	}

	for (int i = 0; i < tracker; i++)
	{
		if (head.transform.GetX() == body[i].transform.GetX() && head.transform.GetY() == body[i].transform.GetY())
		{
			return false;
		}
	}

	if (head.transform.position.x < 0 || head.transform.position.x > 1260 || head.transform.position.y < 0 || head.transform.position.y > 700)
	{
		return false;
	}
	return true;
}

void Game::Render(RenderManager& renderManager)
{
	head.Render(renderManager);
	if (body.size() > 0)
	{
		for (int i = 0; i < tracker; i++)
		{
			body[i].Render(renderManager);
		}
	}
	apple.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key)
{	
	head.OnKeyDown(key);
}

void Game::OnKeyUp(KeyCode key)
{
}
