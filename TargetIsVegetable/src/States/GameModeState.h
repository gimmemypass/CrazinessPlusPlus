#pragma once
#include "../Common/BaseState.h"

class GameModeState : public BaseState
{
public:
	GameModeState(entt::registry& reg) : BaseState(reg) {};
	void OnEnter() override;
	void OnExit() override;
	void Update(float dt) override;
	size_t NextState() override;
protected : 
	void AddSystems() override;
};

