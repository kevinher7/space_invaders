#include "Game.h"
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    // 1024x768
    // 800x600
    Game game{"Space Invaders", 1024, 768};

    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.render();
    }
}
