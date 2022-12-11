#ifndef __ARLG_MODEL_H
#define __ARLG_MODEL_H

#include "../age/model/model.h"
#include "arlgConstants.h"
#include "entities/exitLocked.h"

class ArlgModel: public cs246e::Model {
    size_t level = 1;
    int remainingEnemies = 0;
    ExitLocked *theExit = nullptr;
    bool gameRunning = true;

    void customInit() override;
    void notify(int s) override;
    bool customUpdate() override {return gameRunning;}
private:
    void newLevel();
};

#endif
