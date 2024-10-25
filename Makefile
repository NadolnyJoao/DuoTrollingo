CC = gcc

RAY_FLAGS = -L./raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

FLAGS = -Wall -Wextra -O2

update:
	${CC} src/main.c ${RAY_FLAGS} ${FLAGS} -o main
	./main
