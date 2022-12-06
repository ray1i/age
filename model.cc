#include <memory>
#include <vector>
#include <string>
#include "model.h"
#include "state.h"
#include "entity.h"

namespace cs246e {
    const State Model::getState() { return State{entities, status1, status2, status3}; }

    // void Model::addEntity(const Entity &e) { entities.push_back(make_unique<Entity>(e)); }
    void Model::addEntity(const Entity &e) { entities.push_back(new Entity(e)); }

    void Model::removeEntity(Entity *e) {
        // for (auto it: entities) {
        for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
            if (e == *it) {
                entities.erase(it); break;
            }
        }
    }

    void Model::update() {
        for (auto e: entities) {
            e->update();
            //REMOVE:
            e->getCurrForm();
        }
    }
}
