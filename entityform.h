#ifndef _ENTITYFORM_H_
#define _ENTITYFORM_H_

#include <vector>
#include "cell.h"
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
};

#endif
