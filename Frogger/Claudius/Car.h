#pragma once
#include "Entity.h"

//A struct containg all required data for a SINGLE car, as well as functionality for instantiating different types of those

enum class CarType
{
	Sedan,
	Bulldozer,
	Sport,
	Supercar,
	Truck
};

struct Car : Entity
{
	Car();
	Car(CarType type, Image& spritesheetImage_in, float x_in, float y_in);
	int direction = 1;
	float speedReferenceValue = 0.5f;
	float speed = 0;

	virtual void Update(float dt) final;
};