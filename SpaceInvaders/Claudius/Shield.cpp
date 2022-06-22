#include "Shield.h"

void Shield::Initialize(Image& spritesheetImage_in, float x_in, float y_in)
{
	//32 * 2; 192 * 2 += 46*2
	transform.SetPosition(x_in, y_in);
	collider.SetPosition(static_cast<int>(x_in + 9), static_cast<int>(y_in + 10));
	collider.SetSize(48, 48);
	sprite.SetImage(spritesheetImage_in);
	sprite.SetSource(96, 256, 64, 64);
}

void Shield::Update(float dt)
{
	collider.SetPosition(static_cast<int>(transform.GetPosition().x + 8), static_cast<int>(transform.GetPosition().y + 9));
}

void Shield::Destroy()
{
	collider.isActive = false;
	sprite.SetSource(0, 0, 0, 0);
}
