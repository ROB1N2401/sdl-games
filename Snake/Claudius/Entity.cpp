#include "Entity.h"


void Entity::Render(RenderManager& renderManager)
{
	renderManager.Render(rectangle, color, transform);
}

void Entity::Initialize(float x_in, float y_in)
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(0, 0, 0, 0);
	transform.SetPosition((x_in), (y_in));
}

void Entity::Update(double deltaTIme)
{

}
