#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "../Game.h"
#include <SDL3/SDL.h>

class ColliderComponent : public Component
{
public:
    ColliderComponent() = delete;
    ColliderComponent(std::string name)
        : transform{nullptr}, colliderBox{0.0f, 0.0f, 0.0f, 0.0f}, tagName{name} {}
    ColliderComponent(const ColliderComponent &) = delete;
    ColliderComponent &operator=(const ColliderComponent &) = delete;
    ColliderComponent(ColliderComponent &&) = delete;
    ColliderComponent &operator=(ColliderComponent &&) = delete;
    ~ColliderComponent() = default;

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();

        Game::gameColliders.push_back(this);
    }

    void update() override
    {
        colliderBox.x = transform->position.x;
        colliderBox.y = transform->position.y;
        colliderBox.w = transform->width * transform->scale;
        colliderBox.h = transform->height * transform->scale;
    }

    TransformComponent *transform;
    SDL_FRect colliderBox;
    std::string tagName;
};

#endif
