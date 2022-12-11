#include "health.h"

#include "../arlgConstants.h"

Health::Health(float x, float y):
    Entity(HEALTH, x, y, 0,
    std::vector<EntityForm>({EntityForm('h')}),
    std::vector<Movement>()) {}
        
void Health::collideInto(Entity &e) {
    if (e.getType() != BULLET && e.getType() != FIRE) {
        markToRemove();
    }
}
