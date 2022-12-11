#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

namespace cs246e {
    class Controller {
    protected:
        virtual int action() = 0;
    public:
        virtual ~Controller() {};
        virtual void init() {};
        virtual int getCurrAction() = 0;
        virtual void awaitOneInput() = 0;
    };
}

#endif
