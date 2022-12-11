#include "player.h"

#include "../junkActions.h"

Player::Player(float x, float y):
    UserControlledEntity(PLAYER, x, y, 0,
    std::vector<EntityForm>{EntityForm("o\n^"), EntityForm(" O \n/ \\"), EntityForm("O\n|")},
    std::vector<Movement>{Movement{0, 0.2}}) {}

void Player::collideInto(Entity &e) {
    switch (e.getType()) {
        case EXIT:
            notify(WON);
            break;
    }
}

void Player::collideIntoBorder(BorderDirection dir) {
    switch (dir) {
        case NORTH:
            move(0, 1);
            break;
        case EAST:
            move(-1, 0);
            break;
        case SOUTH:
            move(0, -1);
            break;
        case WEST:
            move(1, 0);
            break;
    }
}

void Player::handleInput(int action) {
    switch (action) {
        case MOVE_UP:
            move(0, -2);
            recentDirection = UP;
            break;
        case MOVE_LEFT:
            move(-1, 0);
            recentDirection = LEFT;
            break;
        case MOVE_RIGHT:
            move(1, 0);
            recentDirection = RIGHT;
            break;
    }
}
