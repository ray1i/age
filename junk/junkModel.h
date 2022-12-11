#ifndef __JUNK_MODEL_H
#define __JUNK_MODEL_H

#include "../age/model/model.h"
#include "junkConstants.h"

class JunkModel: public cs246e::Model {
    bool gameRunning = true;

    void customInit() override;
    void notify(int s) override;
    bool customUpdate() override {return gameRunning;}
};

#endif
