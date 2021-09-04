all:
	gcc -g -o hello src/main.c -lncurses -ltinfo -lcurl -Wall
