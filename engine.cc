#include <string>
#include <memory>
#include "engine.h"
#include "view.h"
#include "state.h"

namespace cs246e {
    Engine::Engine():
        // theController{make_unique<Controller>(new Controller())},
        // theModel{make_unique<Model>(new Model())},
        theView{std::make_unique<View>()} {}

    void Engine::start() {
        theView->initDraw();
        State s = State{"asdf", "dd", "f"};
        theView->drawAll(s);
    }
}