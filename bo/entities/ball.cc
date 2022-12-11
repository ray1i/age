#include "ball.h"
#include "../boConstants.h"
#include "../../age/constants.h"

Ball::Ball():
    Entity(BALL, COLUMNS / 2, ROWS - 7, 0,
        std::vector<EntityForm>{EntityForm("O")},
        std::vector<Movement>{Movement{0, 0.3}}) {}

void Ball::collideInto(Entity &e) {
    switch (e.getType()) {
        case PADDLE:
            downdate();
            {
                float newSlope = 2*(getX() - e.getX()) / (PADDLEWIDTH - 1) - 1;
                setMovements(std::vector<Movement>{Movement{0.3f*newSlope, -0.3}});
            }
            break;
        case BLOCK:
            // downdate();
            reflectY();
            break;
    }
}

void Ball::collideIntoBorder(BorderDirection dir) {
    switch (dir) {
        case EAST: // fall through
        case WEST:
            downdate();
            reflectX();
            break;
        case NORTH:
            downdate();
            reflectY();
            break;
        case SOUTH:
            notify(BALLLOST);
            break;
    }
}

void Ball::reflectX() {
    setMovements(std::vector<Movement>{Movement{-getMovements()[0].slopeX, getMovements()[0].slopeY}});
}

void Ball::reflectY() {
    setMovements(std::vector<Movement>{Movement{getMovements()[0].slopeX, -getMovements()[0].slopeY}});
}
