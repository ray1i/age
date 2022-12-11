#ifndef __EXITLOCKED_H
#define __EXITLOCKED_H

#include "../../age/entity/entity.h"
#include "../arlgConstants.h"

class ExitLocked: public cs246e::Entity {
public:
    ExitLocked(float x, float y);

    void collideInto(Entity &e) override {}
};

#endif
