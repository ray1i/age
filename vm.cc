#include <iostream>
#include "engine.h"

#include "arlg/bullet.h"
#include "arlg/fire.h"
// TEMP:
#include <chrono>
#include <thread>

int main() {
    const int interval = 1000 / 20; // 1000 ms / 20 frames

    cs246e::Engine engine = cs246e::Engine();


    engine.init();
    engine.addEntity(new Bullet(20, 10, 1, 0));
    engine.addEntity(new Fire(40, 10));
    while (true) {
        engine.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }

    return 0;
}