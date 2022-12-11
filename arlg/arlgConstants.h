#ifndef __ARLG_CONSTANTS_H
#define __ARLG_CONSTANTS_H

enum GameState {
    ENEMYDESTROYED,
    NEXTLEVEL,
    WON,
    LOST
};

enum EntityType {
    PLAYER,
    BULLET,
    FIRE,
    HEALTH,
    EXIT,
    WALKER,
    STALKER,
    POPUP,
    POPUPPROJ,
    SNAKE,
    BOSS
};

enum Direction {
    NONE,
    UP,
    LEFT,
    DOWN,
    RIGHT
};

#endif
