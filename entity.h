#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include "cell.h"
#include "entityform.h"
#include "movement.h"

namespace cs246e {
    class Entity {
        float x, y;
        int height;
        int timeOffScreen = 0;

        std::vector<EntityForm> forms;
        size_t formIndex;

        std::vector<Movement> movements;

        bool toRemove = false;
    public:
        Entity(float x, float y, int height, std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements);
        virtual ~Entity() {};

        void markToRemove() { toRemove = true; }
        const bool isToRemove() const { return toRemove; }

        const EntityForm getCurrForm() const;
        void addMovement(Movement m);
        void update();
    };
}

#endif
