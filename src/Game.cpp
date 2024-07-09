#include "Game.h"
#include "TextureManager.h"
#include "Components.h"

#include <SDL3_image/SDL_image.h>
#include <iostream>

SDL_Event Game::gameEvent{};

Manager gameManager{};

Entity &player(gameManager.addEntity());

Game::Game(const char *windowTitle, int width, int height)
    : windowWidth{width}, windowHeight{height}, m_gameWindow{nullptr}, m_isRunning{false}
{
    SDL_InitFlags iFlags{0};
    SDL_WindowFlags wFlags{0};
    if (SDL_InitSubSystem(iFlags) == 0)
    {
        m_gameWindow = SDL_CreateWindow(windowTitle, windowWidth, windowHeight, wFlags);
        gameRenderer = SDL_CreateRenderer(m_gameWindow, NULL);

        SDL_Surface *tmpSurface{IMG_Load("./assets/player.png")};
        SDL_SetWindowIcon(m_gameWindow, tmpSurface);
        SDL_DestroySurface(tmpSurface);

        SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 1);
        m_isRunning = true;
    }
    else
    {
        std::cout << "Subsystems Initialization Failed\n";
    }

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("./assets/player.png");
}

void Game::handleEvents()
{
    SDL_PollEvent(&gameEvent);
    switch (gameEvent.type)
    {
    case SDL_EVENT_QUIT:
        m_isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    gameManager.refresh();
    gameManager.update();
}
void Game::render()
{
    SDL_RenderClear(gameRenderer);
    gameManager.draw();
    SDL_RenderPresent(gameRenderer);
}

Game::~Game()
{
    SDL_DestroyWindow(m_gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}
