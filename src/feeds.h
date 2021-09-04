#ifndef FEEDS_H
#define FEEDS_H

#include "config.h"

typedef struct {
	char *name;
	char *url;
	char *content;
	size_t contentSize; // in bytes
	unsigned int index;
} FEED;

FEED *currentFeed;

#define feedCount sizeof(feeds)/sizeof(FEED)

void initFeeds();

FEED *getNextFeed();
FEED *getPreviousFeed();

#endif
