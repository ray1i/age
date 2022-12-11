#ifndef __BULLET_H
#define __BULLET_H

#include "../../age/entity/entity.h"

class Bullet: public cs246e::Entity {
public:
    Bullet(float x, float y, float dirX, float dirY);

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir) override;
};

#endif
