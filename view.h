#ifndef _VIEW_H_
#define _VIEW_H_

#include <string>
#include "cursesView.h"
#include "state.h"
#include "entity.h"

namespace cs246e {
    class View: public CursesView {
    public:
        void drawAll(const State &state);
    private:
        void drawBorders();
        void drawEntity(const Entity *e);
        void drawStatuses(const std::string s1, const std::string s2, const std::string s3);
        void drawState(const State &state);
    };
}
#endif
