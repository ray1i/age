#ifndef __PLAYER_H
#define __PLAYER_H

#include "../../age/entity/userControlledEntity.h"
#include "../arlgConstants.h"

class Player: public cs246e::UserControlledEntity {
    int health = 5;
    Direction recentDirection = NONE;
public:
    Player(float x, float y);

    void changeHealth(int x);

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir) override;
    void handleInput(int action) override;
};

#endif
