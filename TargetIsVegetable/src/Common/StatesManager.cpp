#include "StatesManager.h"
#include "../States/GameModeState.h"
#include <memory>

StatesManager::StatesManager(entt::registry& reg) : reg(reg)
{
	states[typeid(GameModeState).hash_code()] = std::make_unique<GameModeState>(reg);
	currentState = typeid(GameModeState).hash_code();
	states[currentState]->OnEnter();
}

void StatesManager::Update(float dt)
{
	states[currentState]->Update(dt);
}
