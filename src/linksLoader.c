#include <string.h>

#include "linksLoader.h"


void loadTitleAndUrlTo(char *title, char *url) {
	feedsFile = fopen(FEEDSFILEDIR, "r");
	if(feedsFile != NULL) {
		// everything up to '=' is loaded to title, and everything after '=' (and before '\n'), loaded to url
		fscanf(feedsFile, "%[^=]=%[^\n]", title, url);
		fclose(feedsFile);
	} 
	else {
		fprintf(stderr, "Error: can't open the feeds file.\n");
		exit(1);
	}
}
