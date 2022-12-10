#include "userControlledEntity.h"

namespace cs246e {
    UserControlledEntity::UserControlledEntity(int t, float x, float y, int height,
        std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements):
        Entity(t, x, y, height, forms, formIndex, movements) {}
    
    void UserControlledEntity::addController(Controller *c) {
        theController = c;
    }
    
    void UserControlledEntity::update() {
        handleInput(theController->getCurrAction());
        updateForm();
        updatePosition();
    }
}

