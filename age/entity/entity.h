#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include "cell.h"
#include "entityform.h"
#include "movement.h"
#include "../border.h"

namespace cs246e {
    class Model;

    class Entity {
        int type;
        float x, y;
        int height;
        int timeOffScreen = 0;

        const std::vector<EntityForm> forms;
        size_t formIndex;

        std::vector<Movement> movements;

        bool toRemove = false;

        Model *theModel = nullptr;
    public:
        Entity(int t, float x, float y, int height,
            std::vector<EntityForm> forms, std::vector<Movement> movements);
        virtual ~Entity() {};

        // getters:
        const int getType() const { return type; }
        const float getX() const { return x; }
        const float getY() const { return y; }
        const int getHeight() const { return height; }
        const EntityForm getCurrForm() const;
        const bool isToRemove() const { return toRemove; }

        // setters:
        void move(float x, float y);
        void setMovement(std::vector<Movement> newMovements) {movements = newMovements;}
        void assignModel(Model *m) { theModel = m; }
        void markToRemove() { toRemove = true; }

        const bool collidesWith(const Entity *e) const;

        virtual void update();
        virtual void downdate(); // opposite of update

        virtual void collideInto(Entity &e) = 0;
        virtual void collideIntoBorder(BorderDirection dir);
    protected:
        void updateForm();
        void updatePosition();
        void downdateForm();
        void downdatePosition();
        void addEntity(Entity *e);
        void setStatus(size_t num, std::string s);
        void setModelFlag(int f);
    };
}

#endif
