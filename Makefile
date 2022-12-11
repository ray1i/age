all: boexec
CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = boexec
# OBJECTS = arlg.o bo.o
OBJECTS = bo.o \
		age/engine.o age/controller/cursesController.o age/controller/controller.o \
		age/view/cursesView.o age/view/view.o \
		age/model/model.o age/entity/entity.o age/entity/userControlledEntity.o \
		arlg/arlgModel.o arlg/arlgController.o \
		arlg/entities/player.o arlg/entities/bullet.o arlg/entities/fire.o arlg/entities/health.o \
		arlg/entities/entityWithHealth.o arlg/entities/walker.o \
		arlg/entities/exitLocked.o arlg/entities/exitUnlocked.o \
		bo/boController.o bo/boModel.o \
		bo/entities/paddle.o bo/entities/ball.o \
		bo/entities/block.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
