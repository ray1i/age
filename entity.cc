#include <vector>
#include "entity.h"
#include "cell.h"
#include "entityform.h"
#include "movement.h"
#include "constants.h"

// REMOVE:
#include <iostream>
using std::cout;
using std::endl;

namespace cs246e {
    Entity::Entity(float x, float y, int height, std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements):
        x{x}, y{y}, height{height}, forms{forms}, formIndex{formIndex}, movements{movements} {}

    const EntityForm Entity::getCurrForm() const {
        EntityForm form = EntityForm(forms[formIndex].theForm);
        form.move(x, y);
        return form;
    }

    void Entity::update() {
        // update entity form
        ++formIndex;
        if (formIndex >= forms.size()) formIndex = 0;

        // update entity position
        for (auto m: movements) {
            x += m.slopeX;
            y += m.slopeY;
        }

        // check if entity if offscreen
        if (getCurrForm().offScreen()) ++timeOffScreen;
        if (timeOffScreen > MAXTICKSOFFSCREEN) markToRemove();
    }
}
