#pragma once

#include <entt.hpp>
#include "../Common/BaseSystem.h"

class MoveBoidsSystem : public BaseSystem
{
public :
	MoveBoidsSystem(entt::registry& reg);
	~MoveBoidsSystem() noexcept override;
	void Update(float dt) override;
};
