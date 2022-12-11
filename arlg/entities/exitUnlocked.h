#ifndef __EXITUNLOCKED_H
#define __EXITUNLOCKED_H

#include "../../age/entity/entity.h"
#include "../arlgConstants.h"

class ExitUnlocked: public cs246e::Entity {
public:
    ExitUnlocked(float x, float y);

    void collideInto(Entity &e) override {}
};

#endif
