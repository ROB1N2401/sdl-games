#pragma once
#include "Color.h"
#include "Entity.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Transform.h"
#include "RenderManager.h"
#include "time.h"

struct Apple : Entity
{
	int x = 0, y = 0;

	virtual void UpdatePosition() final;
	virtual void Initialize() final;
};
