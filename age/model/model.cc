#include "model.h"
#include "../constants.h"

namespace cs246e {
    const State Model::getState() {
        return State{entities, status1, status2, status3};
    }

    // TODO: make this template
    void Model::addEntity(Entity *e) {
        entities.insert(e);
        e->assignModel(this);
    }

    void Model::addEntity(UserControlledEntity *e) {
        e->addController(theController);
        entities.insert(e);
        e->assignModel(this);
    }

    void Model::setStatus(size_t num, std::string s) {
        if (num == 0) status1 = s;
        else if (num == 1) status2 = s;
        else if (num == 2) status3 = s;
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
            // check collision with border
            if (borderCollidable) {
                if (e->getCurrForm().collidesWithBorder(NORTH)) e->collideIntoBorder(NORTH);
                if (e->getCurrForm().collidesWithBorder(EAST)) e->collideIntoBorder(EAST);
                if (e->getCurrForm().collidesWithBorder(SOUTH)) e->collideIntoBorder(SOUTH);
                if (e->getCurrForm().collidesWithBorder(WEST)) e->collideIntoBorder(WEST);
            }
            
            // check collisions with other entities
            for (auto &eToCheck: entities) {
                if (e->collidesWith(eToCheck)) {
                    e->collideInto(*eToCheck);
                }
            }
        }
    }

    void Model::init(Controller *c) {
        theController = c;
        customInit();
    }

    void Model::update() {
        removeMarkedEntities();
        updateAllEntities();
        performEntityCollisions();
        customUpdate();
    }
}
