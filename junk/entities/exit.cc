#include "exit.h"

Exit::Exit(float x, float y):
    Entity(EXIT, x, y, 0,
    std::vector<EntityForm>({EntityForm("++\n||\n++")}),
    std::vector<Movement>()) {}
