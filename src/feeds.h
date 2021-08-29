#ifndef FEEDS_H
#define FEEDS_H

typedef struct {
	char *name;
	char *url;
	char *content;
	size_t contentSize; // in bytes
} Feed;

#endif
