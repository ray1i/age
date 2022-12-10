#include "bullet.h"
#include "arlgConstants.h"

Bullet::Bullet(float x, float y, float dirX, float dirY):
    Entity(BULLET, x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, 'O')}, 0, std::vector<Movement>{Movement{dirX, dirY}}) {}

void Bullet::collideInto(Entity &e) {
    switch (e.getType()) {
        case FIRE:
            markToRemove();
            break;
    }
}

void Bullet::collideIntoBorder(BorderDirection dir) {
    markToRemove();
}
