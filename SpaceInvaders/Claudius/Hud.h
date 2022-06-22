#pragma once
#include "Font.h"
#include "Text.h"
#include "Entity.h"

//A struct gor HUD which also handles the logic of player's lives

struct HUD
{
	static const unsigned int livesAmount = 5;
	static const unsigned int livesDisplayed = livesAmount - 1;  //This value is used for depicting enough icons of life on the display
	int livesLeft = livesAmount;
	int currentScore = 0;

	Entity borderPiece[16];
	Entity lives[livesDisplayed];
	Font font;
	Text scoreText;
	Text scoreItself;
	Text credit;
	Text livesText;
	Text gameOver;
 
	void Initialize(Image& spritesheetImage_in, Font& font_in);
	void Render(RenderManager& renderManager);
	void UpdateScore(int score_in);
	void InstantiateVictory();
	void InstantiateLoss();
	void LoseLife();
};