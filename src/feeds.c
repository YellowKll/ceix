#ifndef FEEDS_C
#define FEEDS_C

#include "config.h"
#include "feeds.h"
void initFeeds() {
	for (unsigned int i = 0; i < feedCount; i++) {
		feeds[i].index = i;
	}
	currentFeed = &feeds[0];
}

FEED *getPreviousFeed() {
	if (currentFeed->index == 0) 
		return &feeds[feedCount - 1];
	else
		return &feeds[currentFeed->index -1];
}

FEED *getNextFeed() {
	if (currentFeed->index == (feedCount - 1))
		return &feeds[0];
	else
		return &feeds[currentFeed->index + 1];
}

#endif
