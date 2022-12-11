#ifndef _USERCONTROLLED_ENTITY_H_
#define _USERCONTROLLED_ENTITY_H_

#include "entity.h"
#include "../controller/controller.h"

namespace cs246e {
    class UserControlledEntity: public Entity {
        Controller *theController = nullptr;
    public:
        UserControlledEntity(int t, float x, float y, int height,
            std::vector<EntityForm> forms, std::vector<Movement> movements);
        virtual ~UserControlledEntity() {};

        void update() override;

        virtual void handleInput(int action) = 0;
        void assignController(Controller *c);
    };
}

#endif

