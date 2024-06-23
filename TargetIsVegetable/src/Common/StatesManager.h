#pragma once
#include "BaseState.h"
#include <memory>

class StatesManager
{
private:
	entt::registry& reg;
	size_t currentState;
	std::unordered_map<size_t, std::unique_ptr<BaseState>> states;
public:
	StatesManager(entt::registry& reg);
	void Update(float dt);
};

