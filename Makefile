CC = gcc

RAY_FLAGS = -L./raylib/ -lraylib

FLAGS = -Wall -Wextra -O2

update:
	${CC} src/main.c ${RAY_FLAGS} ${FLAGS} -o main
