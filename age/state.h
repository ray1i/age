#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <set>
#include "entity/entity.h"

struct State {
    std::set<cs246e::Entity*> entities;
    std::string status1, status2, status3;
};

#endif
