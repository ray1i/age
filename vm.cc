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

    Bullet bullet = Bullet(20, 10, 1, 0);
    Fire fire = Fire(40, 10);

    engine.init();
    engine.addEntity(bullet);
    engine.addEntity(fire);
    while (true) {
        engine.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }

    return 0;
}