#ifndef __FIRE_H
#define __FIRE_H

#include "../../age/entity/entity.h"

class Bullet;

class Fire: public cs246e::Entity {
public:
    Fire(float x, float y);

    void collideInto(Entity &e) override;
};

#endif
