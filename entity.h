#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include "cell.h"
#include "entityform.h"
#include "movement.h"

namespace cs246e {
    class Entity {
        int type;
        float x, y;
        int height;
        int timeOffScreen = 0;

        std::vector<EntityForm> forms;
        size_t formIndex;

        std::vector<Movement> movements;

        bool toRemove = false;
    public:
        Entity(int t, float x, float y, int height, std::vector<EntityForm> forms, size_t formIndex, std::vector<Movement> movements);
        virtual ~Entity() {};

        void markToRemove() { toRemove = true; }
        const bool isToRemove() const { return toRemove; }

        const int getType() const { return type; }
        const int getHeight() const { return height; }
        const EntityForm getCurrForm() const;
        const bool collidesWith(const Entity *e) const;
        void addMovement(Movement m);
        void update();
        void downdate(); // opposite of update

        // virtual void beCollidedInto(Entity &e) = 0;
        virtual void collideInto(Entity &e) = 0;
    };
}

#endif
