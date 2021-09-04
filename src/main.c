#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "feeds.c"
#include "config.h"
#include "tui.c"
#include "networking.c"
#include "main.h"

int main() {
	signal(SIGINT, cleanup);

	initFeeds();
	initCurses();
	initTui();

	drawTui();
	mainLoop();

	cleanup();
}

void cleanup() {
	endwin();
	exit(0);
}
