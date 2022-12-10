#include "fire.h"

#include "arlgConstants.h"

Fire::Fire(float x, float y):
    Entity(FIRE, x, y, 0,
    std::vector<EntityForm>({EntityForm('x'), EntityForm('X')}), 0,
    std::vector<Movement>()) {}
        
void Fire::collideInto(Entity &e) {
    switch (e.getType()) {
        case BULLET:
            markToRemove();
            break;
    }
}
