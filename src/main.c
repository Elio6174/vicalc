#include <stdio.h>
#include <curses.h>

void imprimirBuffer(const char *buffer);
void imprimirCeldas(char letras[], WINDOW *cel);

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
	
	WINDOW *cel = derwin(win, 3, 13, 1, 1);
	wborder(cel, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel, y, x);
	mvwprintw(cel, y>>1, x>>1, "A");
	wrefresh(cel);

	WINDOW *cel2 = derwin(win, 3, 13, 1, 13);
	wborder(cel2, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel2, y, x);
	mvwprintw(cel2, y>>1, x>>1, "B");
	wrefresh(cel2);
	wrefresh(cel2); 

	WINDOW *cel3 = derwin(win, 3, 13, 1, 25);
	wborder(cel3, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel3, y, x);
	mvwprintw(cel3, y>>1, x>>1, "C");
	wrefresh(cel3);
	wrefresh(cel3); 
	
	WINDOW *cel4 = derwin(win, 3, 13, 1, 37);
	wborder(cel4, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel4, y, x);
	mvwprintw(cel4, y>>1, x>>1, "D");
	wrefresh(cel4);
	wrefresh(cel4); 
	
	WINDOW *cel5 = derwin(win, 3, 13, 1, 49);
	wborder(cel5, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel5, y, x);
	mvwprintw(cel5, y>>1, x>>1, "E");
	wrefresh(cel5);
	wrefresh(cel5); 

	WINDOW *cel6 = derwin(win, 3, 13, 1, 61);
	wborder(cel6, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel6, y, x);
	mvwprintw(cel6, y>>1, x>>1, "F");
	wrefresh(cel6);
	wrefresh(cel6); 
	
	WINDOW *cel7 = derwin(win, 3, 13, 1, 73);
	wborder(cel7, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel7, y, x);
	mvwprintw(cel7, y>>1, x>>1, "G");
	wrefresh(cel7);
	wrefresh(cel7); 

	WINDOW *cel8 = derwin(win, 3, 13, 1, 85);
	wborder(cel8, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(cel8, y, x);
	mvwprintw(cel8, y>>1, x>>1, "H");
	wrefresh(cel8);
	wrefresh(cel8); 
	char rows[] = {'A','B','C','D'}; 
	
	//imprimirCeldas(rows, cel2);
	


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

void imprimirBuffer(const char *buffer){
	printf("BUFFER: %s\n", buffer);
}


void imprimirCeldas(char letras[], WINDOW *cel2){
	int lenght = sizeof(&letras) >> sizeof(letras[0]);
	int max_x = 13, max_y = 3;
	int x, y;
	for(int i = 0; i < lenght; i++){
		
	}

	getmaxyx(cel2, y, x);
	mvwprintw(cel2, y>>1, (x>>1), "O");
	
}
