#include <iostream>
#include <cstdlib>
#include "junkModel.h"
#include "entities/player.h"
#include "entities/exit.h"

void JunkModel::customInit() {
    addEntity(new Player(COLUMNS/2, ROWS/2));
    addEntity(new Exit(4, ROWS - 4));
}
void JunkModel::notify(int s) {
    switch (s) {
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
