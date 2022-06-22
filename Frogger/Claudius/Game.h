#pragma once
#include <string>
#include <vector>
#include "KeyCode.h"
#include "Image.h"
#include "Sprite.h"
#include "Transform.h"
#include "Entity.h"
#include "Background.h"
#include "GoalsManager.h"
#include "LivesManager.h"
#include "Water.h"
#include "River.h"
#include "Frog.h"
#include "Traffic.h"

struct RenderManager;
struct ResourceManager;

class Game
{
	bool isRunning = true;

	Background background;
	Water water;
	River river;
	Frog frog;
	Traffic traffic;
	GoalsManager goalsManager;
	LivesManager livesManager;

	Image backgroundImage;
	Image spritesheetImage;
	
	ResourceManager& m_resourceManager;

	bool CheckBounds();
	void CheckWaterCollision();
	void CheckTrafficCollision();
	void CheckGoalCollision();
	void CheckLogCollision();

	void CheckOnQuit(KeyCode key);
	void CheckOnLives();

public:
	Game(ResourceManager& resourceManager);
	~Game();
	bool Enter(int& width, int& height, std::string& title); // References sent to the game from the base to set the window size and name
	bool Update(float dt); // If Games update returns false the program will exit
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
};