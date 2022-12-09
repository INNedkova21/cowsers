#include <iostream>
#include <conio.h> // _getch()
#include "drawings.h"
#include "output.h"
#include "gameLogic.h"
#include "rules.h"
#include "settings.h"

using namespace std;

// Print all menu options 
void printMenuOptions(string arrWithOptions[], int selectedOption)
{
	printConsoleDesign();

	for (int i = 0; i < 4; i++)
	{
		// Print selected option
		if (i == selectedOption)
		{
			outputPosition(20, i + 13);
			cout << "-> " << arrWithOptions[i];
		}

		// Print not selected option
		else
		{
			outputPosition(20, i + 13);
			cout << "   " << arrWithOptions[i];
		}
	}
}

// Move arround the difficulties menu using keyboard
void gameDifficultyMenu(string gameDifficultyMenuOptions[], string mainMenuOptions[], string nickname)
{
	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;

	while (exitStatement)
	{
		printMenuOptions(gameDifficultyMenuOptions, selectedOption);
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

		printMenuOptions(gameDifficultyMenuOptions, selectedOption);

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Easy mode
			case 0:
				system("CLS");
				bullsAndCows(100, 999, 3, nickname);

				// Print main menu after game
				system("CLS");
				selectedOption = 0;
				printMenuOptions(mainMenuOptions, selectedOption);
				exitStatement = false;
				break;

				// Normal mode
			case 1:
				system("CLS");
				bullsAndCows(1000, 9999, 4, nickname);

				// Print main menu after game
				system("CLS");
				selectedOption = 0;
				printMenuOptions(mainMenuOptions, selectedOption);
				exitStatement = false;
				break;

				// Hard mode
			case 2:
				system("CLS");
				bullsAndCows(10000, 99999, 5, nickname);

				// Print main menu after game
				system("CLS");
				selectedOption = 0;
				printMenuOptions(mainMenuOptions, selectedOption);
				exitStatement = false;
				break;

				// Go back
			case 3:
				system("CLS");
				selectedOption = 0;
				printMenuOptions(mainMenuOptions, selectedOption);
				exitStatement = false;
				break;

			default:
				break;
			}
		}
	}
}

// Move arround the main menu using keyboard
void mainMenu(string mainMenuOptions[], string gameDifficultyMenuOptions[], string changeNicknameOptions[], string nickname)
{
	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;

	printMenuOptions(mainMenuOptions,
		selectedOption);

	while (exitStatement)
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

		printMenuOptions(mainMenuOptions,
			selectedOption);

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Start game
			case 0:
				system("CLS");
				gameDifficultyMenu(gameDifficultyMenuOptions, mainMenuOptions, nickname);
				break;

				// Rules
			case 1:
				system("CLS");
				printRules(mainMenuOptions, selectedOption);
				break;

				// Settings
			case 2:
				system("CLS");
				settings(nickname, changeNicknameOptions, mainMenuOptions);
				break;

				// Exit
			case 3:
				exitStatement = false;
				system("CLS");
				cout << "Press any key to exit";
				break;

			default:
				break;
			}
		}
	}
}