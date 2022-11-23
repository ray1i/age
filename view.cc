#include <ncurses.h>
#include "view.h"
#include "state.h"

namespace cs246e {
    View::View(): rows{25}, cols{80} {}
    View::~View() {
        endwin();
    }
    void View::initDraw() {
        // setlocale(LC_ALL, "");
        initscr();
        // noecho();
        // keypad(stdscr, TRUE);
        // curs_set(0);
    }
    void View::drawAll(const State &state) {
        refresh();
        drawBorders();
        drawState(state);
        getch();
    }
    void View::drawBorders() {
        // draw corners:
        mvwaddch(stdscr, 0, 0, '+');
        mvwaddch(stdscr, 0, cols - 1, '+');
        mvwaddch(stdscr, rows - 1, 0, '+');
        mvwaddch(stdscr, rows - 1, cols - 1, '+');
        // draw top and bottom
        for (int i = 1; i < cols - 1; ++i) {
            mvwaddch(stdscr, 0, i, '-');
            mvwaddch(stdscr, rows - 1, i, '-');
        }
        // draw left and right:
        for (int i = 1; i < rows - 1; ++i) {
            mvwaddch(stdscr, i, 0, '|');
            mvwaddch(stdscr, i, cols - 1, '|');
        }
    }
    void View::drawState(const State &state) {
        mvprintw(rows, 0, state.status1.c_str());
        mvprintw(rows + 1, 0, state.status2.c_str());
        mvprintw(rows + 2, 0, state.status3.c_str());
    }
}