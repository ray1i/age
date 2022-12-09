#include <vector>
#include "bullet.h"
#include "../entity.h"
#include "../entityform.h"
#include "../movement.h"
// #include "fire.h"
#include "arlgConstants.h"

// REMOVE:
#include <iostream>
using std::cout;
using std::endl;

Bullet::Bullet(float x, float y, float dirX, float dirY):
    Entity(BULLET, x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, 'O')}, 0, std::vector<Movement>{Movement{dirX, dirY}}) {}

// void Bullet::beCollidedInto(Fire &e) {
//     markToRemove();
//     cout << "big collide" << endl;
// }

void Bullet::collideInto(Entity &e) {
    switch (e.getType()) {
        case FIRE:
            markToRemove();
            cout << "big collide" << endl;
    }
}
