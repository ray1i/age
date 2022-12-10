#ifndef _VIEW_H_
#define _VIEW_H_

#include <string>
#include "../state.h"

namespace cs246e {
    class View {
    public:
        virtual ~View();

        virtual void init() = 0;
        virtual void drawAll(const State &state) = 0;
    };
}
#endif
