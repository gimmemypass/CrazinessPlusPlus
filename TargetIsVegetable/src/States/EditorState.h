#pragma once
#include "../Common/BaseState.h"

class EditorState : public BaseState
{
public:
	EditorState(entt::registry& reg) : BaseState(reg) {};
	void OnEnter() override;
	void OnExit() override;
	void Update(float dt) override;
	size_t NextState() override;
protected : 
	void AddSystems() override;
};

