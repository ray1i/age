#ifndef _VIEW_H_
#define _VIEW_H_

#include <string>
#include "state.h"
#include "entity.h"

using std::string;

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
        void drawEntity(const Entity *e);
        void drawStatuses(const string s1, const string s2, const string s3);
        void drawState(const State &state);
    };
}
#endif
