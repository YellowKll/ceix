#ifndef NETWORKING_C
#define NETWORKING_C

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#include "networking.h"
#include "feeds.h"

void getArticles(FEED *feed) {
	if (feed->content != NULL) {
		return;
	}

	feed->content = calloc(1, sizeof(char));
	char errorBuffer[CURL_ERROR_SIZE];

	CURL *ptr = curl_easy_init();
	curl_easy_setopt(ptr, CURLOPT_URL, feed->url);
	curl_easy_setopt(ptr, CURLOPT_WRITEDATA, (void *) feed);
	curl_easy_setopt(ptr, CURLOPT_WRITEFUNCTION, got_data);
	curl_easy_setopt(ptr, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_perform(ptr);

	if(strlen(errorBuffer) > 1){
		free(feed->content);
		feed->content = calloc(strlen(errorBuffer), sizeof(char));
		strcpy(feed->content, errorBuffer);
	}

	curl_easy_cleanup(ptr);
}

size_t got_data(char *response, size_t itemsize, size_t nitems, void *feedPtr) {
	size_t bytes = itemsize * nitems;
	// printf("New Chunk! (%zu bytes)", bytes);
	FEED *feed = (FEED *) feedPtr;
	feed->contentSize += bytes;

	feed->content = realloc(feed->content, feed->contentSize+1);
	strncat(feed->content, response, bytes);
	return bytes;
}

#endif
