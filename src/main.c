#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "linksLoader.c"

int main() {
	char *title = malloc(sizeof(char) + 1);
	char *url = malloc(sizeof(char) + 1);
;
	loadTitleAndUrl(title, url);
	printf("title - %s\nurl - %s\n", title, url);
}
