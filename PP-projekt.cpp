#include <unistd.h>
#include <ncurses.h>

WINDOW *win;
WINDOW *win2;

class MENU
{	
	private:
	int height_window1, width_window1, startx_window1, starty_window1;
	int height_window2, width_window2, startx_window2, starty_window2;
	int x1,x2,y1,y2;
	

	public:
	MENU()
	{
		height_window1=10;
		width_window1=20;
		startx_window1=60;
		starty_window1=14;
		height_window2=34;
		width_window2=90;
		startx_window2=25;
		starty_window2=2;
		x1=6;
		x2=8;
		y1=3;
		y2=6;
	}

	void Create_Window()
	{
		win=newwin(height_window1,width_window1,starty_window1,startx_window1);
		refresh();
		
	}
	
	void Create_Window2()
	{
		win2=newwin(height_window2,width_window2,starty_window2,startx_window2);
		refresh();
		
	}
	void Draw_Border()
	{
		box(win,0,0);
		wrefresh(win);
		
	}
	
	void Draw_Border2()
	{
		box(win2,0,0);
		wrefresh(win2);
	}

	void Print()
	{
		mvwprintw(win,y1,x1,"NEW GAME");
		mvwprintw(win,y2,x2,"QUIT");
		wrefresh(win);
	}

	void Check_Mouse()
	{
		mmask_t mmask;
		MEVENT mysz;
		int we, px,py;
		keypad(stdscr, TRUE);
		mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
		
		while(1)
		{		
			we=getch();
						
			if(we==KEY_MOUSE)
			{
				
				if(getmouse(&mysz)==OK)
				{
					py=mysz.y;
					px=mysz.x;
					if((mysz.y==17) && (mysz.x>=65) && (mysz.x<=74))
					{	
						sleep(1);
						wclear(win);
						wrefresh(win);
						delwin(win);
						Create_Window2();
						Draw_Border2();
						
						break;
					}
				}
			}
		}

		
	}	
};







int main()
{

	initscr();

	noecho();
	curs_set(0);

	
	
	MENU menu;
	menu.Create_Window();
	menu.Draw_Border();
	menu.Print();
	menu.Check_Mouse();

	
	getch();

	endwin();

	return 0;

}
