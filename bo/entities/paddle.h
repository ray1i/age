#ifndef __PADDLE_H
#define __PADDLE_H

#include "../../age/entity/userControlledEntity.h"
#include "../boConstants.h"

class Paddle: public cs246e::UserControlledEntity {
public:
    Paddle();

    void collideInto(Entity &e) override;
    void collideIntoBorder(BorderDirection dir) override;
    void handleInput(int action) override;
};

#endif
