#include <curses.h>
#include "feeds.h"
#include "tui.h"
#include "config.h"
#include "main.h"
#include "networking.h"


void initCurses () {
	initscr();
	noecho();
	cbreak();
}

void initTui() {
	initBoxes();
	initWindows();
	refresh();
}

void initBoxes (){
	namesBox = newwin(NAMESBOX_HEIGHT, NAMESBOX_WIDTH, 0, 0);
	titlesBox = newwin(TITLESBOX_HEIGHT, TITLESBOX_WIDTH, 0, COLS/2);
	helpBox = newwin(HELPBOX_HEIGHT, HELPBOX_WIDTH, LINES - HELPBOX_HEIGHT, 0);
}

void initWindows() {
	namesWindow = derwin(namesBox, NAMESWINDOW_HEIGHT, NAMESWINDOW_WIDTH, 1, 1);
	titlesWindow = derwin(titlesBox, TITLESWINDOW_HEIGHT, TITLESWINDOW_WIDTH, 1, 1);
	helpWindow = derwin(helpBox, HELPWINDOW_HEIGHT, HELPWINDOW_WIDTH, 1, 1);
}

void drawTui() {
	drawBoxes();
	drawWindows();
}

void drawBoxes() {
	box(namesBox, 0, 0);
	wrefresh(namesBox);

	box(titlesBox, 0, 0);
	wrefresh(titlesBox);

	box(helpBox, 0, 0);
	wrefresh(helpBox);
}

void drawWindows() {
	drawNames();
	drawTitles(currentFeed);
	drawHelp();
}

void drawNames() {
	for(int i = 0; i < feedCount; i++)
		printFeedName(&feeds[i]);
	wrefresh(namesWindow);
}

void printFeedName(FEED *feed) {
	mvwprintw(namesWindow, feed->index, 0, "%s", feed->name);
}

void drawTitles(FEED *feed){ 
	werase(titlesWindow);
	loadArticlesInto(feed);
	mvwprintw(titlesWindow, 0, 0, "%s", feed->content);
	wrefresh(titlesWindow);
}

void drawHelp() {
	mvwprintw(helpWindow, 0, 0, HELPMESSAGE);
	wrefresh(helpWindow);
}


void mainLoop() {
	prepareMainLoop();
	for(char a = wgetch(namesWindow); a != 'q'; a = getch())
		decideAction(a);
}

void prepareMainLoop() {
	highlightFeed(currentFeed);
}

void decideAction(char a) {
	switch(a) {
		case 'j':
			action_nextFeed();
			break;
		case 'k':
			action_previousFeed();
			break;
		case 'q':
			cleanup();
			break;
	}
}

void action_nextFeed() {
	unhighlightFeed(currentFeed);
	currentFeed = getNextFeed();
	highlightFeed(currentFeed);
	wrefresh(namesWindow);

	drawTitles(currentFeed);
}

void action_previousFeed() {
	unhighlightFeed(currentFeed);
	currentFeed = getPreviousFeed();
	highlightFeed(currentFeed);
	wrefresh(namesWindow);

	drawTitles(currentFeed);
}

void highlightFeed(FEED *feed) {
	wattron(namesWindow, highlightAttribute);
	printFeedName(feed);
	wattroff(namesWindow, highlightAttribute);
}

void unhighlightFeed(FEED *feed) {
	printFeedName(feed);
}
