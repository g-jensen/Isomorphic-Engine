GCC=g++
EXT=cpp
SRC=src

SFML_PATH= C:\SFML-2.5.1
SFML_INCLUDE= -I${SFML_PATH}\include
SFML_LIB= -lsfml-graphics -lsfml-window -lsfml-system
SFML_LINK= -L${SFML_PATH}\lib ${SFML_LIB}

all: compile clean

compile:
ifeq (${OS},Windows_NT)
	${GCC} -c ${SFML_INCLUDE} ${SRC}/*.${EXT}
	${GCC} *.o -o main ${SFML_LINK}
else
	${GCC} -c ${SRC}/*.${EXT}
	${GCC} *.o -o main ${SFML_LIB}
endif

clean:
ifeq (${OS},Windows_NT)
	del *.o
else
	rm *.o
endif