#ifndef TUI_H
#define TUI_H

WINDOW *namesWindow;
WINDOW *titlesBox;
WINDOW *titlesWindow;
WINDOW *helpWindow;

unsigned int currentFeed;

void initTui();
void drawTui();

void initWindows();
void drawWindows();

void drawNames(WINDOW *win);
void printFeedName(WINDOW *win, int feedIndex);
void drawHelp(WINDOW *win);
void drawTitles(WINDOW* win, Feed *feed); 

void mainLoop();
void prepareMainLoop();
void decideAction(char a);

void nextFeed();
void previousFeed();

void highlightFeed(int i);
void unhighlightFeed(int i);

#endif
