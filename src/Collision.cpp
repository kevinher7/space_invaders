#include "Collision.h"
#include "ECS/ColliderComponent.h"

bool Collision::AABB(const SDL_FRect &rectA, const SDL_FRect &rectB)
{
    if (rectA.x + rectA.w >= rectB.x &&
        rectB.x + rectB.w >= rectA.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y)
    {
        return true;
    }

    return false;
}

bool Collision::AABB(const ColliderComponent &colliderA, const ColliderComponent &colliderB)
{
    if (AABB(colliderA.colliderBox, colliderB.colliderBox))
    {
        std::cout << colliderA.tagName << " hit: " << colliderB.tagName << "\n";
        return true;
    }

    return false;
}
