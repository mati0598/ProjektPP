#include <unistd.h>
#include <ncurses.h>

class NEW_GAME
{
	private:
	int x, y;
	
	
	public:
	NEW_GAME()
	{
		x=(COLS-5)/2;
		y=7;
	}

	void Print()
	{
		mvprintw(y,x,"NEW GAME");
	}

};


int main()
{

	initscr();

	noecho();
	curs_set(0);

	NEW_GAME new_game;
	new_game.Print();


	refresh();
	sleep(5);

	endwin();

	return 0;

}
