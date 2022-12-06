#include <vector>
#include "entity.h"
#include "cell.h"
#include "entityform.h"
#include "movement.h"

// REMOVE:
#include <iostream>
using std::cout;
using std::endl;

namespace cs246e {
    Entity::Entity(float x, float y, int height, std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements):
        x{x}, y{y}, height{height}, timeOffScreen{0}, forms{forms}, formIndex{formIndex}, movements{movements} {}

    const EntityForm Entity::getCurrForm() const {
        EntityForm form = EntityForm(forms[formIndex].theForm);
        form.move(x, y);
        return form;
    }
    void Entity::update() {
        for (auto m: movements) {
            x += m.slopeX;
            y += m.slopeY;
        }
    }
}