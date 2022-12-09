#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <memory>
#include "view.h"
#include "model.h"
#include "entity.h"

namespace cs246e {
    class Engine {
        // std::unique_ptr<Controller> theController;
        std::unique_ptr<Model> theModel;
        std::unique_ptr<View> theView;
    public:
        Engine();
        // Engine &operator=(const Engine) = delete;

        void init();
        // TODO:
        // void go();

        void addEntity(Entity *e);
    // private:
        void update();
    };
}
#endif
