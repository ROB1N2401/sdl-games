#include "Car.h"

Car::Car()
{

}

Car::Car(CarType type, Image& spritesheetImage_in, float x_in, float y_in)
{
	// loading of sprite
	sprite.SetImage(spritesheetImage_in);
	transform.SetPosition(x_in, y_in);
	switch (type)
	{
		case CarType::Sedan:
		{
			collider.SetSize(16, 16);
			sprite.SetSource(48, 0, 16, 16);
			direction = -1;
			speed = speedReferenceValue * 2;
		} break;
		case CarType::Bulldozer:
		{
			collider.SetSize(16, 16);
			sprite.SetSource(64, 0, 16, 16);
			direction = 1;
			speed = speedReferenceValue * 1;
		} break;
		case CarType::Sport:
		{
			collider.SetSize(16, 16);
			sprite.SetSource(112, 0, 16, 16);
			direction = -1;
			speed = speedReferenceValue * 2.5f;
		} break;
		case CarType::Supercar:
		{
			collider.SetSize(16, 16);
			sprite.SetSource(128, 0, 16, 16);
			direction = 1;
			speed = speedReferenceValue * 3;
		} break;
		case CarType::Truck:
		{
			collider.SetSize(32, 16);
			sprite.SetSource(80, 0, 32, 16);
			direction = -1;
			speed = speedReferenceValue * 1.5f;
		} break;
		default: break;
	}
}

void Car::Update(float dt)
{
	if (transform.GetPosition().x < -40) // relativer to size, all cars are not 40 i would think /jerry
	{
		transform.ChangePosition(480, 0);
	}
	else if (transform.GetPosition().x > 440)
	{
		transform.ChangePosition(-480, 0);
	}
	
	collider.SetPosition(static_cast<int>(transform.GetPosition().x), static_cast<int>(transform.GetPosition().y));
	transform.ChangePosition(speed * direction, 0.f);
}
