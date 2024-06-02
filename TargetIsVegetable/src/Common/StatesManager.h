#pragma once
#include "BaseState.h"
#include <memory>

class StatesManager
{
private:
	entt::registry& _reg;
	size_t _currentState;
	std::unordered_map<size_t, std::unique_ptr<BaseState>> _states;
public:
	StatesManager(entt::registry& reg);
	void Update(float dt);
};

