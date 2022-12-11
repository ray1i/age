#ifndef __BLOCK_H
#define __BLOCK_H

#include "../../age/entity/entity.h"

class Block: public cs246e::Entity {
    Block *otherBlock = nullptr;
public:
    Block(int type, float x, float y);

    void collideInto(Entity &e) override;

    void assignOther(Block *other) {otherBlock = other;}
};

#endif
