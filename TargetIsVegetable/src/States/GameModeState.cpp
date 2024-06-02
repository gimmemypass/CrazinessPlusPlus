#include "GameModeState.h"
#include "../SystemsHelper.h"

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
	SystemsHelper::AddDefaultSystems(_systems, _reg);
}
