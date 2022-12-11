#ifndef __BALL_H
#define __BALL_H

#include "../../age/entity/entity.h"

class Ball: public cs246e::Entity {
public:
    Ball();

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir) override;
private:
    void reflectX();
    void reflectY();
};

#endif
