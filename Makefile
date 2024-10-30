CC = gcc

RAY_STATIC = -L./raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
RAY_DLL = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

FLAGS = -Wall -Wextra 

update:
	${CC} src/main.c src/include/panel.c ${RAY_DLL} ${FLAGS} -o main
	./main
