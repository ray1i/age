#include <iostream>
#include "engine.h"

#include "age-test-entity.h"

// TEMP:
#include <chrono>
#include <thread>

int main() {
    const int interval = 1000 / 20; // 1000 ms / 20 frames

    cs246e::Engine engine = cs246e::Engine();

    MovesRightEntity testEntity = MovesRightEntity(20, 10);

    engine.init();
    engine.addEntity(testEntity);
    while (true) {
        engine.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }

    return 0;
}