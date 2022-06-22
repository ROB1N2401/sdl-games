#include "Log.h"

Log::Log()
{
	
}

void Log::Initialize(Image& spritesheetImage_in, LogType type_in, int direction_in, float x_in, float y_in)
{
	sprite.SetImage(spritesheetImage_in);
	transform.SetPosition(x_in, y_in);
	speed = baseSpeed * direction_in;

	switch (type_in)
	{
	case LogType::Short:
	{
		sprite.SetSource(64, 16, 48, 16);
		collider.SetSize(48, 19);
	} break;
	case LogType::Medium:
	{
		sprite.SetSource(64, 32, 64, 16);
		collider.SetSize(64, 19);
	} break;

	case LogType::Long:
	{
		sprite.SetSource(64, 48, 80, 16);
		collider.SetSize(80, 19);
	} break;
	default: break;
	}
}

void Log::Update(float dt)
{
	if (transform.GetPosition().x < -100) // relativer to size, all cars are not 40 i would think /jerry
	{
		transform.ChangePosition(600, 0);
	}
	else if (transform.GetPosition().x > 500)
	{
		transform.ChangePosition(-600, 0);
	}

	collider.SetPosition(static_cast<int>(transform.GetPosition().x), static_cast<int>(transform.GetPosition().y));
	transform.ChangePosition(speed, 0.f);
}
