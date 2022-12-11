#include "cursesController.h"

//REMOV
#include <iostream>

namespace cs246e {
    CursesController::CursesController():
        Controller() {}

    void CursesController::init() {
        setlocale(LC_ALL, "");
        nodelay(stdscr, true);
    }

    int CursesController::action() {
        return getch();
    }
    void CursesController::awaitOneInput() {
        nodelay(stdscr, false);
        getch();
    }
}
