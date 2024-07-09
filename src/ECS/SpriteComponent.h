#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "../TextureManager.h"
#include <memory>

class SpriteComponent : public Component
{
public: // Trying with make_unique (could fail)
    SpriteComponent()
        : m_transform{nullptr}, m_texture{nullptr}, m_srcRec{0.0f, 0.0f, 64.0f, 64.0f}, m_destRec{0.0f, 0.0f, 64.0f, 64.0f} {}
    SpriteComponent(const char *spritePath)
        : m_transform{nullptr}, m_texture{nullptr}, m_srcRec{0.0f, 0.0f, 64.0f, 64.0f}, m_destRec{0.0f, 0.0f, 64.0f, 64.0f}
    {
        setTexture(spritePath);
    }

    void init() override
    {
        m_transform = std::make_unique<TransformComponent>(entity->getComponent<TransformComponent>());
        m_srcRec.w = m_transform->width;
        m_srcRec.h = m_transform->height;
    }

    void setTexture(const char *spritePath)
    {
        m_texture = TextureManager::LoadTexture(spritePath);
    }

    void update() override
    {
        m_destRec.x = m_transform->position.x;
        m_destRec.y = m_transform->position.y;

        m_destRec.w = m_transform->width * m_transform->scale;
        m_destRec.h = m_transform->height * m_transform->scale;
    }

    void draw() override
    {
        TextureManager::DrawTexture(m_texture, m_srcRec, m_destRec);
    }

    SpriteComponent(const SpriteComponent &) = delete;
    SpriteComponent &operator=(const SpriteComponent &) = delete;
    SpriteComponent(SpriteComponent &&) = delete;
    SpriteComponent &operator=(SpriteComponent &&) = delete;
    ~SpriteComponent(){};

private:
    std::unique_ptr<TransformComponent> m_transform;
    SDL_Texture *m_texture;
    SDL_FRect m_srcRec, m_destRec;
};

#endif
