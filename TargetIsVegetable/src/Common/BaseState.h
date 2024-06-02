#pragma once
#include <vector>
#include <memory>
#include "BaseSystem.h"
#include <entt.hpp>

class BaseState
{
protected:
    entt::registry& _reg;
public:
    BaseState(entt::registry& reg);

    BaseState(const BaseState&) = delete;

    BaseState(BaseState&& other) noexcept = default;

    BaseState& operator=(const BaseState&) = delete;

    BaseState& operator=(BaseState&& other) = default;

    virtual ~BaseState() noexcept = default;

    virtual void OnEnter() = 0;

    virtual void OnExit() = 0;

    virtual void Update(float dt) = 0;

    virtual size_t NextState() = 0;


protected: 
    std::vector<std::unique_ptr<BaseSystem>> _systems;
    virtual void AddSystems() = 0;
    void UpdateSystems(float dt);
};

