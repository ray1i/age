// #include <ncurses.h>
#include <string>
#include "cursesView.h"
#include "view.h"
#include "state.h"
#include "entity.h"
#include "entityform.h"

namespace cs246e {
    void View::drawAll(const State &state) {
        refreshView();
        drawBorders();
        drawState(state);
    }

    void View::drawBorders() {
        // draw corners:
        drawChar(0, 0, '+');
        drawChar(COLS - 1, 0, '+');
        drawChar(0, ROWS - 1, '+');
        drawChar(COLS - 1, ROWS - 1, '+');
        // draw top and bottom
        for (int i = 1; i < COLS - 1; ++i) {
            drawChar(i, 0, '-');
            drawChar(i, ROWS - 1, '-');
        }
        // draw left and right:
        for (int i = 1; i < ROWS - 1; ++i) {
            drawChar(0, i, '|');
            drawChar(COLS - 1, i, '|');
        }
    }

    void View::drawEntity(const Entity *e) {
        const EntityForm currForm = e->getCurrForm();
        for (auto c: currForm.theForm) {
            drawChar(c.x, c.y, c.sprite);
            // string s = "" + std::to_string(c.x) + std::to_string(c.y);
            // mvprintw(27, 0, s.c_str());
        }
    }
    
    void View::drawStatuses(const std::string s1, const std::string s2, const std::string s3) {
        // print statuses:
        drawStatus(0, s1);
        drawStatus(1, s2);
        drawStatus(2, s3);
    }

    void View::drawState(const State &state) {
        for (auto e: state.entities) drawEntity(e);
        drawStatuses(state.status1, state.status2, state.status3);
    }
}