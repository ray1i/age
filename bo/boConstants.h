#ifndef __ARLG_CONSTANTS_H
#define __ARLG_CONSTANTS_H

#define PADDLEWIDTH 7

enum GameState {
    BLOCKDESTROYED,
    BALLGAINED,
    BALLLOST,
    WON,
    LOST
};

enum EntityType {
    PADDLE,
    BALL,
    BLOCK,
    POWERUP
};

enum Direction {
    NONE,
    UP,
    LEFT,
    DOWN,
    RIGHT
};

#endif
