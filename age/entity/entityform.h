#ifndef _ENTITYFORM_H_
#define _ENTITYFORM_H_

#include <vector>
#include <string>
#include "cell.h"
#include "../constants.h"
#include "../border.h"

struct EntityForm {
    std::vector<Cell> theForm;

    // single character
    EntityForm(char c): theForm{std::vector<Cell>({Cell{0, 0, c}})} {}

    // bitmap
    EntityForm(std::string sprite): theForm{std::vector<Cell>()} {
        int x = 0;
        int y = 0;
        for (const auto &c: sprite) {
            if (c == ' ') ++x;
            else if (c == '\n') {
                ++y;
                x = 0;
            } else {
                theForm.push_back(Cell{x, y, c});
                ++x;
            }
        }
    }

    // rectangle
    EntityForm(int width, int height, char c): theForm{std::vector<Cell>()} {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                theForm.push_back(Cell{x, y, c});
            }
        }
    }

    // EntityForm(std::vector<Cell> forms): theForm{forms} {}
    // EntityForm(Cell c): theForm{std::vector<Cell>{c}} {}
    // EntityForm(int x, int y, char c): theForm{std::vector<Cell>{Cell{x, y, c}}} {}

    void move(float x, float y) {
        for (auto &c: theForm) {
            c.x += x;
            c.y += y;
        }
    }

    bool offScreen() const { // check if entity is COMPLETELY offscreen
        for (auto c: theForm) {
            if ((0 <= c.x && c.x < COLUMNS) && (0 <= c.y && c.y < ROWS)) {
                return false;
            }
        }
        return true;
    }

    bool collidesWithBorder(const BorderDirection dir) const {
        for (auto c: theForm) {
            if ((c.y == 0 && dir == NORTH) ||
                (c.x == COLUMNS - 1 && dir == EAST) ||
                (c.y == ROWS - 1 && dir == SOUTH) ||
                (c.x == 0 && dir == WEST)){
                    return true;
                }
        }
        return false;
    }

    // TODO: add iterator?
};

#endif
