#ifndef __BLOCK_H
#define __BLOCK_H

#include "../../age/entity/entity.h"

class Block: public cs246e::Entity {
public:
    Block(float x, float y);

    void collideInto(Entity &e) override;
};

#endif
