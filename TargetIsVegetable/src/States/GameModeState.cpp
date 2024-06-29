#include "GameModeState.h"
#include "../SystemsHelper.h"
#include "../Systems/InitBoidsSystem.h"
#include "../Systems/MoveBoidsSystem.h"

GameModeState::GameModeState(entt::registry& reg): BaseState(reg)
{}

void GameModeState::OnEnter()
{
	AddSystems();
	
}

void GameModeState::OnExit()
{
}

void GameModeState::Update(const float dt)
{
	UpdateSystems(dt);
}

size_t GameModeState::NextState()
{
	return size_t();
}

void GameModeState::AddSystems()
{
	SystemsHelper::AddDefaultSystems(systems, reg);
	systems.push_back(std::make_unique<InitBoidsSystem>(reg));
	systems.push_back(std::make_unique<MoveBoidsSystem>(reg));
}
