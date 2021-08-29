#include "networking.c"
#include <stdio.h>

int main() {
	Feed *feed = calloc(1, sizeof(Feed));
	feed->name = "hello world";
	feed->url = "https://lukesmith.xyz";
	getDocument(feed);
	printf("%s", feed->content);

	return 0;
}
