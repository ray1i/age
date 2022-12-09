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
    Entity::Entity(int t, float x, float y, int height, std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements):
        type{t}, x{x}, y{y}, height{height},
        forms{forms}, formIndex{formIndex}, movements{movements} {}

    const EntityForm Entity::getCurrForm() const {
        EntityForm form = EntityForm(forms[formIndex].theForm);
        form.move(x, y);
        return form;
    }

    const bool Entity::collidesWith(const Entity *e) const {
        if (this == e) return false;
        if (e->getHeight() != height) return false;
        for (const auto &myCell: getCurrForm().theForm) {
            for (const auto &otherCell: e->getCurrForm().theForm) {
                if (myCell.x == otherCell.x && myCell.y == otherCell.y) {
                    return true;
                }
            }
        }
        return false;
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

    void Entity::downdate() {
        const bool previouslyOffScreen = getCurrForm().offScreen();
        
        // update entity form
        --formIndex;
        if (formIndex < 0) formIndex = forms.size() - 1;

        // update entity position
        for (auto m: movements) {
            x -= m.slopeX;
            y -= m.slopeY;
        }

        // check if entity if offscreen
        if (previouslyOffScreen && !getCurrForm().offScreen()) --timeOffScreen;
        if (timeOffScreen <= MAXTICKSOFFSCREEN) toRemove = false; // replace with ..
    }
}
