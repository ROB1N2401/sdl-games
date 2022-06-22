#include "Water.h"

void Water::Initialize(Image& backgroundImage_in)
{
	transform.SetPosition(0, 0);
	collider.SetPosition(0, 0);
	collider.SetSize(400, 170);
	sprite.SetImage(backgroundImage_in);
	sprite.SetSource(0, 100, 400, 180);
}

void Water::Update(float dt)
{

}
