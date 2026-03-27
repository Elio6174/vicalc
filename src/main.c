#include <stdio.h>
#include <curses.h>

void imprimirBuffer(const char *buffer);

void printRows(WINDOW *win);
void printColumns(WINDOW *win);

int main(int argc, char *argv[]){
	initscr();
	noecho();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW *win = newwin(yMax, xMax, 0, 0);
	box(win, 0, 0);
	
	mvwprintw(win,0,2,"File");
	mvwprintw(win,0,7, "Options");
	
	
	int x, y;

	printRows(win);
	printColumns(win);




	char ch;
	while(ch = wgetch(win)){
		switch(ch){
			case 'f':
				wattron(win, A_STANDOUT);
				mvwprintw(win,0,2,"File");
			break;
			case 'o':
				wattron(win, A_STANDOUT);
				mvwprintw(win,0,7, "Options");
				default:
			break;
		}
	}
		
		
		
	endwin();
	return 0;
}
	

	
	
void printColumns(WINDOW *win){
	char rows[] = {'A','B','C','D','E','F','G'}; 
	int lenght = sizeof(rows) / sizeof(rows[0]);
	WINDOW *colm;		
	int x, y;

	for(int i = 0; i < lenght; i++){
		colm = derwin(win, 3, 13, 1, 12*i + 5);
		wborder(colm, '|', '|', '-', '-', '+', '+', '+', '+');
		getmaxyx(colm, y, x);
		mvwprintw(colm, y>>1, x>>1, "%c", rows[i]);
		wrefresh(colm);
	}
}


void printRows(WINDOW *win){
	int x, y;
	WINDOW *row;
	for(int i = 0; i < 24; i++){
		row = derwin(win, 3, 5, (i<<1)+3 , 1);
		wborder(row, '|', '|', '-', '-', '+', '+', '+', '+');
		getmaxyx(row, y, x);
		mvwprintw(row, y>>1, x>>1, "%d", i+1);
		wrefresh(row);
	}
}