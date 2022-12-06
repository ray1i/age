#include <ncurses.h>
#include <string>
#include "view.h"
#include "state.h"
#include "entity.h"
#include "entityform.h"

using std::string;

namespace cs246e {
    View::View(): rows{22}, cols{80} {}
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
        clear();
        drawBorders();
        drawState(state);
        // getch();
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
    void View::drawEntity(const Entity *e) {
        const EntityForm currForm = e->getCurrForm();
        for (auto c: currForm.theForm) {
            mvwaddch(stdscr, c.y, c.x, c.sprite);
            // string s = "" + std::to_string(c.x) + std::to_string(c.y);
            // mvprintw(27, 0, s.c_str());
        }
    }
    void View::drawStatuses(const string s1, const string s2, const string s3) {
        // print statuses:
        mvprintw(rows, 0, s1.c_str());
        mvprintw(rows + 1, 0, s2.c_str());
        mvprintw(rows + 2, 0, s3.c_str());
    }
    void View::drawState(const State &state) {
        for (auto e: state.entities) drawEntity(e);
        drawStatuses(state.status1, state.status2, state.status3);
    }
}