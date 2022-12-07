#include <ncurses.h>
#include <string>
#include "cursesView.h"
#include "view.h"
#include "state.h"
#include "entity.h"
#include "entityform.h"

namespace cs246e {
    CursesView::~CursesView() {
        endwin();
    }

    void CursesView::initDraw() {
        // setlocale(LC_ALL, "");
        initscr();
        // noecho();
        // keypad(stdscr, TRUE);
        // curs_set(0);
    }

    void CursesView::refreshView() {
        refresh();
        clear();
    }

    void CursesView::drawChar(size_t x, size_t y, char c) {
        if (0 <= x && x <= COLS && 0 <= y && y <= ROWS) { mvwaddch(stdscr, y, x, c); }
    }

    // whichStatus is 0, 1, 2
    void CursesView::drawStatus(size_t whichStatus, std::string s) {
        if (0 <= whichStatus && whichStatus <= 2) {
            mvprintw(ROWS + whichStatus, 0, s.c_str());
        }
    }
}
