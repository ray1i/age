#ifndef __BULLET_H
#define __BULLET_H

#include "../entity.h"

class Fire;

class Bullet: public cs246e::Entity {
public:
    Bullet(float x, float y, float dirX, float dirY);

    // void beCollidedWith(Fire &e);
    void collideInto(Entity &e) override;
};

#endif
