#include "player.h"

#include "../arlgActions.h"
#include "bullet.h"

Player::Player(float x, float y):
    UserControlledEntity(PLAYER, x, y, 0,
    std::vector<EntityForm>{EntityForm("p")},
    std::vector<Movement>()) {
        setStatus(1, "Health: " + std::to_string(health));
    }

void Player::changeHealth(int x) {
    health += x;
    setStatus(1, "Health: " + std::to_string(health));
}

void Player::collideInto(Entity &e) {
    switch (e.getType()) {
        case FIRE: // fall through
        case WALKER:
        case STALKER:
        case POPUP:
        case POPUPPROJ:
        case SNAKE:
        case BOSS:
            switch (recentDirection) {
                case UP:
                    move(0, 2);
                    break;
                case LEFT:
                    move(2, 0);
                    break;
                case DOWN:
                    move(0, -2);
                    break;
                case RIGHT:
                    move(-2, 0);
                    break;
                default: break;
            }
            changeHealth(-1);
            break;
        case HEALTH:
            changeHealth(1);
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
            move(0, -1);
            recentDirection = UP;
            break;
        case MOVE_LEFT:
            move(-1, 0);
            recentDirection = LEFT;
            break;
        case MOVE_DOWN:
            move(0, 1);
            recentDirection = DOWN;
            break;
        case MOVE_RIGHT:
            move(1, 0);
            recentDirection = RIGHT;
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
