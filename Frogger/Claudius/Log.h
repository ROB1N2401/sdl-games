#pragma once
#include "Entity.h"

//A struct describing a single log, as well as containing data for different types of those

enum class LogType
{
	Short,
	Medium,
	Long
};

struct Log : Entity
{
	float baseSpeed = 1;
	float speed = 0;

	Log();

	virtual void Initialize(Image& spritesheetImage_in, LogType type_in, int direction_in, float x_in, float y_in) final;
	virtual void Update(float dt) final;
};