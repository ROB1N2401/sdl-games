#include "Entity.h"

void Entity::Initialize()
{

}

void Entity::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, transform);
	//if (collider.isActive)
	//{
	//	renderManager.Render(collider.rect, colliderColor);
	//}
}

void Entity::Update(float dt)
{
	collider.SetPosition(static_cast<int>(transform.GetPosition().x), static_cast<int>(transform.GetPosition().y));
}
