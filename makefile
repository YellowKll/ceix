all:
	tcc -O0 -g -o hello src/main.c -lncurses -ltinfo
