#include <iostream>
#include <cstdlib>
#include "boModel.h"
#include "entities/paddle.h"
#include "entities/ball.h"
#include "entities/block.h"

void BoModel::customInit() {
    // determine which level to start at:
    std::string startLevel;
    std::cout << "Which level to start at? ";
    std::cin >> startLevel;
    if (0 < std::stoi(startLevel) && std::stoi(startLevel) <= 4)
        level = std::stoi(startLevel);
    
    newLevel();
}

void BoModel::newLevel() {
    clearEntities();
    remainingBlocks = 0;

    setStatus(0, "Level " + std::to_string(level) + "/3");

    addEntity(new Paddle());
    addEntity(new Ball());
    ballsCount = 1;

    if (level == 4) {
        addEntity(new Block(COLUMNS / 2 - 3, 10));
        ++remainingBlocks;
    } else {
        for (size_t y = 5; y < 5 + 4*level; y += 4) {
            for (size_t x = 5; x < COLUMNS - 8; x += 8) {
                addEntity(new Block(x, y));
                ++remainingBlocks;
            }
        }
    }

    setStatus(1, "Remaining Blocks: " + std::to_string(remainingBlocks));
}

void BoModel::notify(int s) {
    switch (s) {
        case BLOCKDESTROYED:
            --remainingBlocks;
            setStatus(1, "Remaining Blocks: " + std::to_string(remainingBlocks));
            if (remainingBlocks <= 0) {
                ++level;
                if (level > 3) notify(WON);
                else newLevel();
            }
            break;
        case BALLGAINED:
            ++ballsCount;
            break;
        case BALLLOST:
            --ballsCount;
            if (ballsCount <= 0) notify(LOST);
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
