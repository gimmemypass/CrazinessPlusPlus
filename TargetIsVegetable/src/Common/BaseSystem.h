#pragma once
#include <entt.hpp>

class BaseSystem
{
protected:
	entt::registry& _reg;
public :
	BaseSystem(entt::registry& reg) : _reg(reg) {};
	BaseSystem(const BaseSystem& sys) = default;
	BaseSystem(BaseSystem&& sys) = default;
	BaseSystem& operator=(BaseSystem&& sys) = delete;
	BaseSystem& operator=(const BaseSystem& sys) = delete;
	virtual ~BaseSystem() noexcept = default;

	virtual void Update(float dt) = 0;
};

