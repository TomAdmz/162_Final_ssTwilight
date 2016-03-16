#########################################################################
## Author: Tom Adamcewicz
## Date: 3/15/16
## Description: This is the makefile for the final project, it includes 
## c++ flags, variables for all file types and build instructions
## to make the ssTwilight program. It includes instructions to
## to compress all files as well as clean the target program.
########################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

####################
### USER SECTION ###
####################

SRCS = Creature.cpp SpaceMarine.cpp Alien.cpp Space.cpp Ship.cpp Game.cpp
SRCS += Die.cpp CargoBay.cpp ControlRoom.cpp Lab.cpp EscapePod.cpp
SRCS += Bridge.cpp ssTwilight.cpp

HEADERS = Creature.hpp SpaceMarine.hpp Alien.hpp Space.hpp Ship.hpp Game.hpp
HEADERS += Die.hpp CargoBay.hpp ControlRoom.hpp Lab.hpp EscapePod.hpp
HEADERS += Bridge.hpp 


TARGET = ssTwilight

TAR = cs162_final_adamcewt.tar.bz2

ZIP = cs162_final_adamcewt.zip

#####################
### BUILD SECTION ###
#####################

${TARGET}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${TARGET}

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS}  makefile

zip:
	zip ${ZIP} ${SRCS} ${HEADERS}  makefile

clean:
	rm -f ${TARGET} *.o *~

