#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

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

// Windows function for chainging text color
void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else {}
}

// Function for printing all the menu options 
void printMenuOptions(string arr[], int n, int selectedOption)
{
	for (int i = 0; i < n; i++)
	{
		// Print selected option
		if (i == selectedOption)
		{
			outputPosition(2, i + 1);
			cout << "-> " << arr[i];
		}

		// Print not selected option
		else
		{
			outputPosition(2, i + 1);
			cout << "   " << arr[i];
		}
	}
}

// Function for moving arround the menu using keyboard
void mainMenu(string arr[], int n)
{
	int selectedOption = 0;
	char pressedKey = ' ';

	printMenuOptions(arr, n, selectedOption);

	while (true)
	{
		pressedKey = _getch();

		// Moving up through the menu
		if (selectedOption != 0 && pressedKey == (char)72)
		{
			selectedOption--;
		}

		// Moving down through the menu
		if (selectedOption != 3 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		printMenuOptions(arr, n, selectedOption);

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
			case 0:
				system("CLS");
				cout << "First option selected";
				break;

			case 1:
				system("CLS");
				cout << "Second option selected";
				break;

			case 2:
				system("CLS");
				cout << "Third option selected";
				break;

			case 3:
				system("CLS");
				cout << "Fourth option selected";
				break;

			default:
				break;
			}
		}	
	}
}

int main()
{
	// Array of strings with all the main menu options
	string mainMenuOptions[4] = { "Start", "Rules", "Settings", "Exit" };
	// Array of strings with all the game difficulty menu options
	string gameDifficultyOptions[3] = { "Easy", "Normal", "Hard" };

	mainMenu(mainMenuOptions, 4);
}

