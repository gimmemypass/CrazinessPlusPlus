#include "InitBoidsSystem.h"
#include "../Components.h"
#include "../Common/ResourceManager/RecourceHolder.h"

InitBoidsSystem::InitBoidsSystem(entt::registry& reg) : BaseSystem(reg)
{
    const auto ent = reg.create();
    reg.emplace<TransformComponent>(ent);
    reg.emplace<SpriteRendererComponent>(ent, LoadBoidSprite());
    reg.emplace<BoidTagComponent>(ent);
    reg.emplace<MovementComponent>(ent, 500.f);
    reg.get<TransformComponent>(ent).scale = sf::Vector2f(1, 1) * 0.1f;
}

InitBoidsSystem::~InitBoidsSystem() noexcept
= default;

void InitBoidsSystem::Update(float dt)
{

}

sf::Sprite InitBoidsSystem::LoadBoidSprite()
{
    const auto& boidTexture = ResourceHolder::Get().textures.Get("boid");
    const auto size = boidTexture.getSize();
    auto sprite = sf::Sprite(boidTexture);
    sprite.setOrigin(size.x/2.f, size.y/2.f);
    return sprite;
}
