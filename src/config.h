#ifndef CONFIG_H
#define CONFIG_H

#include <curses.h>
#include "feeds.h"

static Feed feeds[] = {
	// title			url
	{"hello world",			"https://example.com"},
	{" destroy the world! ",	"https://lukesmith.xyz"},
	{"glueBackTheWorld<3",		"https://gluebacktheworld.how"}
};

#define helpWindowHeight 3
#define helpMessage "Exit:q | Up/Down:j/k | (WIP) Left/Right:h/l"

static const attr_t highlightAttribute = A_BOLD;

#endif
