#include "../Common/BaseSystem.h"
#include "../Components.h";
#include "SpriteRendererSystem.h"
#include <entt.hpp>
#include <iostream>

SpriteRendererSystem::SpriteRendererSystem(entt::registry& reg) : BaseSystem(reg)
{
	
}
SpriteRendererSystem::~SpriteRendererSystem()
= default;

void SpriteRendererSystem::Update(float dt)
{
	const auto view = reg.view<SpriteRendererComponent, TransformComponent>();
	for (auto& ent : view)
	{
		auto& spriteRendererComponent = view.get<SpriteRendererComponent>(ent);
		auto& transformComponent = view.get<TransformComponent>(ent);
		spriteRendererComponent.sprite.setPosition(transformComponent.position.x, transformComponent.position.y);
		spriteRendererComponent.sprite.setRotation(transformComponent.rotation);
		spriteRendererComponent.sprite.setScale(transformComponent.scale);
	}
}
