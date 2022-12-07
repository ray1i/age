#include <vector>
#include "../entity.h"
#include "../entityform.h"
#include "../movement.h"

class Bullet: public cs246e::Entity {
public:
    Bullet(float x, float y, float dirX, float dirY):
        Entity(x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, 'O')}, 0, std::vector<Movement>{Movement{dirX, dirY}}) {}
};

