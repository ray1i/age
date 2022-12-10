#include <vector>
#include "player.h"

#include "arlgActions.h"
#include "arlgConstants.h"
#include "bullet.h"

Player::Player(float x, float y):
    UserControlledEntity(PLAYER, x, y, 0,
    std::vector<EntityForm>{EntityForm("p")}, 0,
    std::vector<Movement>()) {}

void Player::collideInto(Entity &e) {
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
            move(0, -1);
            break;
        case MOVE_LEFT:
            move(-1, 0);
            break;
        case MOVE_DOWN:
            move(0, 1);
            break;
        case MOVE_RIGHT:
            move(1, 0);
            break;
        case SHOOT_UP:
            addEntity(new Bullet(getX(), getY(), 0, -1));
            break;
        case SHOOT_LEFT:
            addEntity(new Bullet(getX(), getY(), -1, 0));
            break;
        case SHOOT_DOWN:
            addEntity(new Bullet(getX(), getY(), 0, 1));
            break;
        case SHOOT_RIGHT:
            addEntity(new Bullet(getX(), getY(), 1, 0));
            break;
    }
}
