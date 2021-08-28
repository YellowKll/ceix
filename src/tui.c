#include <curses.h>
#include "feeds.h"
#include "tui.h"
#include "config.h"
#include "main.h"

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
	namesWindow = newwin(LINES-helpWindowHeight, COLS/2, 0, 0);
	titlesWindow = newwin(LINES-helpWindowHeight, COLS/2, 0, COLS/2);
	helpWindow = newwin(helpWindowHeight, COLS, LINES - helpWindowHeight, 0);

	refresh();
}

void drawWindows() {
	box(namesWindow, 0, 0);
	drawNames(namesWindow);
	wrefresh(namesWindow);

	box(titlesWindow, 0, 0);
	drawTitles(titlesWindow);
	wrefresh(titlesWindow);

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

void drawTitles(WINDOW *win) {
	mvwprintw(win, 1, 1, "Titles of the articles.");
}

void drawHelp(WINDOW* win) {
	if(helpWindowHeight > 1) 
		mvwprintw(win, 1, 1, helpMessage);
}

void mainLoop() {
	currentFeed = 0;
	highlightFeed(currentFeed);
	for(char a = wgetch(namesWindow); a != 'q'; a = getch())
		decideAction(a);
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
	if (currentFeed == feedCount-1) 
		currentFeed = 0;
	else
		currentFeed++;
	highlightFeed(currentFeed);
}

void previousFeed() {
	unhighlightFeed(currentFeed);
	if (currentFeed == 0)
		currentFeed = feedCount-1;
	else
		currentFeed--;
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
