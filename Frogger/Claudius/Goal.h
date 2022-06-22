#pragma once
#include "Entity.h"

//An entity representing one single point of destination. Changes state when triggered by player

struct Goal : Entity
{
	void ChangeState();

	virtual void Initialize(Image& backgroundImage_in, float x_in, float y_in) final;
}; 
