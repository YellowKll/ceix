#include <curses.h>
#include "feeds.h"
#include "tui.h"
#include "config.h"
#include "main.h"
#include "networking.h"

#define feedCount sizeof(feeds)/sizeof(Feed)

void initTui () {
	initscr();
	noecho();
}

void drawTui() {
	initWindows();
	drawWindows();
}

void initWindows() {
	namesWindow = newwin(LINES - helpWindowHeight, COLS/2, 0, 0);
	titlesWindow = newwin(LINES - helpWindowHeight, COLS/2, 0, COLS/2);
	helpWindow = newwin(helpWindowHeight, COLS, LINES - helpWindowHeight, 0);

	refresh();
}

void drawWindows() {
	box(namesWindow, 0, 0);
	drawNames(namesWindow);
	wrefresh(namesWindow);

	box(helpWindow, 0, 0);
	drawHelp(helpWindow);
	wrefresh(helpWindow);
}

void drawNames(WINDOW *win) {
	for(int i = 0; i < feedCount; i++)
		printFeedName(win, i);
}

void printFeedName(WINDOW *win, int feedIndex) {
	mvwprintw(win, feedIndex+1, 1, "%s", feeds[feedIndex].name);
}

void drawHelp(WINDOW* win) {
	if(helpWindowHeight > 1) 
		mvwprintw(win, 1, 1, helpMessage);
}

void drawTitles(WINDOW* win, Feed *feed){ 
	werase(win);
	getArticles(feed);
	mvwprintw(win, 1, 1, "%s", feed->content);
	box(win, 0, 0);
	wrefresh(win);
}

void mainLoop() {
	prepareMainLoop();
	for(char a = wgetch(namesWindow); a != 'q'; a = getch())
		decideAction(a);
}

void prepareMainLoop() {
	currentFeed = 0;

	drawTitles(titlesWindow, &feeds[currentFeed]);
	wrefresh(titlesWindow);

	highlightFeed(currentFeed);
}

void decideAction(char a) {
	switch(a) {
		case 'j':
			nextFeed();
			wrefresh(namesWindow);
			break;
		case 'k':
			previousFeed();
			wrefresh(namesWindow);
			break;
		case 'q':
			cleanup();
			break;
	}
}

void nextFeed() {
	unhighlightFeed(currentFeed);
	if (currentFeed == feedCount - 1) 
		currentFeed = 0;
	else
		currentFeed++;
	drawTitles(titlesWindow, &feeds[currentFeed]);
	highlightFeed(currentFeed);
}

void previousFeed() {
	unhighlightFeed(currentFeed);
	if (currentFeed == 0)
		currentFeed = feedCount-1;
	else
		currentFeed--;
	drawTitles(titlesWindow, &feeds[currentFeed]);
	highlightFeed(currentFeed);
}

void highlightFeed(int i) {
	wattron(namesWindow, highlightAttribute);
	printFeedName(namesWindow, i);
	wattroff(namesWindow, highlightAttribute);
}

void unhighlightFeed(int i) {
	printFeedName(namesWindow, i);
}
