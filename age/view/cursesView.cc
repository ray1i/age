#include <ncurses.h>
#include "cursesView.h"
#include "../entity/entityform.h"

namespace cs246e {
    void CursesView::init() {
        initscr();
        keypad(stdscr, TRUE);
        curs_set(0);
        setlocale(LC_ALL, "");
        nodelay(stdscr, true);
        noecho();
    }
    
    void CursesView::end() {
        endwin();
    }

    void CursesView::drawAll(const State &state) {
        refreshView();
        drawBorders();
        drawState(state);
    }

    void CursesView::refreshView() {
        refresh();
        clear();
    }

    void CursesView::drawChar(size_t x, size_t y, char c) {
        if (0 <= x && x <= COLUMNS && 0 <= y && y <= ROWS) {
            mvwaddch(stdscr, y, x, c);
        }
    }

    // whichStatus is 0, 1, 2
    void CursesView::drawStatus(size_t whichStatus, std::string s) {
        if (0 <= whichStatus && whichStatus <= 2) {
            mvprintw(ROWS + whichStatus, 0, s.c_str());
        }
    }

    // HELPER:
    void CursesView::drawBorders() {
        // draw corners:
        drawChar(0, 0, '+');
        drawChar(COLUMNS - 1, 0, '+');
        drawChar(0, ROWS - 1, '+');
        drawChar(COLUMNS - 1, ROWS - 1, '+');
        // draw top and bottom
        for (int i = 1; i < COLUMNS - 1; ++i) {
            drawChar(i, 0, '-');
            drawChar(i, ROWS - 1, '-');
        }
        // draw left and right:
        for (int i = 1; i < ROWS - 1; ++i) {
            drawChar(0, i, '|');
            drawChar(COLUMNS - 1, i, '|');
        }
    }

    void CursesView::drawEntity(const Entity *e) {
        const EntityForm currForm = e->getCurrForm();
        for (const auto &c: currForm.theForm) {
            drawChar(c.x, c.y, c.sprite);
        }
    }

    void CursesView::drawStatuses(const std::string s1, const std::string s2, const std::string s3) {
        // print statuses:
        drawStatus(0, s1);
        drawStatus(1, s2);
        drawStatus(2, s3);
    }

    void CursesView::drawState(const State &state) {
        for (auto e: state.entities) drawEntity(e);
        drawStatuses(state.status1, state.status2, state.status3);
    }
}
