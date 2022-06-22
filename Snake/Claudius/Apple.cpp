#include "Apple.h"

void Apple::UpdatePosition() 
{
	srand(static_cast<unsigned int>(time(NULL)));
	x = 20 * (rand() % 64);
	y = 20 * (rand() % 36);
	transform.SetPosition(static_cast<float>(x), static_cast<float>(y));
}

void Apple::Initialize()
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(static_cast<char>(255), 0, 0, 0);
	transform.SetPosition(480, 480);
}