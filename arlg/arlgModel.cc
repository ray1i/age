#include "arlgModel.h"
#include "player.h"
#include "fire.h"

void ArlgModel::customInit() {
    addEntity(new Player(10, 10));
    addEntity(new Fire(40, 10));
}
