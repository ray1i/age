#include "cursesController.h"

namespace cs246e {
    CursesController::CursesController() {
        setlocale(LC_ALL, "");
        nodelay(stdscr, true);
    }

    int CursesController::action() {
        return getch();
    }
}
