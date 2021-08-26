#include <string.h>

#include "linksLoader.h"

#define delimiter '='

#define addCharToStr(a, str) strncat(str, &a, 1)

void loadTitle(char *title);
void loadUrl(char *url);


void loadTitleAndUrl (char *title, char *url) {
	feedsFile = fopen(LINKSFILEDIR, "r");
	loadTitle(title);
	loadUrl(url);
	fclose(feedsFile);
}

void loadTitle(char *title) {
	for (char a = getc(feedsFile); a != titleUrlDelimiter; a = getc(feedsFile))
		addCharToStr(a, title);
}

void loadUrl(char *url) {
	for (char a = getc(feedsFile); a != '\n'; a = getc(feedsFile))
		addCharToStr(a, url);	
	}
