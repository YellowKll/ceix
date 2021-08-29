#ifndef NETWORKING_H
#define NETWORKING_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#include "networking.h"
#include "feeds.h"

void getDocument(Feed *feed) {
#ifndef OMIT_SECURITY_CHECKS
	if (feed->content != NULL) {
		fprintf(stderr, "Error: getDocument(Feed *feed); feed->content is not NULL");
		exit(ERR);
	}
#endif
	feed->content = calloc(1, sizeof(char));

	CURL *ptr = curl_easy_init();
	curl_easy_setopt(ptr, CURLOPT_URL, feed->url);
	curl_easy_setopt(ptr, CURLOPT_WRITEDATA, (void *) feed);
	curl_easy_setopt(ptr, CURLOPT_WRITEFUNCTION, got_data);
	curl_easy_perform(ptr);
	curl_easy_cleanup(ptr);
}

size_t got_data(char *response, size_t itemsize, size_t nitems, void *feedPtr) {
	size_t bytes = itemsize * nitems;
	printf("New Chunk! (%zu bytes)", bytes);
	Feed *feed = (Feed *) feedPtr;
	feed->contentSize += bytes;

	feed->content = realloc(feed->content, feed->contentSize+1);
	strncat(feed->content, response, bytes);
	return bytes;
}
#endif
