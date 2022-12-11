#ifndef __BO_CONTROLLER_H
#define __BO_CONTROLLER_H

#include <map>
#include "../age/controller/cursesController.h"
#include "boActions.h"

class BoController: public cs246e::CursesController {
    std::map<int, Action> mapping; 
public:
    BoController();
    int getCurrAction() override;
};

#endif 
