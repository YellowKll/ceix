#include <string.h>

#include "linksLoader.h"


void loadTitleAndUrlTo(char *title, char *url) {
	feedsFile = fopen(FEEDSFILEDIR, "r");
	if(feedsFile != NULL) {
		loadTitleTo(title);
		loadUrlTo(url);
		fclose(feedsFile);
	} 
	else {
		fprintf(stderr, "Error: can't open the feeds file.\n");
		exit(1);
	}
}

void loadTitleTo(char *title) {
	for (char a = getc(feedsFile); a != titleUrlDelimiter; a = getc(feedsFile))
		addCharToStr(a, title);
}

void loadUrlTo(char *url) {
	for (char a = getc(feedsFile); a != '\n'; a = getc(feedsFile))
		addCharToStr(a, url);	
	}
