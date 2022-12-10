#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <memory>

// for TIMER:
#include <chrono>
#include <thread>

#include "constants.h"
#include "model/model.h"
#include "controller/controller.h"
#include "view/view.h"

namespace cs246e {
    template<typename ControllerType, typename ModelType, typename ViewType> class Engine {
        static_assert(std::is_base_of<Controller, ControllerType>::value);
        static_assert(std::is_base_of<Model, ModelType>::value);
        static_assert(std::is_base_of<View, ViewType>::value);

        std::unique_ptr<ControllerType> theController;
        std::unique_ptr<ModelType> theModel;
        std::unique_ptr<ViewType> theView;

        bool gameRunning = false;
    public:
        Engine():
            theController{std::make_unique<ControllerType>()},
            theModel{std::make_unique<ModelType>()},
            theView{std::make_unique<ViewType>()} {}

        void go() {
            init();
            while (gameRunning) {
                update();
                std::this_thread::sleep_for(std::chrono::milliseconds(TICKLENGTH));
            }
        }

        void stop() {gameRunning = false;}
    private:
        void init() {
            theModel->init(theController.get());
            theView->init();
            gameRunning = true;
        }
        
        void update() {
            theModel->update();
            theView->drawAll(theModel->getState());
        }
    };
}

#endif
