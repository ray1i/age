#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

namespace cs246e {
    class Controller {
    protected:
        virtual int action() = 0;
    public:
        ~Controller() {};
        virtual int getCurrAction() = 0;
    };
}

#endif
