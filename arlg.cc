#include <iostream>
#include "age/engine.h"
#include "age/view/cursesView.h"

#include "arlg/arlgController.h"
#include "arlg/arlgModel.h"

int main() {

    cs246e::Engine<ArlgController, ArlgModel, cs246e::CursesView>
        engine = cs246e::Engine<ArlgController, ArlgModel, cs246e::CursesView>();

    engine.go();

    return 0;
}