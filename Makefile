
GCC=g++
EXT=cpp
SRC=src
SFML= -lsfml-graphics -lsfml-window -lsfml-system

all: compile clean

compile:
	${GCC} -c ${SRC}/*.${EXT}
	${GCC} *.o -o main ${SFML}
clean:
	rm *.o
