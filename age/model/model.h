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
        // std::set<std::unique_ptr<Entity>> entities;
        std::set<Entity*> entities;
        std::string status1, status2, status3;

        bool borderCollidable = true;
        Controller *theController = nullptr;
    public:
        const State getState();
        void addEntity(Entity *e);
        void addEntity(UserControlledEntity *e);
        void clearEntities();
        void setStatus(size_t num, std::string s);
        void setBorderCollidable(bool tf) { borderCollidable = tf; }

        void init(Controller *c);
        void update();

    protected:
        int flag;
    public: 
        void setFlag(int f) {flag = f;}
    protected:
        virtual void customUpdate() {};
        virtual void customInit() {}
    private:
        void removeMarkedEntities();
        void updateAllEntities();
        void performEntityCollisions();
    };
}
#endif
