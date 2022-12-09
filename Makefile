CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = vm
OBJECTS = vm.o engine.o cursesView.o view.o model.o entity.o arlg/bullet.o arlg/fire.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
