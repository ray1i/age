#ifndef __EXIT_H
#define __EXIT_H

#include "../../age/entity/entity.h"
#include "../junkConstants.h"

class Exit: public cs246e::Entity {
public:
    Exit(float x, float y);

    void collideInto(Entity &e) override {}
};

#endif
