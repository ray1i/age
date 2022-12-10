#include <vector>
#include "../model/model.h"
#include "entity.h"
#include "../constants.h"

namespace cs246e {
    Entity::Entity(int t, float x, float y, int height,
        std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements):
        type{t}, x{x}, y{y}, height{height},
        forms{forms}, formIndex{formIndex}, movements{movements} {}

    const EntityForm Entity::getCurrForm() const {
        EntityForm form = EntityForm(forms[formIndex].theForm);
        form.move(x, y);
        return form;
    }

    void Entity::move(float dx, float dy) {
        x += dx;
        y += dy;
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

    void Entity::updateForm() {
        // update entity form
        ++formIndex;
        if (formIndex >= forms.size()) formIndex = 0;
    }

    void Entity::updatePosition() {
        // update entity position
        for (auto m: movements) {
            x += m.slopeX;
            y += m.slopeY;
        }

        // check if entity if offscreen
        if (getCurrForm().offScreen()) ++timeOffScreen;
        else timeOffScreen = 0;

        if (timeOffScreen > MAXTICKSOFFSCREEN) markToRemove();
    }

    void Entity::update() {
        updateForm();
        updatePosition();
    }

    void Entity::downdateForm() {
        // update entity form
        --formIndex;
        if (formIndex < 0) formIndex = forms.size() - 1;
   }

    void Entity::downdatePosition() {
        // update entity position
        for (auto m: movements) {
            x -= m.slopeX;
            y -= m.slopeY;
        }

        // check if entity if offscreen
        if (!getCurrForm().offScreen()) timeOffScreen = 0;
        if (timeOffScreen <= MAXTICKSOFFSCREEN) toRemove = false; // replace with ..
    }


    void Entity::downdate() {
        downdateForm();
        downdatePosition();
    }

    void Entity::addEntity(Entity *e) {
        if (theModel) theModel->addEntity(e);
    }

    // by default, border blocks movement.
    void Entity::collideIntoBorder(BorderDirection dir) {
        switch (dir) {
            case NORTH:
                move(0, 1);
                break;
            case EAST:
                move(-1, 0);
                break;
            case SOUTH:
                move(0, -1);
                break;
            case WEST:
                move(1, 0);
                break;
        }
    }
}
