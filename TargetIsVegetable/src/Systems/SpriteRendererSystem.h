#pragma once
#include <entt.hpp>
#include "../Common/BaseSystem.h"

class SpriteRendererSystem final : public BaseSystem
{
public :
	explicit SpriteRendererSystem(entt::registry& reg);
	~SpriteRendererSystem() noexcept override;
	void Update(float dt) override;
};
