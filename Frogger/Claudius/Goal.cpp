#include "Goal.h"

void Goal::ChangeState()
{
	collider.SetPosition(0, 0);
	collider.SetSize(0, 0);
	sprite.SetSource(64, 96, 16, 16);
	transform.SetScale(2);
}

void Goal::Initialize(Image& backgroundImage_in, float x_in, float y_in)
{
	transform.SetPosition(x_in, y_in);
	collider.SetPosition(static_cast<int>(x_in), static_cast<int>(y_in));
	collider.SetSize(28, 40);
	sprite.SetImage(backgroundImage_in);
	sprite.SetSource(0, 0, 0, 0);
}

//void Goal::Render(RenderManager& renderManager)
//{
//
//}
