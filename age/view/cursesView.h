#ifndef _CURSESVIEW_H_
#define _CURSESVIEW_H_

#include <string>
#include "view.h"
#include "../state.h"

namespace cs246e {
    class CursesView: public View {
    public:
        ~CursesView();
        CursesView &operator=(CursesView other) = delete;

        void init() override;
        void drawAll(const State &state) override;
    private:
        void refreshView();
        void drawChar(size_t x, size_t y, char c);
        void drawStatus(size_t whichStatus, std::string s);

        void drawBorders();
        void drawEntity(const Entity *e);
        void drawStatuses(const std::string s1, const std::string s2, const std::string s3);
        void drawState(const State &state);
    };
}
#endif
