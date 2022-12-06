#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <vector>
#include "entity.h"

struct State {
    std::vector<cs246e::Entity*> entities;
    std::string status1, status2, status3;
};

#endif
