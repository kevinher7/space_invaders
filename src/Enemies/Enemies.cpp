#include "Enemies.h"
#include "Components.h"
#include "../Game.h"

void Enemies::init()
{
    int xpos{48};
    int ypos{(64 + 32) * lineNumber - 64};

    for (int enemyID{0}; enemyID < 10; enemyID++)
    {
        Entity &newEnemy{Game::gameManager.addEntity()};
        newEnemy.addComponent<TransformComponent>(xpos, ypos);
        newEnemy.addComponent<SpriteComponent>(spritePath.c_str());
        enemyEntities.push_back(&newEnemy);
        xpos += 64 + 32;
    }
}
