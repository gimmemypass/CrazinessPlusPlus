#pragma once
#include "../Common/BaseSystem.h"
#include <sfml/Graphics.hpp>
#include "../Components.h"
#include "../Common/ResourceManager/RecourceHolder.h"

class InitBoidsSystem : public BaseSystem
{
public:
    InitBoidsSystem(entt::registry& reg);
	~InitBoidsSystem() noexcept override;
	void Update(float dt) override;
private:
    sf::Sprite LoadBoidSprite();
};