#include "MoveBoidsSystem.h"
#include "../Components.h"
#include "../Utils/SFMLMath.hpp"
#include <SFML/Window.hpp>
#include "../Services/InputService.h"

MoveBoidsSystem::MoveBoidsSystem(entt::registry& reg) : BaseSystem(reg)
{
}

MoveBoidsSystem::~MoveBoidsSystem() noexcept
= default;

void MoveBoidsSystem::Update(float dt)
{

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return;

	const sf::Vector2f mousePosition = InputService::Instance()->GetMouseWorldPosition();
	const auto view = reg.view<BoidTagComponent>();
	for (auto& ent : view)
	{
		auto& transformComponent = reg.get<TransformComponent>(ent);
		const auto& movementComponent = reg.get<MovementComponent>(ent);
		auto dir = sf::getNormalized(mousePosition - transformComponent.position);
		transformComponent.position = transformComponent.position + dir * movementComponent.speed * dt;
		transformComponent.SetForward(dir);	
	}
}
