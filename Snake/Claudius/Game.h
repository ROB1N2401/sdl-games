#pragma once

#include <string>
#include <vector>
#include "ResourceManager.h"
#include "RenderManager.h"
#include "KeyCode.h"
#include "Entity.h"
#include "Snake.h"
#include "Apple.h"

struct RenderManager;
struct ResourceManager;

class Game
{
	Apple apple;
	Head head;
	ResourceManager& m_resourceManager;

	std::vector<Body> body;
	float velocity = 10;
	double timer = 0;
	size_t tracker = 0;



public:
	Game(ResourceManager& resourceManager);
	~Game();
	bool Enter(int& width, int& height, std::string& title);
	bool Update(double dt);
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
};