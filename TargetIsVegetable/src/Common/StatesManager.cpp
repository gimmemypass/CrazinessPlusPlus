#include "StatesManager.h"
#include "../States/EditorState.h"
#include "../States/GameModeState.h"
#include <memory>

StatesManager::StatesManager(entt::registry& reg) : _reg(reg)
{
	_states[typeid(GameModeState).hash_code()] = std::make_unique<GameModeState>(_reg);
	_currentState = typeid(GameModeState).hash_code();
	_states[_currentState]->OnEnter();
}

void StatesManager::Update(float dt)
{
	_states[_currentState]->Update(dt);
}
