#include <string.h>

#include "linksLoader.h"


void loadTitleAndUrlTo(char *title, char *url) {
	feedsFile = fopen(FEEDSFILEDIR, "r");
	if(feedsFile != NULL) {
		fscanf(feedsFile, "%[^=]=%s", title, url);
		fclose(feedsFile);
	} 
	else {
		fprintf(stderr, "Error: can't open the feeds file.\n");
		exit(1);
	}
}
