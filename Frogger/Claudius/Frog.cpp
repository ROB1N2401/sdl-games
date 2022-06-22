#include "Frog.h"

void Frog::Initialize(Image& spritesheetImage_in)
{
	transform.SetPosition(200, 320);
	collider.SetSize(16, 16);
	sprite.SetImage(spritesheetImage_in);
	sprite.SetSource(32, 0, 16, 16);
}

void Frog::OnKeyUp(KeyCode key)
{
	if (!isMoving)
	{
		if (key == KeyCode::UP_ARROW)
		{
			transform.SetRotation(0);
			isMoving = true;
			delta_x = 0;
			delta_y = -speed;
		}
		else if (key == KeyCode::LEFT_ARROW)
		{
			transform.SetRotation(270);
			isMoving = true;
			delta_x = -speed;
			delta_y = 0;
		}
		else if (key == KeyCode::DOWN_ARROW)
		{
			transform.SetRotation(180);
			isMoving = true;
			delta_x = 0;
			delta_y = speed;
		}
		else if (key == KeyCode::RIGHT_ARROW)
		{
			transform.SetRotation(90);
			isMoving = true;
			delta_x = speed;
			delta_y = 0;
		}
	}
}

void Frog::MakeStep()
{
	transform.ChangePosition(delta_x, delta_y);
}

void Frog::Update(float dt)
{
	if (isMoving && stepsMade < stepsNeeded)
	{
		MakeStep();
		stepsMade++;
	}
	else
	{
		isMoving = false;
		stepsMade = 0;
	}

	collider.SetPosition(static_cast<int>(transform.GetPosition().x), static_cast<int>(transform.GetPosition().y));
}
