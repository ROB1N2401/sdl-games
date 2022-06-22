#include "Wall.h"

void Wall::Initialize(float x_in, float y_in, float width_in, float height_in)
{
	rectangle.SetBounds(0, 0, width_in, height_in);
	color.SetColor(0, 0, 0, 100);
	transform.SetPosition(x_in, y_in);
}
