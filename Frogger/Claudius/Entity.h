#pragma once
#include "RenderManager.h"
#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"

//A base for other structs

struct Entity
{
	Sprite sprite; 
	Transform transform;
	Collider collider;  
	Color colliderColor{ 0, 255, 0, 255 }; 

	virtual void Initialize();
	virtual void Render(RenderManager& renderManager);
	virtual void Update(float dt);
};
