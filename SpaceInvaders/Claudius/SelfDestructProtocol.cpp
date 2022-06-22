#include "SelfDestructProtocol.h"

SelfDestructProtocol::SelfDestructProtocol()
{
}

SelfDestructProtocol::SelfDestructProtocol(float timeToDestroy_in)
{
	timeToDestroy = timeToDestroy_in;
}

void SelfDestructProtocol::StartCountdown(Collider& collider_in)
{
	collider_in.isActive = false;
	countdownStarted = true;
}

void SelfDestructProtocol::Destroy()
{
	isToDestroy = true;
}
