#ifndef __BO_MODEL_H
#define __BO_MODEL_H

#include "../age/model/model.h"
#include "boConstants.h"

class BoModel: public cs246e::Model {
    size_t level = 1;
    int remainingBlocks = 0;
    int ballsCount = 0;
    bool gameRunning = true;

    void customInit() override;
    void notify(int s) override;
    bool customUpdate() override {return gameRunning;}
private:
    void newLevel();
};

#endif
