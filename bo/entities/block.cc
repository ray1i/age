#include "block.h"
// #include "health.h"
#include "../boConstants.h"
#include <cstdlib>

Block::Block(float x, float y):
    Entity(BLOCK, x, y, 0,
    std::vector<EntityForm>{EntityForm(6, 2, '#')},
    std::vector<Movement>()) {}
        
void Block::collideInto(Entity &e) {
    switch (e.getType()) {
        case BALL:
            markToRemove();
            notify(BLOCKDESTROYED);

            // srand(time(NULL));
            // if (rand() % 2 == 0) {
                // addEntity(new Health(getX(), getY()));
            // }
            break;
    }
}
