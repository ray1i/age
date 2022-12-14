#include <iostream>
#include <cstdlib>
#include "arlgModel.h"
#include "entities/player.h"
#include "entities/fire.h"
#include "entities/walker.h"
#include "entities/exitLocked.h"
#include "entities/exitUnlocked.h"

void ArlgModel::customInit() {
    // determine which level to start at:
    std::string startLevel;
    std::cout << "Which level to start at? ";
    std::cin >> startLevel;
    if (0 < std::stoi(startLevel) && std::stoi(startLevel) <= 7)
        level = std::stoi(startLevel);
    
    newLevel();
}

void ArlgModel::newLevel() {
    clearEntities();
    remainingEnemies = 0;

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
    while (filled[y][x]) {
        x = rand() % filledCols;
        y = rand() % filledRows;
    }
    ExitLocked *e = new ExitLocked(x*4 + 1, y*4 + 1);
    addEntity(e);
    theExit = e;
    filled[y][x] = true;

    if (level < 7) {
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

            ++remainingEnemies;
        }
    } else {
        while (filled[y][x]) {
            x = rand() % filledCols;
            y = rand() % filledRows;
        }
        addEntity(new Walker(x*4 + 1, y*4 + 1, p));
        filled[y][x] = true;

        ++remainingEnemies;
    }
}

void ArlgModel::notify(int s) {
    switch (s) {
        case ENEMYDESTROYED:
            --remainingEnemies;
            if (remainingEnemies <= 0 && theExit) {
                addEntity(new ExitUnlocked(theExit->getX(), theExit->getY()));
                theExit->markToRemove();
                theExit = nullptr;
            }
            break;
        case NEXTLEVEL:
            ++level;
            if (level > 6) notify(WON);
            else newLevel();
            break;
        case WON:
            setStatus(0, "You Won!");
            setStatus(1, "Made by Ray Li");
            gameRunning = false;
            break;
        case LOST:
            setStatus(0, "You Lost!");
            setStatus(1, "Made by Ray Li");
            gameRunning = false;
            break;
    }
}
