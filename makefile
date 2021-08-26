all:
	gcc -O0 -g -o hello src/main.c -lncurses -ltinfo -Iinclude
