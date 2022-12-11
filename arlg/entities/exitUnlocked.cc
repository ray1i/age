#include "exitUnlocked.h"

ExitUnlocked::ExitUnlocked(float x, float y):
    Entity(EXIT, x, y, 0,
    std::vector<EntityForm>({EntityForm('E')}),
    std::vector<Movement>()) {}
