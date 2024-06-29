#pragma once
#include "../Common/BaseState.h"

class GameModeState final : public BaseState
{
public:
	explicit GameModeState(entt::registry& reg);
	void OnEnter() override;
	void OnExit() override;
	void Update(float dt) override;
	size_t NextState() override;
protected : 
	void AddSystems() override;
};

