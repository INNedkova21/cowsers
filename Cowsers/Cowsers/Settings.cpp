#include <iostream>
#include <string>
#include <conio.h> // _getch()
#include "output.h"
#include "drawings.h"
#include "menus.h"

using namespace std;

// Settings option
void settings(string& nickname, string menuOptions[], string mainMenuOptions[])
{
	printConsoleDesign();

	outputPosition(22, 12);
	cout << "Hi " << nickname << ",";
	outputPosition(17, 13);
	cout << "Welcome to settings!";

	outputPosition(16, 15);
	cout << "Change your nickname?";

	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;

	// Print menu options
	for (int i = 0; i < 2; i++)
	{
		// Print selected option
		if (i == selectedOption)
		{
			outputPosition(22, i + 17);
			cout << "-> " << menuOptions[i];
		}

		// Print not selected option
		else
		{
			outputPosition(22, i + 17);
			cout << "   " << menuOptions[i];
		}
	}

	while (exitStatement)
	{
		pressedKey = _getch();

		// Moving up through the menu
		if (selectedOption != 0 && pressedKey == (char)72)
		{
			selectedOption--;
		}

		// Moving down through the menu
		if (selectedOption != 1 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		// Print menu options
		for (int i = 0; i < 2; i++)
		{
			// Print selected option
			if (i == selectedOption)
			{
				outputPosition(22, i + 17);
				cout << "-> " << menuOptions[i];
			}

			// Print not selected option
			else
			{
				outputPosition(22, i + 17);
				cout << "   " << menuOptions[i];
			}
		}

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Change nickname
			case 0:
				system("CLS");
				printConsoleDesign();
				printPopup();

				outputPosition(17, 14);
				cout << "Enter your nickname";

				// Nickname input			
				outputPosition(25, 15);
				getline(cin, nickname);

				// Press enter to go back
				outputPosition(29, 18);
				cout << "Press Enter";

				pressedKey = ' ';
				pressedKey = _getch();

				while (pressedKey != '\r')
				{
					pressedKey = ' ';
					pressedKey = _getch();
				}

				system("CLS");
				printConsoleDesign();

				selectedOption = 2;

				printMenuOptions(mainMenuOptions,
					selectedOption);
				exitStatement = false;
				break;

				// Don't change nickname - Go back
			case 1:
				selectedOption = 2;

				printMenuOptions(mainMenuOptions,
					selectedOption);
				exitStatement = false;
				break;

			default:
				break;
			}
		}
	}
}