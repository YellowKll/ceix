#define addCharToStr(a, str) strncat(str, &a, 1)

void loadTitle(char *title);
void loadUrl(char *url);

FILE *feedsFile;
