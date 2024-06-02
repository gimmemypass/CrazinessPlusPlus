#pragma once
#include <entt.hpp>
#include "../Common/BaseSystem.h"

class SpriteRendererSystem : public BaseSystem
{
public :
	SpriteRendererSystem(entt::registry& reg);
	~SpriteRendererSystem() noexcept override;
	void Update(float dt) override;
};
