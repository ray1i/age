#ifndef __WALKER_H
#define __WALKER_H

#include "entityWithHealth.h"

class Player;

class Walker: public EntityWithHealth {
    Player *thePlayer;
public:
    Walker(float x, float y, Player *p);

    void update() override;
};

#endif
