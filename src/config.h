#include "feeds.h"

#define titleUrlDelimiter '='
const char *FEEDSFILEDIR = "links.txt";

static const Feed feeds[] = {
	// title			url
	{"hello world",			"https://helloworld.rss"},
	{" destroy the world! ",	"https://destorytheworld.xyz"},
};
