#include "../../age/constants.h"
#include "paddle.h"
#include "../boActions.h"

Paddle::Paddle():
    UserControlledEntity(PADDLE, COLUMNS / 2 - 3, ROWS - 3, 0,
    std::vector<EntityForm>{EntityForm("=======")},
    std::vector<Movement>()) {}

void Paddle::collideInto(Entity &e) {
    switch (e.getType()) {
        case POWERUP: // fall through
            break;
    }
}

void Paddle::collideIntoBorder(BorderDirection dir) {
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

void Paddle::handleInput(int action) {
    switch (action) {
        case MOVE_LEFT:
            move(-1, 0);
            break;
        case MOVE_RIGHT:
            move(1, 0);
            break;
    }
}
