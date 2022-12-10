CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = arlgexec
OBJECTS = arlg.o \
		age/engine.o age/controller/cursesController.o age/controller/controller.o \
		age/view/cursesView.o age/view/view.o \
		age/model/model.o age/entity/entity.o age/entity/userControlledEntity.o \
		arlg/arlgModel.o arlg/arlgController.o arlg/player.o arlg/bullet.o arlg/fire.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
