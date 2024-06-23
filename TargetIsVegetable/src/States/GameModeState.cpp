#include "GameModeState.h"
#include "../SystemsHelper.h"
#include "../Systems/InitBoidsSystem.h"

void GameModeState::OnEnter()
{
	AddSystems();
	
}

void GameModeState::OnExit()
{
}

void GameModeState::Update(float dt)
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
}
