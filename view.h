#ifndef _VIEW_H_
#define _VIEW_H_

#include "state.h"

namespace cs246e {
    class View {
        const int rows, cols;
    public:
        View();

        ~View();
        View(View &other) = delete;
        View(View &&other) = delete;
        View &operator=(View other) = delete;

        void initDraw();
        void drawAll(const State &state);
        void drawBorders();
        void drawState(const State &state);
    };
}
#endif
