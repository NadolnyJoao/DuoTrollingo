.DEFAULT_GOAL := run
CC = gcc

RAY_STATIC = -Wl,-Bstatic -L./raylib/ -lraylib -lpthread -ldl -lrt -Wl,-Bdynamic -lGL -lX11 -lm
RAY_DLL = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
FLAGS = -Wall -Wextra -std=c17 -pedantic -O3

OBJ = obj/

BINS = ${OBJ}panel.o ${OBJ}button.o ${OBJ}actions.o ${OBJ}globals.o

all: ${BINS} src/main.c
	${CC} $^ ${RAY_DLL} ${FLAGS} -o main

clear:
	rm obj/*.o
	rm main

run: all
	./main

${OBJ}panel.o: src/include/panel.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}button.o: src/include/button.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}actions.o: src/actions.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}globals.o: src/globals.c
	${CC} ${FLAGS} -c $^ -o $@
