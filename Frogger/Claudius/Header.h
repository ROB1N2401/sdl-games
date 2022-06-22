#pragma once
#include "Collider.h"
#include "Color.h"
#include "Transform.h"

struct SideBorder
{
	Transform transform;
	Collider collider;
	Color colliderColor{ 0, 255, 0, 0 };

	void Initialize(float x_in, float y_in);
};