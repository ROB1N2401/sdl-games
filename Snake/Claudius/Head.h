#pragma once
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Transform.h"
#include "RenderManager.h"

struct Head
{
	Transform transform;
	Color color;
	Rectangle rectangle;
	const float velocity = 10;
	float timer = 0;
	float delta_x = 20;
	float delta_y = 0;

	void Render(RenderManager& renderManager);
	void Update(double deltaTime);
	void OnKeyDown(KeyCode keycode);
	void Initialize(float x_in, float y_in);
};