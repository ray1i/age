#include "exitLocked.h"

ExitLocked::ExitLocked(float x, float y):
    Entity(EXIT, x, y, -1,
    std::vector<EntityForm>({EntityForm('e')}),
    std::vector<Movement>()) {}
