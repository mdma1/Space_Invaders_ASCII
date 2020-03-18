#include "Headers.h"

void setPosition(int i, int j)
{
	COORD cPos;
	cPos.X = i;
	cPos.Y = j;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
}

void setColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}