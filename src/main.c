#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "feeds.c"
#include "config.h"
#include "tui.c"
#include "networking.c"

void cleanup() {
	endwin();
	exit(0);
}

int main() {
	signal(SIGINT, cleanup);

	initFeeds();
	initTui();
	drawTui();
	mainLoop();
	cleanup();
}
