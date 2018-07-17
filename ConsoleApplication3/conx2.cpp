#include "conx2.h"

// hide the annoying cursor
void hidcur()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
// move cursor to given location
void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// read a key entered from keyboard
int getkey(void) {
	return( _getch() );
}

// detect key pressing
bool KeyPressed(void) {
	return( _kbhit() );
}

// clear console
void clrcon(void) {
	system("cls");
}