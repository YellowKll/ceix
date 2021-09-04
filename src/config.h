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

#define TITLESBOX_HEIGHT (LINES - HELPBOX_HEIGHT)
#define TITLESBOX_WIDTH (COLS/2)
#define TITLESWINDOW_HEIGHT (LINES - HELPBOX_HEIGHT - 2)
#define TITLESWINDOW_WIDTH (COLS/2 - 2)

#define NAMESBOX_HEIGHT (LINES - HELPBOX_HEIGHT)
#define NAMESBOX_WIDTH (COLS/2)
#define NAMESWINDOW_HEIGHT (LINES - HELPBOX_HEIGHT - 2)
#define NAMESWINDOW_WIDTH (COLS/2 - 2)

#define HELPBOX_HEIGHT 3
#define HELPBOX_WIDTH COLS
#define HELPWINDOW_HEIGHT (HELPBOX_HEIGHT - 2)
#define HELPWINDOW_WIDTH (HELPBOX_WIDTH - 2)
#define HELPMESSAGE "Exit:q | Up/Down:j/k | (WIP) Left/Right:h/l"

static const attr_t highlightAttribute = A_REVERSE;

#endif
