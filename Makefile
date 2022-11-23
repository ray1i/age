CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = age-test
OBJECTS = age-test.o engine.o view.o model.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
