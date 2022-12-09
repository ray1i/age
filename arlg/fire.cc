#include <vector>
#include "fire.h"
#include "../entity.h"
#include "../entityform.h"
#include "../movement.h"

#include "arlgConstants.h"

Fire::Fire(float x, float y):
    Entity(FIRE, x, y, 0, std::vector<EntityForm>{EntityForm(0, 0, 'x'), EntityForm(0, 0, 'X')}, 0, std::vector<Movement>()) {}
