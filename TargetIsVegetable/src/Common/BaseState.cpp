#include "BaseState.h"

BaseState::BaseState(entt::registry& reg) : reg(reg)
{
}
void BaseState::UpdateSystems(float dt)
{
	for (auto& system : systems)
	{
		system->Update(dt);
	}
}
