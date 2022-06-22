#pragma once
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Transform.h"
#include "RenderManager.h"
#include "time.h"

struct Entity
{
	Transform transform;
	Color color;
	Rectangle rectangle;

	virtual void Render(RenderManager& renderManager);
	virtual void Initialize(float x_in, float y_in);
	virtual void Update(double deltaTIme);
};
