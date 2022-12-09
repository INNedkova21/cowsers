#include <windows.h> // outputPossition()
#include <stdlib.h> // outputPossition()

// Windows function for setting cursor's possition
void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
	{
		return;
	}
	else {}
}