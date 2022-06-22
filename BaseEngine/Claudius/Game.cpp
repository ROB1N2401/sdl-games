#include "Game.h"
#include <assert.h>
#include "ResourceManager.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"

Game::Game(ResourceManager& resourceManager, SoundManager& soundManager) : resourceManager(resourceManager), soundManager(soundManager)
{
	if (!resourceManager.LoadImageFromFile(image[0], "../Assets/test.bmp"))
		return;
	if (!resourceManager.LoadImageFromFile(image[1], "../Assets/test.png"))
		return;
	if (!resourceManager.LoadSoundFromFile(sound, "../Assets/test.ogg"))
		return;
	if (!resourceManager.LoadMusicFromFile(music, "../Assets/test.ogg"))
		return;
	if (!resourceManager.LoadFontFromFile(font, "../Assets/test.ttf", 16))
		return;
	
	test[0].sprite.SetImage(image[0]);
	test[0].sprite.SetSource(64, 64, 128, 128);
	test[0].transform.SetPosition(100, 100);
	test[0].collider.SetSize(64, 64);
	test[1].sprite.SetImage(image[1]);
	test[1].sprite.SetSource(0, 0, 256, 256);
	test[1].transform.SetPosition(300, 100);
	test[1].transform.SetScale(0.5f, 0.5f);
	test[1].collider.SetSize(64, 64);

	// The test structs movement logic is INSIDE test struct
	text[0].text = "WASD examples of moving box, color change on collision";
	text[1].text = "YUIO to play/stop/raise/lower music/volume";
	text[2].text = "HJK to play/raise/lower sound/volume";
	text[3].text = "QE ZC non uniform scaling";

	for (int i = 0; i < 4; i++)
	{
		text[i].transform.SetPosition(10, static_cast<float>(10 + 20*i));
		text[i].color.SetColor(255, 255, 255, 0);
	}
}

Game::~Game()
{                                                                            
}

bool Game::Enter(int& width, int& height, std::string& title)
{
	width = 640;
	height = 480;
	title = "Clone_Base";
	return true;
}


bool Game::Update(float dt)
{	
	test[0].Update(dt);
	test[1].Update(dt);
	
	if(CollisionManager::CheckCollision(test[0].collider, test[1].collider))
	{
		test[0].color.SetColor(255, 0, 0, 0); // if collison happens set the color in A and B to red
		test[1].color.SetColor(255, 0, 0, 0);
	}
	else
	{
		test[0].color.SetColor(0, 255, 0, 0); // if collision does not happen set the color in A and B to green
		test[1].color.SetColor(0, 255, 0, 0);
	}
	return true;
}

void Game::Render(RenderManager& renderManager)
{
	test[0].Render(renderManager);
	test[1].Render(renderManager);
	for (int i = 0; i < 4; i++)
	{
		renderManager.Render(font, text[i]);
	}
	
}

void Game::OnKeyDown(KeyCode key)
{
	test[1].OnKeyDown(key);
	if (key == KeyCode::H)
		soundManager.PlaySound(sound,0);
	if (key == KeyCode::J)
	{
		soundVolume = (soundVolume >= 100 ? 100 : soundVolume + 10);
		soundManager.SetSoundVolume(sound, soundVolume);
	}
	if (key == KeyCode::K)
	{
		soundVolume = (soundVolume <= 0 ? 0 : soundVolume - 10);
		soundManager.SetSoundVolume(sound, soundVolume);
	}

	if (key == KeyCode::Y)
		soundManager.PlayMusic(music, -1);
	if (key == KeyCode::U)
		soundManager.StopMusic(music);
	if (key == KeyCode::I)
	{
		musicVolume = (musicVolume >= 100 ? 100 : musicVolume + 10);
		soundManager.SetMusicVolume(music, musicVolume);
	}
	if (key == KeyCode::O)
	{
		musicVolume = (musicVolume <= 0 ? 0 : musicVolume - 10);
		soundManager.SetMusicVolume(music, musicVolume);
	}
}

void Game::OnKeyUp(KeyCode key)
{
}
