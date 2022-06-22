#include "LivesManager.h"

LivesManager::LivesManager()
{

}

void LivesManager::DeleteLife(bool died, Frog& frog_in)
{
	frog_in.isMoving = false;
	frog_in.transform.SetPosition(200, 320);
	frog_in.transform.SetRotation(0);
	if (died)
	{
		lives[livesLeft].sprite.SetSource(64, 64, 16, 16);
	}
	else
	{
		lives[livesLeft].sprite.SetSource(48, 64, 16, 16);
	}
	livesLeft --;
}

void LivesManager::Initialize(Image& spritesheetImage_in)
{
	float x = 0;

	for (int i = 0; i < livesAmount; i++)
	{
		InitializeEntity(spritesheetImage_in, lives[i], x);
		x += 20;
	}
}

void LivesManager::InitializeEntity(Image& spritesheetImage_in, Entity& entity_in, float x_in)
{
	entity_in.transform.SetPosition(x_in, 360);
	entity_in.collider.SetPosition(0, 0);
	entity_in.collider.SetSize(0, 0);
	entity_in.sprite.SetImage(spritesheetImage_in);
	entity_in.sprite.SetSource(48, 96, 16, 16);
}

void LivesManager::Render(RenderManager& renderManager)
{
	for (int i = 0; i < livesAmount; i++)
	{
		lives[i].Render(renderManager);
	}
}
