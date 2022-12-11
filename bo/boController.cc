#include "boController.h"

BoController::BoController():
    cs246e::CursesController() {
    mapping[KEY_LEFT] = Action::MOVE_LEFT;
    mapping[KEY_RIGHT] = Action::MOVE_RIGHT;
}

int BoController::getCurrAction() {
    int n = action();

    if ( mapping.find(n) != mapping.end() ){
        return mapping[n];
    }

    return Action::INVALID;
}
