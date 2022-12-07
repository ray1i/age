#ifndef _CURSESVIEW_H_
#define _CURSESVIEW_H_

#include <string>

#define ROWS 22
#define COLS 80

namespace cs246e {
    class CursesView {
    public:
        // CursesView();

        virtual ~CursesView();
        // CursesView(const CursesView &other) = delete;
        // CursesView(const CursesView &&other) = delete;
        CursesView &operator=(CursesView other) = delete;

        void initDraw();
    protected:
        void refreshView();
        void drawChar(size_t x, size_t y, char c);
        void drawStatus(size_t whichStatus, std::string s);
    };
}
#endif
