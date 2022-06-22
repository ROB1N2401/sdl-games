#include "Hud.h"

void HUD::Initialize(Image& spritesheetImage_in, Font& font_in)
{
	font = font_in;

	float x = 0, y = 478;
	for (int i = 0; i < 16; i++)
	{
		borderPiece[i].collider.isActive = false;
		borderPiece[i].transform.SetPosition(x, y);
		borderPiece[i].sprite.SetImage(spritesheetImage_in);
		borderPiece[i].sprite.SetSource(0, 128, 32, 32);
		x += 32;
	}

	x = 52; y = 480;
	for (int i = 0; i < livesDisplayed; i++)
	{
		lives[i].collider.isActive = false;
		lives[i].transform.SetPosition(x, y);
		lives[i].sprite.SetImage(spritesheetImage_in);
		lives[i].sprite.SetSource(128, 0, 32, 32);
		x += 34;
	}

	x = 18; y = 480;
	livesText.transform.SetPosition(x, y);
	livesText.text = "0" + std::to_string(livesLeft);

	x = 274; y = 480;
	credit.transform.SetPosition(x, y);
	credit.text = "CREDIT 000";

	x = 190; y = 18;
	scoreText.transform.SetPosition(x, y);
	scoreText.text = "SCORE";

	x = 195; y = 50;
	scoreItself.transform.SetPosition(x, y);
	scoreItself.text = std::to_string(currentScore);

	x = 170; y = 100;
	gameOver.transform.SetPosition(x, y);
	gameOver.text = "";
}

void HUD::Render(RenderManager& renderManager)
{
	renderManager.Render(font, scoreText);
	renderManager.Render(font, scoreItself);
	renderManager.Render(font, livesText);
	renderManager.Render(font, credit);
	renderManager.Render(font, gameOver);
	
	for (int i = 0; i < 16; i++)
	{
		borderPiece[i].Render(renderManager);
	}
	for (int i = 0; i < livesDisplayed; i++)
	{
		lives[i].Render(renderManager);
	}
}

void HUD::UpdateScore(int score_in)
{
	currentScore += score_in;
	scoreItself.text = std::to_string(currentScore);
}

void HUD::InstantiateVictory()
{
	gameOver.color.SetColor(255, 175, 0, 0);
	gameOver.text = "YOU WON!!!";
}

void HUD::InstantiateLoss()
{
	gameOver.color.SetColor(255, 0, 0, 0);
	gameOver.text = "GAME OVER";
}

void HUD::LoseLife()
{
	livesLeft--;
	livesText.text = "0" + std::to_string(livesLeft);
	if (livesLeft > 0)
	{
		lives[livesLeft - 1].sprite.SetSource(0, 0, 0, 0);
	}
	else
	{
		InstantiateLoss();
	}
}
