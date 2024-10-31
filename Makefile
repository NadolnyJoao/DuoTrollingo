CC = gcc

RAY_STATIC = -L./raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
RAY_DLL = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
FLAGS = -Wall -Wextra 

BINS = src/main.c src/actions.c
INCLUDE = src/include/panel.c src/include/button.c

update:
	${CC} ${BINS} ${INCLUDE} ${RAY_DLL} ${FLAGS} -o main
	./main
