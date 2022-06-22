#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"

#include "Font.h"
#include "Text.h"
#include "Sound.h"
#include "Music.h"
#include "Image.h"
#include "TEST_STRUCT_DELETE_BEFORE_HANDIN.h"

struct RenderManager;
struct ResourceManager;
struct SoundManager;

class Game
{
	Font font;
	Text text[4];
	Sound sound;
	int soundVolume = 100;
	Music music;
	int musicVolume = 100;
	Image image[2];

	TEST_STRUCT_DELETE_BEFORE_HANDIN test[2];

	ResourceManager& resourceManager;
	SoundManager& soundManager;
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