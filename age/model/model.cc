#include "model.h"
#include "../constants.h"

namespace cs246e {
    Model::~Model() {
        for (auto e: entities) {
            delete e;
        }
    }

    const State Model::getState() {
        return State{entities, status1, status2, status3};
    }

    // TODO: make this template
    void Model::addEntity(Entity *e) {
        entities.insert(e);
        e->assignModel(this);
    }

    void Model::addEntity(UserControlledEntity *e) {
        e->assignController(theController);
        entities.insert(e);
        e->assignModel(this);
    }

    void Model::clearEntities() {
        for (auto &e: entities) {
            e->markToRemove();
        }
    }

    void Model::setStatus(size_t num, std::string s) {
        if (num == 0) status1 = s;
        else if (num == 1) status2 = s;
        else if (num == 2) status3 = s;
    }

    void Model::removeMarkedEntities() {
        for (auto it = entities.begin(); it != entities.end();) {
            if ((*it)->isToRemove()) {
                delete *it;
                it = entities.erase(it);
            }
            else ++it;
        }
    }

    void Model::updateAllEntities() {
        for (auto e: entities) {
            e->update();
        }
    }

    void Model::performEntityCollisions() {
        std::set<Entity*> oldEntities = entities;

        for (auto &e: oldEntities) {
            // check collision with border
            if (borderCollidable) {
                EntityForm f = e->getCurrForm();
                if (f.collidesWithBorder(NORTH)) e->collideIntoBorder(NORTH);
                if (f.collidesWithBorder(EAST)) e->collideIntoBorder(EAST);
                if (f.collidesWithBorder(SOUTH)) e->collideIntoBorder(SOUTH);
                if (f.collidesWithBorder(WEST)) e->collideIntoBorder(WEST);
            }
            
            // check collisions with other entities
            for (auto &eToCheck: oldEntities) {
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

    bool Model::update() {
        removeMarkedEntities();
        updateAllEntities();
        performEntityCollisions();
        return customUpdate();
    }
}
