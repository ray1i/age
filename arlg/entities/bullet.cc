#include "bullet.h"
#include "../arlgConstants.h"

Bullet::Bullet(float x, float y, float dirX, float dirY):
    Entity(BULLET, x, y, 0,
        std::vector<EntityForm>{EntityForm("O")},
        std::vector<Movement>{Movement{dirX, dirY}}) {}

void Bullet::collideInto(Entity &e) {
    markToRemove();
}

void Bullet::collideIntoBorder(BorderDirection dir) {
    markToRemove();
}
