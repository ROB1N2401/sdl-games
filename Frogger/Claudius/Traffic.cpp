#include "Traffic.h"
#include <ctime>

Traffic::Traffic()
{

}

void Traffic::Initialize(Image& spritesheetImage_in)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < sedanAmount; i++)
	{
		int x = rand() % 80 + 100 * i;
		Car sedan(CarType::Sedan, spritesheetImage_in, static_cast<float>(x), 300);
		sedans[i] = sedan;
	}
	for (int i = 0; i < bulldozerAmount; i++)
	{
		int x = rand() % 80 + 100 * i;
		Car bulldozer(CarType::Bulldozer, spritesheetImage_in, static_cast<float>(x), 280);
		bulldozers[i] = bulldozer;
	}
	for (int i = 0; i < sportAmount; i++)
	{
		int x = rand() % 80 + 100 * i;
		Car sport(CarType::Sport, spritesheetImage_in, static_cast<float>(x), 260);
		sports[i] = sport;
	}
	for (int i = 0; i < supercarAmount; i++)
	{
		int x = rand() % 80 + 100 * i;
		Car supercar(CarType::Supercar, spritesheetImage_in, static_cast<float>(x), 240);
		supercars[i] = supercar;
	}
	for (int i = 0; i < truckAmount; i++)
	{
		int x = rand() % 80 + 100 * i;
		Car truck(CarType::Truck, spritesheetImage_in, static_cast<float>(x), 220);
		trucks[i] = truck;
	}

	for (int i = 0; i < totalAmount; i++)
	{
		for (int j = 0; j < sedanAmount; j++)
		{
			cars[j] = sedans[j];
		}
		for (int j = 0; j < bulldozerAmount; j++)
		{
			cars[sedanAmount + j] = bulldozers[j];
		}
		for (int j = 0; j < sportAmount; j++)
		{
			cars[sedanAmount + bulldozerAmount + j] = sports[j];
		}
		for (int j = 0; j < supercarAmount; j++)
		{
			cars[sedanAmount + bulldozerAmount + sportAmount + j] = supercars[j];
		}
		for (int j = 0; j < truckAmount; j++)
		{
			cars[sedanAmount + bulldozerAmount + sportAmount + supercarAmount + j] = trucks[j];
		}
	}
}

void Traffic::Render(RenderManager& renderManager)
{
	for (int i = 0; i < totalAmount; i++)
	{
		cars[i].Render(renderManager);
	}
}

void Traffic::Update(float dt)
{
	for (int i = 0; i < totalAmount; i++)
	{
		cars[i].Update(dt);
	}
}
