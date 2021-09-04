#ifndef NETWORKING_C
#define NETWORKING_C

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#include "feeds.h"
#include "networking.h"

void loadArticlesInto(FEED *feed) {
	if (feed->content != NULL) {
		return;
	}

	feed->content = calloc(1, sizeof(char));
	char errorBuffer[CURL_ERROR_SIZE];

	CURL *curlHandle = curl_easy_init();
	setCurlOptions(curlHandle, feed, errorBuffer);
	curl_easy_perform(curlHandle);

	if(strlen(errorBuffer) > 1){
		free(feed->content);
		feed->content = calloc(strlen(errorBuffer), sizeof(char));
		strcpy(feed->content, errorBuffer);
	}

	curl_easy_cleanup(curlHandle);
}

void setCurlOptions(CURL *handle, FEED *feed, char *errorBuffer) {
	curl_easy_setopt(handle,	CURLOPT_URL,		feed->url);
	curl_easy_setopt(handle,	CURLOPT_WRITEDATA,	(void *) feed);
	curl_easy_setopt(handle,	CURLOPT_ERRORBUFFER,	errorBuffer);
	curl_easy_setopt(handle,	CURLOPT_WRITEFUNCTION,	got_data);
}

size_t got_data(char *response, size_t itemsize, size_t nitems, void *feedPtr) {
	size_t bytes = itemsize * nitems;
	FEED *feed = (FEED *) feedPtr;
	feed->contentSize += bytes;
	feed->content = realloc(feed->content, feed->contentSize+1);
	strncat(feed->content, response, bytes);
	return bytes;
}

#endif
