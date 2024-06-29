#pragma once
#include "../Common/BaseSystem.h"
#include <sfml/Graphics.hpp>


class InitBoidsSystem final : public BaseSystem
{
public:
    explicit InitBoidsSystem(entt::registry& reg);
	~InitBoidsSystem() noexcept override;
	void Update(float dt) override;
private:
    sf::Sprite LoadBoidSprite();
};