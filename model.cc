#include <memory>
#include <vector>
#include <string>
#include "model.h"
#include "state.h"
#include "entity.h"

namespace cs246e {
    const State Model::getState() { return State{entities, status1, status2, status3}; }

    // TODO: make this template
    // void Model::addEntity(const Entity &e) { entities.push_back(make_unique<Entity>(e)); }
    void Model::addEntity(const Entity &e) { entities.insert(new Entity(e)); }

    void Model::removeEntity(Entity *e) {
        // for (auto it: entities) {
        // for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        //     if (e == *it) {
        //         entities.erase(it); break;
        //     }
        // }
        entities.erase(e);
    }

    void Model::removeMarkedEntities() {
        for (auto it = entities.begin(); it != entities.end();) {
            if ((*it)->isToRemove()) it = entities.erase(it);
            else ++it;
        }
    }

    void Model::update() {
        removeMarkedEntities();

        for (auto e: entities) {
            e->update();
        }
    }
}
