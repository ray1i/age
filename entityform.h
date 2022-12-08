#ifndef _ENTITYFORM_H_
#define _ENTITYFORM_H_

#include <vector>
#include "cell.h"
#include "constants.h"
// TODO: use initializer list

// REMOVE:
#include <iostream>
using std::cout;
using std::endl;

struct EntityForm {
    std::vector<Cell> theForm;

    EntityForm(std::vector<Cell> forms): theForm{forms} {}
    EntityForm(Cell c): theForm{std::vector<Cell>{c}} {}
    EntityForm(int x, int y, char c): theForm{std::vector<Cell>{Cell{x, y, c}}} {}

    void move(float x, float y) {
        for (auto &c: theForm) {
            c.x += x;
            c.y += y;
        }
    }

    bool offScreen() const { // check if entity is COMPLETELY offscreen
        for (auto c: theForm) {
            if ((0 <= c.x && c.x < COLS) && (0 <= c.y && c.y < ROWS)) {
                return false;
            }
        }
        return true;
    }
};

#endif
