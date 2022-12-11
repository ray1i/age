#include "junkController.h"

JunkController::JunkController():
    cs246e::CursesController() {
    mapping[KEY_UP] = Action::MOVE_UP;
    mapping[KEY_LEFT] = Action::MOVE_LEFT;
    mapping[KEY_RIGHT] = Action::MOVE_RIGHT;
}

int JunkController::getCurrAction() {
    int n = action();

    if ( mapping.find(n) != mapping.end() ){
        return mapping[n];
    }

    return Action::INVALID;
}
