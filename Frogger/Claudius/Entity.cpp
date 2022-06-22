#include "Entity.h"
#include "RenderManager.h"

void Entity::Initialize()
{

}

void Entity::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, transform);
	//renderManager.Render(collider.rect, colliderColor);
}

void Entity::Update(float dt)
{
	collider.SetPosition(static_cast<int>(transform.GetPosition().x), static_cast<int>(transform.GetPosition().y));
}