all: main.c
	gcc -Wall -Werror -lm -o geometry main.c