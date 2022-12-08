#include <string>
#include <memory>
#include "engine.h"
#include "view.h"
#include "model.h"
#include "entity.h"
#include "state.h"

namespace cs246e {
    Engine::Engine():
        // theController{std::make_unique<Controller>(new Controller())},
        theModel{std::make_unique<Model>()},
        theView{std::make_unique<View>()} {}

    void Engine::init() {
        theView->initDraw();
    }

    // TODO:
    // void Engine::go() {
    //     init();
    // }
    
    void Engine::addEntity(const Entity &e) { theModel->addEntity(e); }

    void Engine::update() {
        // TODO: take controller input
        theModel->update();
        theView->drawAll(theModel->getState());
    }
}