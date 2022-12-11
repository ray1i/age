#include <iostream>
#include <cstdlib>
#include "arlgModel.h"
#include "entities/player.h"
#include "entities/fire.h"
#include "entities/walker.h"

void ArlgModel::customInit() {
    // determine which level to start at:
    std::string startLevel;
    std::cout << "Which level to start at? ";
    std::cin >> startLevel;
    if (0 < std::stoi(startLevel) && std::stoi(startLevel) <= 6)
        level = std::stoi(startLevel);
    
    newLevel();
}

void ArlgModel::newLevel() {
    clearEntities();

    const int filledRows = (ROWS - 2) / 4; // should be 5?
    const int filledCols = (COLUMNS - 2) / 4; // should be 19
    bool filled[filledRows][filledCols] = {{false}};

    size_t x;
    size_t y;

    srand(time(NULL));

    // spawn player:
    x = rand() % filledCols;
    y = rand() % filledRows;
    Player *p = new Player(x*4 + 1, y*4 + 1);
    addEntity(p);
    filled[y][x] = true;
    setStatus(0, "Level " + std::to_string(level) + "/6");
    setStatus(1, "Health: 5");

    // spawn exit:
    /*
    x = (rand() % filledCols) * 4;
    y = (rand() % filledRows) * 4;
    filled[y][x] = true;
    */

    // spawn fire:
    for (size_t i = 0; i < level; ++i) {
        while (filled[y][x]) {
            x = rand() % filledCols;
            y = rand() % filledRows;
        }
        addEntity(new Fire(x*4 + 1, y*4 + 1));
        filled[y][x] = true;
    }

    // spawn enemies:
    for (size_t i = 0; i < level + 4; ++i) {
        while (filled[y][x]) {
            x = rand() % filledCols;
            y = rand() % filledRows;
        }
        addEntity(new Walker(x*4 + 1, y*4 + 1, p));
        filled[y][x] = true;
    }
}
