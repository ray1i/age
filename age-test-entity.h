#include <vector>
#include "entity.h"
#include "entityform.h"
#include "movement.h"

class MovesRightEntity: public cs246e::Entity {
public:
    MovesRightEntity(float x, float y):
        Entity(x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, '#')}, 0, std::vector<Movement>{Movement{1, 0}}) {}
};
