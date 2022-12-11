#include "entityWithHealth.h"
#include "../arlgConstants.h"

EntityWithHealth::EntityWithHealth(int t, float x, float y, int height,
    std::vector<EntityForm> forms, std::vector<Movement> movements,
    int health):
    Entity(t, x, y, height, forms, movements), health{health} {}

void EntityWithHealth::addHealth(int x) {
    health += x;
    if (health <= 0) {
        markToRemove();
        notify(ENEMYDESTROYED);
    }
}

void EntityWithHealth::collideInto(Entity &e) {
    if (e.getType() == BULLET || e.getType() == FIRE) {
        addHealth(-1);
        // downdate();
    }
}