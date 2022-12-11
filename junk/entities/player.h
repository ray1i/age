#ifndef __PLAYER_H
#define __PLAYER_H

#include "../../age/entity/userControlledEntity.h"
#include "../junkConstants.h"

class Player: public cs246e::UserControlledEntity {
    Direction recentDirection = NONE;
public:
    Player(float x, float y);

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir) override;
    void handleInput(int action) override;
};

#endif
