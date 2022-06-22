#pragma once
#include "Entity.h"
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Transform.h"
#include "RenderManager.h"

struct SnakeBase : Entity
{	
	float timer = 0;
	float current_x = 0, current_y = 0;
	float new_x = 0, new_y = 0;
};


struct Head : SnakeBase 
{
	float delta_x = 20;
	float delta_y = 0;

	void OnKeyDown(KeyCode keycode);
	// Inherited via SnakeBase
	virtual void Update(double deltaTime) final;
	virtual void Initialize(float x_in, float y_in) final;
};

struct Body : SnakeBase
{
	// Inherited via SnakeBase
	virtual void Update(double deltaTime, float x_in, float y_in) final;
	virtual void Initialize(float x_in, float y_in) final;
};