#pragma once
#include "Car.h"

//Struct-collection of cars that also handles them

struct Traffic
{
	Traffic();
	static const unsigned int sedanAmount = 4;
	static const unsigned int bulldozerAmount = 4;
	static const unsigned int sportAmount = 4;
	static const unsigned int supercarAmount = 3;
	static const unsigned int truckAmount = 3;
	static const unsigned int totalAmount = sedanAmount + bulldozerAmount + sportAmount + supercarAmount + truckAmount;
	
	Car sedans[sedanAmount];
	Car bulldozers[bulldozerAmount];
	Car sports[sportAmount];
	Car supercars[supercarAmount];
	Car trucks[truckAmount];
	Car cars[totalAmount];

	void Initialize(Image& spritesheetImage_in);
	void Render(RenderManager& renderManager);
	void Update(float dt);
};