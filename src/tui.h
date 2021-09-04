#ifndef TUI_H
#define TUI_H

#include "feeds.h"

WINDOW *namesWindow;
WINDOW *titlesBox;
WINDOW *titlesWindow;
WINDOW *helpWindow;

void initTui();
void drawTui();

void initWindows();
void drawWindows();

void drawNames();
void printFeedName(FEED *feed);
void drawHelp(WINDOW *win);
void drawTitles(FEED *feed); 

void mainLoop();
void prepareMainLoop();
void decideAction(char a);

void action_nextFeed();
void action_previousFeed();

void highlightFeed(FEED *feed);
void unhighlightFeed(FEED *feed);

#endif
