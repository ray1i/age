#ifndef _MODEL_H_
#define _MODEL_H_

#include <memory>
#include <set>
#include <string>
#include "state.h"
#include "entity.h"

namespace cs246e {
    class Model {
        std::set<Entity*> entities;
        std::string status1, status2, status3;
    public:
        const State getState();
        void addEntity(const Entity &e);
        void removeEntity(Entity *e);
        void removeMarkedEntities();
        void update(); // TODO: take string arg for controller
    };
}
#endif
