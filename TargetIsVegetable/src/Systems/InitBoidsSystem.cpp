#include "InitBoidsSystem.h"
#include "../Components.h"
#include "../Common/ResourceManager/RecourceHolder.h"

InitBoidsSystem::InitBoidsSystem(entt::registry& reg) : BaseSystem(reg)
{
    auto ent = reg.create();
    reg.emplace<TransformComponent>(ent);
    reg.emplace<SpriteRendererComponent>(ent, LoadBoidSprite());
    reg.get<TransformComponent>(ent).scale = sf::Vector2f(1, 1) * 0.1f;
}

InitBoidsSystem::~InitBoidsSystem() noexcept
{

}

void InitBoidsSystem::Update(float dt)
{

}

sf::Sprite InitBoidsSystem::LoadBoidSprite()
{
    auto& boidTexture = ResourceHolder::Get().textures.Get("boid");
    return sf::Sprite(boidTexture);
}
