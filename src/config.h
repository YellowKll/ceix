#ifndef CONFIG_H
#define CONFIG_H

#include <curses.h>
#include "feeds.h"

static FEED feeds[] = {
	// title			url
	{"hello world",			"https://example.com"},
	{"glueBackTheWorld<3",		"https://lukesmith.xyz"},
	{"d E \ns troy th eWórlð",	"https://destroyTheWorld.abfasd"},
};

// TODO - delete - titlesWindow = derwin(titlesBox, LINES - helpWindowHeight - 2, COLS/2-2, 1, 1);
#define titlesWindowHeight
#define helpWindowHeight 3
#define helpMessage "Exit:q | Up/Down:j/k | (WIP) Left/Right:h/l"

static const attr_t highlightAttribute = A_REVERSE;

#endif
