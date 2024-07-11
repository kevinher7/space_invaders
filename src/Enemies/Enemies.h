#ifndef ENEMIES_H
#define ENEMIES_H

#include "../ECS/ECS.h"
#include <vector>
#include <string>

class Enemies
{
public:
    Enemies(int num) : lineNumber{num}, spritePath{}, enemyEntities{}
    {
        switch (num)
        {
        case 1:
            spritePath = "assets/enemy1.png";
            break;
        case 2:
            spritePath = "assets/enemy2.png";
            break;
        case 3:
            spritePath = "assets/enemy3.png";
            break;
        case 4:
            spritePath = "assets/enemy4.png";
            break;

        default:
            break;
        }
    }

    void init();

    int lineNumber;
    std::string spritePath;
    std::vector<Entity *> enemyEntities;
};

#endif
