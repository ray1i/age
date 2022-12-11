#ifndef __HEALTH_H
#define __HEALTH_H

#include "../../age/entity/entity.h"

class Health: public cs246e::Entity {
public:
    Health(float x, float y);

    void collideInto(Entity &e) override;
};

#endif
