#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <memory>
#include "view.h"

namespace cs246e {
    class Engine {
        // std::unique_ptr<Controller> theController;
        // std::unique_ptr<Model> theModel;
        std::unique_ptr<View> theView;
    public:
        Engine();

        void start();
    private:
        void update();
    };
}
#endif
