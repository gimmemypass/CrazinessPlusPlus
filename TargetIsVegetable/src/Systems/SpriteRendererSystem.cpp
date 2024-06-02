#include "../Common/BaseSystem.h"
#include "../Components/SpriteRendererComponent.h";
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
	auto view = _reg.view<SpriteRendererComponent>();
	for (auto& ent : view)
	{
		//todo
	}
}
