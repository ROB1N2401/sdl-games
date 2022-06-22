#pragma once
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Transform.h"
#include "RenderManager.h"

struct Tail
{
	Transform transform;
	Color color;
	Rectangle rectangle;

	float delta_x = 20;
	float delta_y = 0;

	void Render(RenderManager& renderManager);
	void Update(double deltaTime);
	void Initialize(float x_in, float y_in);
};
