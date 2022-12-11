#ifndef __JUNK_CONTROLLER_H
#define __JUNK_CONTROLLER_H

#include <map>
#include "../age/controller/cursesController.h"
#include "junkActions.h"

class JunkController: public cs246e::CursesController {
    std::map<int, Action> mapping; 
public:
    JunkController();
    int getCurrAction() override;
};

#endif 
