#pragma once
#include "Collider.h"

//A struct which is responsible for launching destruction animations

struct SelfDestructProtocol
{
	SelfDestructProtocol();
	SelfDestructProtocol(float timeToDestroy_in);
	float timeToDestroy = 0.5;
	float timeElapsed = 0;
	bool isToDestroy = false;
	bool countdownStarted = false;

	void StartCountdown(Collider& collider_in);
	void Destroy();
};