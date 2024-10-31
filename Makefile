CC = gcc

RAY_STATIC = -L./raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
RAY_DLL = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
FLAGS = -Wall -Wextra 

OBJ = obj/

BINS = ${OBJ}panel.o ${OBJ}button.o ${OBJ}actions.o

main: ${BINS} src/main.c
	${CC} $^ ${RAY_STATIC} ${FLAGS} -o $@
	./main

${OBJ}panel.o: src/include/panel.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}button.o: src/include/button.c
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}actions.o: src/actions.c
	${CC} ${FLAGS} -c $^ -o $@
