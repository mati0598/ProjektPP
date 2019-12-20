#include <unistd.h>
#include <ncurses.h>

WINDOW *win;

class Window
{	
	private:
	int height_window, width_window, startx_window, starty_window;
	

	public:
	Window()
	{
		height_window=10;
		width_window=20;
		startx_window=30;
		starty_window=7;

	}

	void Create_Window()
	{
		win=newwin(height_window,width_window,starty_window,startx_window);
		refresh();
		
	}
	
	void Draw_Border()
	{
		box(win,0,0);
		wrefresh(win);
	}

	

};




class MENU
{
	private:
	int x1,x2,y1,y2;
	
	
	
	public:
	MENU()
	{
		x1=6;
		x2=8;
		y1=3;
		y2=6;
	}

	void Print()
	{
		mvwprintw(win,y1,x1,"NEW GAME");
		mvwprintw(win,y2,x2,"QUIT");
		wrefresh(win);
	}

};


int main()
{

	initscr();

	noecho();
	curs_set(0);
	
	Window W1;
	W1.Create_Window();
	W1.Draw_Border();
	
	MENU menu;
	menu.Print();


	
	sleep(5);

	endwin();

	return 0;

}
