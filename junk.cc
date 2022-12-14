#include <iostream>
#include "age/engine.h"
#include "age/view/cursesView.h"

#include "junk/junkController.h"
#include "junk/junkModel.h"

int main() {

    cs246e::Engine<JunkController, JunkModel, cs246e::CursesView>
        engine = cs246e::Engine<JunkController, JunkModel, cs246e::CursesView>();

    engine.go();

    return 0;
}
