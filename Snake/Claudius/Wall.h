#pragma once
#include "Color.h"
#include "Rectangle.h"
#include "Transform.h"

struct Wall
{
	Transform transform;
	Color color;
	Rectangle rectangle;

	void Update(double deltaTime);
	void Initialize(float x_in, float y_in, float width_in, float height_in);
};