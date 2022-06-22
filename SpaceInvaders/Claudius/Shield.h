#pragma once
#include "Entity.h"

//A struct describing a single defending shield

struct Shield : Entity
{
	virtual void Initialize(Image& spritesheetImage_in, float x_in, float y_in) final;
	virtual void Update(float dt) final;

	void Destroy();
};
