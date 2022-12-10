#include <iostream>
#include "age/engine.h"
#include "age/view/cursesView.h"

#include "arlg/arlgController.h"
#include "arlg/arlgModel.h"
#include "arlg/player.h"
#include "arlg/fire.h"

int main() {

    cs246e::Engine<ArlgController, ArlgModel, cs246e::CursesView>
        engine = cs246e::Engine<ArlgController, ArlgModel, cs246e::CursesView>();

    // engine.init();
    // engine.addEntity(new Player(10, 10));
    // // engine.addEntity(new Bullet(20, 10, 1, 0));
    // engine.addEntity(new Fire(40, 10));
    // while (true) {
    //     engine.update();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    // }
    engine.go();

    return 0;
}