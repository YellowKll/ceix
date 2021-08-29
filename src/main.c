#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "feeds.h"
#include "config.h"
#include "tui.c"
#include "networking.c"

void cleanup() {
	endwin();
	exit(0);
}

int main() {
	signal(SIGINT, cleanup);

	initTui();
	drawTui();
	mainLoop();
	cleanup();
}
