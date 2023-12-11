#include "MacUILib.h"

print_ptr MacUILib_printf;

#ifdef WINDOWS

	#include <conio.h>
	
	void MacUILib_init(void)
	{
		MacUILib_printf = &printf;
	}

	void MacUILib_init_sync(void)
	{
		// Nothing different.  Win allows scanf() to be used with conio.h anyways.
		MacUILib_printf = &printf;
	}

	void MacUILib_Delay(int usec)
	{
		usleep(usec);
	}
	
	int MacUILib_hasChar(void)
	{
		return _kbhit();
	}
	
	char MacUILib_getChar(void)
	{
		return _getch();
	}
	
	void MacUILib_clearScreen(void)
	{
		system("cls");
	}
	
	void MacUILib_uninit(void)
	{
		// No implementation required
		MacUILib_printf("\nPress Any Key to Shut Down\n");
		getchar();
	}
	
#endif

	
#ifdef POSIX

	#include <ncurses.h>
	#include <unistd.h>
	
	void MacUILib_init(void)
	{
		MacUILib_printf = &printw;
		
		initscr();
		noecho();
		cbreak();
		nodelay(stdscr, TRUE);
		curs_set(0);
	}

	void MacUILib_init_sync(void)
	{
		MacUILib_printf = &printw;
		
		initscr();
		noecho();
		curs_set(0);
	}

	void MacUILib_Delay(int usec)
	{
		refresh();
		usleep(usec);
	}

		int MacUILib_hasChar()
	{
		char ch = getch();
		if(ch == ERR)
			return 0;
		else
		{
			ungetch(ch);
			return 1;
		}		
	}

	char MacUILib_getChar(void)
	{
		return getch();
	}

	void MacUILib_clearScreen(void)
	{
		clear();
	}

	void MacUILib_uninit(void)
	{
		MacUILib_printf("\nPress Any Key to Shut Down\n");
		refresh();
		getchar();
		endwin();
	}

#endif
