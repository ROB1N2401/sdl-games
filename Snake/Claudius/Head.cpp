#include "Head.h"

void Head::Initialize(float x_in, float y_in)
{
	rectangle.SetBounds(0, 0, 20, 20);
	color.SetColor(0, 250, 0, 0);
	transform.SetPosition((x_in), (y_in));
}

void Head::Render(RenderManager& renderManager)
{
	renderManager.Render(rectangle, color, transform);
}

void Head::Update(double deltaTime)
{
	timer += deltaTime;
	if (timer >= velocity)
	{
		transform.ChangePosition(delta_x, delta_y);
		timer = 0;
	}
}

void Head::OnKeyDown(KeyCode keycode)
{
	switch (keycode)
	{
	case KeyCode::W: {
		delta_x = 0;
		delta_y = -20;
	}
				   break;
	case KeyCode::A: {
		delta_x = -20;
		delta_y = 0;
	}
				   break;
	case KeyCode::S: {
		delta_x = 0;
		delta_y = 20;
	}
				   break;
	case KeyCode::D: {
		delta_x = 20;
		delta_y = 0;
	}
				   break;
	default:
		break;

	}
}
