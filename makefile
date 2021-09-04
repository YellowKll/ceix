all:
	tcc -g -o hello src/main.c -lncurses -ltinfo -lcurl -Wall
	ctags -R .
d:
	gcc -g -o hello src/main.c -lncurses -ltinfo -lcurl -Wall
