#include "BaseState.h"

BaseState::BaseState(entt::registry& reg) : _reg(reg)
{
}
void BaseState::UpdateSystems(float dt)
{
	for (auto& system : _systems)
	{
		system->Update(dt);
	}
}
