#include <vector>
#include "../entity.h"
#include "../entityform.h"
#include "../movement.h"

class Fire: public cs246e::Entity {
public:
    Fire(float x, float y):
        Entity(x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, 'x'), EntityForm(0, 0, 'X')}, 0, std::vector<Movement>()) {}
};

