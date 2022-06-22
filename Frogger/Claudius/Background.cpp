#include "Background.h"

void Background::Initialize(Image& backgroundImage_in)
{
	topBackground.sprite.SetImage(backgroundImage_in);
	topBackground.sprite.SetSource(0, 0, 400, 60);
	topBackground.transform.SetPosition(0, 0);

	middleBackground.sprite.SetImage(backgroundImage_in);
	middleBackground.sprite.SetSource(0, 60, 400, 40);
	middleBackground.transform.SetPosition(0, 180);

	bottomBackground.sprite.SetImage(backgroundImage_in);
	bottomBackground.sprite.SetSource(0, 60, 400, 40);
	bottomBackground.transform.SetPosition(0, 320);
}

void Background::Render(RenderManager& renderManager)
{
	topBackground.Render(renderManager);
	middleBackground.Render(renderManager);
	bottomBackground.Render(renderManager);
}
