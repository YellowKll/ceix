#define addCharToStr(a, str) strncat(str, &a, 1)
void loadTitleAndUrlTo(char *title, char *url);

void loadTitleTo(char *title);
void loadUrlTo(char *url);

FILE *feedsFile;
