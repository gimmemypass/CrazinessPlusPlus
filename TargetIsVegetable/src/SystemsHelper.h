#pragma once
#include "Systems/SpriteRendererSystem.h"
#include <vector>
#include <entt.hpp>

class SystemsHelper
{
public:
	SystemsHelper() = delete;

	static void AddDefaultSystems(std::vector<std::unique_ptr<BaseSystem>>& list, entt::registry &reg)
	{
		list.push_back(std::make_unique<SpriteRendererSystem>(reg));
	}
};
