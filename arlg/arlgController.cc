#include "arlgController.h"

ArlgController::ArlgController():
    cs246e::CursesController() {
    mapping[KEY_UP] = Action::MOVE_UP;
    mapping[KEY_LEFT] = Action::MOVE_LEFT;
    mapping[KEY_RIGHT] = Action::MOVE_RIGHT;
    mapping[KEY_DOWN] = Action::MOVE_DOWN;
    mapping['w'] = Action::SHOOT_UP;
    mapping['a'] = Action::SHOOT_LEFT;
    mapping['d'] = Action::SHOOT_RIGHT;
    mapping['s'] = Action::SHOOT_DOWN;
}

int ArlgController::getCurrAction() {
    int n = action();

    if ( mapping.find(n) != mapping.end() ){
        return mapping[n];
    }

    return Action::INVALID;
}
