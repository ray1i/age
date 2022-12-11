#ifndef __ARLG_MODEL_H
#define __ARLG_MODEL_H

#include "../age/model/model.h"

class ArlgModel: public cs246e::Model {
    size_t level = 1;

    void customInit() override;
    // void customUpdate() override;
private:
    void newLevel();
};

#endif
