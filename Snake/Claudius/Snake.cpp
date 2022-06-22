#include "Snake.h"

void Head::Initialize(float x_in, float y_in)
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(static_cast<char>(255), static_cast<char>(255), 0, 0);
	transform.SetPosition((x_in), (y_in));
}

void Head::Update(double deltaTime)
{
	current_x = transform.GetX();
	current_y = transform.GetY();
	transform.ChangePosition(delta_x, delta_y);
	new_x = transform.GetX();
	new_y = transform.GetY();	
	timer = 0;
}

void Head::OnKeyDown(KeyCode keycode)
{
	if (keycode == KeyCode::UP_ARROW && delta_y != 20)
	{
		delta_x = 0;
		delta_y = -20;
	}
	else if (keycode == KeyCode::LEFT_ARROW && delta_x != 20)
	{
		delta_x = -20;
		delta_y = 0;
	}
	else if (keycode == KeyCode::DOWN_ARROW && delta_y != -20)
	{
		delta_x = 0;
		delta_y = 20;
	}
	else if (keycode == KeyCode::RIGHT_ARROW && delta_x != -20)
	{
		delta_x = 20;
		delta_y = 0;
	}
}

void Body::Initialize(float x_in, float y_in)
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(0, static_cast<char>(255), 0, 0);
	transform.SetPosition((x_in), (y_in));
}

void Body::Update(double deltaTime, float x_in, float y_in)
{
	current_x = transform.GetX();
	current_y = transform.GetY();
	transform.SetPosition(x_in, y_in);
	new_x = transform.GetX();
	new_y = transform.GetY();
	timer = 0;
}
