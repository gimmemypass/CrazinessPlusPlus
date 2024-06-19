#include "../Common/BaseSystem.h"
#include "../Components/SpriteRendererComponent.h";
#include "../Components/TransformComponent.h";
#include "SpriteRendererSystem.h"
#include <iostream>
#include <entt.hpp>

SpriteRendererSystem::SpriteRendererSystem(entt::registry& reg) : BaseSystem(reg)
{
	
}
SpriteRendererSystem::~SpriteRendererSystem()
{

}
void SpriteRendererSystem::Update(float dt)
{
	std::cout << "sprite renderer system update" << std::endl;
	auto view = _reg.view<SpriteRendererComponent, TransformComponent>();
	for (auto& ent : view)
	{
		auto& spriteRendererComponent = view.get<SpriteRendererComponent>(ent);
		auto& transformComponent = view.get<TransformComponent>(ent);
		spriteRendererComponent.sprite.setPosition(transformComponent.position);
		spriteRendererComponent.sprite.setRotation(transformComponent.rotation);
		spriteRendererComponent.sprite.setScale(transformComponent.scale);
	}
}
