#include "Tail.h"

void Tail::Initialize(float x_in, float y_in)
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(0, 250, 0, 0);
	transform.SetPosition((x_in), (y_in));
}

void Tail::Render(RenderManager& renderManager)
{
	renderManager.Render(rectangle, color, transform);
}

void Tail::Update(double deltaTime)
{

}
