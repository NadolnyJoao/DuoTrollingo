CC = gcc

RAY_STATIC = -Wl,-Bstatic -L./raylib/ -lraylib -lpthread -ldl -lrt -Wl,-Bdynamic -lGL -lX11 -lm
RAY_DLL = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
FLAGS = -Wall -Wextra -std=c17 -pedantic -O3

OBJ = obj/

BINS = ${OBJ}panel.o ${OBJ}button.o ${OBJ}actions.o

main: ${BINS} src/main.c
	${CC} $^ ${RAY_DLL} ${FLAGS} -o $@

clear:
	rm obj/*.o
	rm main

${OBJ}panel.o: src/include/panel.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}button.o: src/include/button.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}actions.o: src/actions.c
	${CC} ${FLAGS} -c $^ -o $@
