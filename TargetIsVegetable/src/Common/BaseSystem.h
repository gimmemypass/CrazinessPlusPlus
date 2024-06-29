#pragma once
#include <entt.hpp>

class BaseSystem
{
protected:
	entt::registry& reg;
public :
	explicit BaseSystem(entt::registry& reg) : reg(reg) {}
	BaseSystem(const BaseSystem& sys) = default;
	BaseSystem(BaseSystem&& sys) = default;
	BaseSystem& operator=(BaseSystem&& sys) = delete;
	BaseSystem& operator=(const BaseSystem& sys) = delete;
	virtual ~BaseSystem() noexcept = default;

	virtual void Update(float dt) = 0;
};

