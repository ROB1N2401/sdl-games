#pragma once
#include "Entity.h"

//Struct for water section of level

struct Water : Entity
{
	virtual void Initialize(Image& backgroundImage_in) final;
	virtual void Update(float dt) final;
};

