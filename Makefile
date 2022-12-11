all: arlgexec boexec junkexec
CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
DEPENDS = ${OBJECTS:.o=.d}

EXEC1 = arlgexec
OBJECTS1 = arlg.o \
		age/engine.o age/controller/cursesController.o age/controller/controller.o \
		age/view/cursesView.o age/view/view.o \
		age/model/model.o age/entity/entity.o age/entity/userControlledEntity.o \
		arlg/arlgModel.o arlg/arlgController.o \
		arlg/entities/player.o arlg/entities/bullet.o arlg/entities/fire.o arlg/entities/health.o \
		arlg/entities/entityWithHealth.o arlg/entities/walker.o \
		arlg/entities/exitLocked.o arlg/entities/exitUnlocked.o \

${EXEC1}: ${OBJECTS1}
	${CXX} ${OBJECTS1} ${GIVEN} -o ${EXEC1} ${CXXFLAGS}

EXEC2 = boexec
OBJECTS2 = bo.o \
		age/engine.o age/controller/cursesController.o age/controller/controller.o \
		age/view/cursesView.o age/view/view.o \
		age/model/model.o age/entity/entity.o age/entity/userControlledEntity.o \
		bo/boController.o bo/boModel.o \
		bo/entities/paddle.o bo/entities/ball.o \
		bo/entities/block.o

${EXEC2}: ${OBJECTS2}
	${CXX} ${OBJECTS2} ${GIVEN} -o ${EXEC2} ${CXXFLAGS}

EXEC3 = junkexec
OBJECTS3 = junk.o \
		age/engine.o age/controller/cursesController.o age/controller/controller.o \
		age/view/cursesView.o age/view/view.o \
		age/model/model.o age/entity/entity.o age/entity/userControlledEntity.o \
		junk/junkController.o junk/junkModel.o \
		junk/entities/player.o junk/entities/exit.o

${EXEC3}: ${OBJECTS3}
	${CXX} ${OBJECTS3} ${GIVEN} -o ${EXEC3} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
