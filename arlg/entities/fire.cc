#include "fire.h"
#include "health.h"
#include "../arlgConstants.h"
#include <cstdlib>

Fire::Fire(float x, float y):
    Entity(FIRE, x, y, 0,
    std::vector<EntityForm>({EntityForm('x'), EntityForm('X')}),
    std::vector<Movement>()) {}
        
void Fire::collideInto(Entity &e) {
    switch (e.getType()) {
        case BULLET:
            markToRemove();
            srand(time(NULL));
            if (rand() % 2 == 0) {
                addEntity(new Health(getX(), getY()));
            }
            break;
    }
}
