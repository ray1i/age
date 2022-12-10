#ifndef __PLAYER_H
#define __PLAYER_H

#include "../age/entity/entity.h"
#include "../age/entity/userControlledEntity.h"

class Player: public cs246e::UserControlledEntity {
public:
    Player(float x, float y);

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir);
    void handleInput(int action) override;
};

#endif
