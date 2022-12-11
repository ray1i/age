#include <iostream>
#include "age/engine.h"
#include "age/view/cursesView.h"

#include "bo/boController.h"
#include "bo/boModel.h"

int main() {

    cs246e::Engine<BoController, BoModel, cs246e::CursesView>
        engine = cs246e::Engine<BoController, BoModel, cs246e::CursesView>();

    engine.go();

    return 0;
}