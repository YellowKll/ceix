#include <curses.h>
#include "feeds.h"
#include "tui.h"
#include "config.h"
#include "main.h"
#include "networking.h"


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
	titlesBox = newwin(LINES - helpWindowHeight, COLS/2, 0, COLS/2);
	titlesWindow = derwin(titlesBox, LINES - helpWindowHeight - 2, COLS/2-2, 1, 1);
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

void drawNames() {
	for(int i = 0; i < feedCount; i++)
		printFeedName(&feeds[i]);
}

void printFeedName(FEED *feed) {
	mvwprintw(namesWindow, feed->index, 0, "%s", feed->name);
}

void drawHelp(WINDOW* win) {
	if(helpWindowHeight > 1) 
		mvwprintw(win, 1, 1, helpMessage);
}

void drawTitles(FEED *feed){ 
	werase(titlesWindow);
	getArticles(feed);
	mvwprintw(titlesWindow, 0, 0, "%s", feed->content);
	box(titlesBox, 0, 0);
	wrefresh(titlesWindow);
}

void mainLoop() {
	prepareMainLoop();
	for(char a = wgetch(namesWindow); a != 'q'; a = getch())
		decideAction(a);
}

void prepareMainLoop() {
	drawTitles(currentFeed);
	touchwin(titlesBox);
	wrefresh(titlesBox);
	wrefresh(titlesWindow);

	highlightFeed(currentFeed);
}

void decideAction(char a) {
	switch(a) {
		case 'j':
			action_nextFeed();
			wrefresh(namesWindow);
			break;
		case 'k':
			action_previousFeed();
			wrefresh(namesWindow);
			break;
		case 'q':
			cleanup();
			break;
	}
}

void action_nextFeed() {
	unhighlightFeed(currentFeed);
	currentFeed = getNextFeed();
	drawTitles(currentFeed);
	highlightFeed(currentFeed);
}

void action_previousFeed() {
	unhighlightFeed(currentFeed);
	currentFeed = getPreviousFeed();
	drawTitles(currentFeed);
	highlightFeed(currentFeed);
}

void highlightFeed(FEED *feed) {
	wattron(namesWindow, highlightAttribute);
	printFeedName(feed);
	wattroff(namesWindow, highlightAttribute);
}

void unhighlightFeed(FEED *feed) {
	printFeedName(feed);
}
