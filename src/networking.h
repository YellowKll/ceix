#ifndef NETWORKING_H
#define NETWORKING_H

#include "feeds.h"
#include <curl/curl.h>

void loadArticlesInto(FEED *feed);
void setCurlOptions(CURL *handle, FEED *feed, char *errorBuffer);
size_t got_data(char *response, size_t itemsize, size_t nitems, void *feedPtr);

#endif
