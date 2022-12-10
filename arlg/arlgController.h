#ifndef __ARLG_CONTROLLER_H
#define __ARLG_CONTROLLER_H

#include <map>
#include <string>
#include "../age/controller/cursesController.h"
#include "arlgActions.h"

class ArlgController: public cs246e::CursesController {
    std::map<int, Action> mapping; 
public:
    ArlgController();
    int getCurrAction() override;
};

#endif 
