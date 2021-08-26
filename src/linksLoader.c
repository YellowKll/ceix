#include <string.h>

#include "linksLoader.h"


void loadTitleAndUrl (char *title, char *url) {
	feedsFile = fopen(FEEDSFILEDIR, "r");
	if(feedsFile != NULL) {
		loadTitle(title);
		loadUrl(url);
		fclose(feedsFile);
	} 
	else {
		fprintf(stderr, "Error: can't open the feeds file.\n");
		exit(1);
	}
}

void loadTitle(char *title) {
	for (char a = getc(feedsFile); a != titleUrlDelimiter; a = getc(feedsFile))
		addCharToStr(a, title);
}

void loadUrl(char *url) {
	for (char a = getc(feedsFile); a != '\n'; a = getc(feedsFile))
		addCharToStr(a, url);	
	}
