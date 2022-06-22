#pragma once
#include "Entity.h"
#include "Keycode.h"

//An entity controlled by player. Contains the input logic for it as well

struct Frog : Entity
{
	bool isMoving = false;
	float delta_x = 0;
	float delta_y = 0;
	float speed = 2;
	float stepsMade = 0;	
	float stepsNeeded = 20 / speed;

	void MakeStep();
	void OnKeyUp(KeyCode key);

	virtual void Initialize(Image& backgroundImage_in) final;
	virtual void Update(float dt) final;
};