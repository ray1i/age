#ifndef _MODEL_H_
#define _MODEL_H_

#include <memory>
#include <set>
#include <string>
#include "../state.h"
#include "../entity/entity.h"
#include "../entity/userControlledEntity.h"

namespace cs246e {
    class Controller;

    class Model {
        std::set<Entity*> entities;
        std::string status1, status2, status3;

        bool borderCollidable = true;
        Controller *theController = nullptr;
    public:
        virtual ~Model();

        const State getState();
        void addEntity(Entity *e);
        void addEntity(UserControlledEntity *e);
        void clearEntities();
        void setStatus(size_t num, std::string s);
        void setBorderCollidable(bool tf) { borderCollidable = tf; }

        void init(Controller *c);
        bool update(); // returns if we should stop or not

        virtual void notify(int s) = 0;
    protected:
        virtual bool customUpdate() {return true;};
        virtual void customInit() {}
    private:
        void removeMarkedEntities();
        void updateAllEntities();
        void performEntityCollisions();
    };
}
#endif
