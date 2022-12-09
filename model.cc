#include <memory>
#include <string>
#include "model.h"
#include "state.h"
#include "entity.h"
#include "constants.h"

namespace cs246e {
    const State Model::getState() {
        return State{entities, status1, status2, status3};
    }

    // TODO: make this template
    // void Model::addEntity(const Entity &e) { entities.push_back(make_unique<Entity>(e)); }
    void Model::addEntity(Entity *e) { entities.insert(e); }

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

    void Model::updateAllEntities() {
        for (auto e: entities) {
            e->update();
        }
    }

    // CURRENTLY DOESN'T CHECK OUTSIDE BOUNDS
    void Model::performEntityCollisions() {
        for (auto &e: entities) {
            for (auto &eToCheck: entities) {
                if (e->collidesWith(eToCheck)) {
                    e->collideInto(*eToCheck);
                }
            }
        }
    }

    void Model::update() {
        removeMarkedEntities();
        updateAllEntities();
        performEntityCollisions();
    }
}
