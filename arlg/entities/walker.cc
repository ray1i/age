#include "walker.h"
#include "player.h"


Walker::Walker(float x, float y, Player *p):
    EntityWithHealth(WALKER, x, y, 0,
        std::vector<EntityForm>{EntityForm(2, 2, 'a')},
        std::vector<Movement>(), 3), thePlayer{p} {}

void Walker::update() {
    EntityWithHealth::update();
    if (thePlayer) {
        const float baseSpeed = 0.05;

        float tempX = thePlayer->getX() - getX();
        float tempY = thePlayer->getY() - getY();

        float theX = tempX <= -1 ? -baseSpeed : tempX >= 1 ? 0.05 : 0;
        float theY = tempY <= -1 ? -baseSpeed : tempY >= 1 ? 0.05 : 0;

        setMovements(std::vector<Movement>{Movement{theX, theY}});
    }
}
