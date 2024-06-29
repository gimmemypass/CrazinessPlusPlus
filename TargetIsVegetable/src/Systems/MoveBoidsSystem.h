#pragma once

#include "../Common/BaseSystem.h"

class MoveBoidsSystem final : public BaseSystem
{
public :
	explicit MoveBoidsSystem(entt::registry& reg);
	~MoveBoidsSystem() noexcept override;
	void Update(float dt) override;
};
