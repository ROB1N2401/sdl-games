#pragma once

#include <string>
#include <vector>
#include "Font.h"
#include "Text.h"
#include "Sound.h"
#include "Music.h"
#include "Image.h"
#include "KeyCode.h"

#include "Player.h"
#include "Shield.h"
#include "HUD.h"
#include "EnemiesManager.h"

struct RenderManager;
struct ResourceManager;
struct SoundManager;

class Game
{
	static const unsigned int shieldsAmount = 4;
	bool isRunning = true;

	HUD hud;
	Player player;
	Shield shields[4];
	Entity sideBounds[2];
	EnemiesManager enemiesManager;
	ProjectilesManager projectilesManager;

	Font font;
	Image spritesheetImage;
	Sound playerKilled;
	Sound invaderKilled;
	Sound shoot;
	Sound ufo;
	Sound ufoDestroyed;
	Sound notes[4];

	ResourceManager& resourceManager;
	SoundManager& soundManager;

	void CheckBoundsCollision();
	void CheckEnemiesCollision();
	void CheckPlayerCollision();
	void CheckShieldCollision();

	void CheckOnQuit(KeyCode key);
	void InitializeSideBounds();
	void CheckOnLivesLeft();
	void CheckOnEnemiesLeft();

public:
	
	// references to a resource and sound manager sent in the constructor
	Game(ResourceManager& resourceManager, SoundManager& soundManager);
	~Game();

	// References sent to the game from the base to set the window size and name
	bool Enter(int& width, int& height, std::string& title); 

	// If Games update returns false the program will exit, dt is milliseconds passed since last frame
	bool Update(float dt);

	// reference to the rendermanager sent in the function call, make sure to separate update logic from render logic
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
};

/* ----------- Reference Code ----------- 
	Font font;
	Text text[4];
	Sound sound;
	int soundVolume = 100;
	Music music;
	int musicVolume = 100;
	Image image[2];

	TEST_STRUCT_DELETE_BEFORE_HANDIN test[2];
*/