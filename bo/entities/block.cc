#include "block.h"
// #include "health.h"
#include "../boConstants.h"
#include <cstdlib>

Block::Block(int type, float x, float y):
    Entity(type, x, y, 0,
    std::vector<EntityForm>{EntityForm(type==BLOCKSIDE ? "#  #\n#  #" : "##")},
    std::vector<Movement>()) {}
        
void Block::collideInto(Entity &e) {
    switch (e.getType()) {
        case BALL:
            markToRemove();
            if (otherBlock) otherBlock->markToRemove();
            notify(BLOCKDESTROYED);

            // srand(time(NULL));
            // if (rand() % 2 == 0) {
                // addEntity(new Health(getX(), getY()));
            // }
            break;
    }
}
