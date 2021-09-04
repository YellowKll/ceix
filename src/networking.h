#ifndef NETWORKING_H
#define NETWORKING_H

#include "feeds.h"
void getArticles(FEED *feed);
size_t got_data(char *response, size_t itemsize, size_t nitems, void *feedPtr);

#endif
