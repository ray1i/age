#ifndef _CURSE_CONTROLLER_H_
#define _CURSE_CONTROLLER_H_

#include "controller.h"
#include <string>
#include <ncurses.h>

namespace cs246e {
    class CursesController: public Controller {
    protected:
        int action() override;
    public:
        CursesController();
        ~CursesController() {};
    };
}

#endif
