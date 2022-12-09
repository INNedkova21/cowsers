#include <iostream>
#include <string>
#include <cstdlib> // srand()
#include <windows.h> // color(), outputPossition()
#include <stdlib.h> // color(), outputPossition()
#include <conio.h> // _getch()

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

// Prints game base frame
void printGameFrame()
{
	// Frame top
	outputPosition(1, 1);
	cout << char(218); // Top left corner
	for (int i = 0; i < 50; i++)
	{
		cout << char(196); // Horizontal line
	}
	cout << char(191) << endl; // Top right corner

	// Frame base
	for (int i = 2; i < 30; i++)
	{
		outputPosition(1, i);
		cout << char(179) << "                                                  " << char(179) << endl; // Vertical lines
	}

	// Frame bottom
	outputPosition(1, 30);
	cout << char(192); // Bottom left corner
	for (int i = 0; i < 50; i++)
	{
		cout << char(196); // Horizontal line
	}
	cout << char(217) << endl; // Bottom right corner

	// Frame top bar
	outputPosition(1, 3);
	cout << char(195); // Left frame connecting piece
	for (int i = 0; i < 50; i++)
	{
		cout << char(196); // Horizontal line
	}
	cout << char(180); // Right frame connecting piece

	// Frame bar symbols
	outputPosition(48, 2);
	cout << char(196) << " x"; // Horizontal line and X
}

// Prints warning popup box
void printPopup()
{
	// Popup top
	outputPosition(11, 12);
	cout << char(218); // Top left corner
	for (int i = 0; i < 30; i++)
	{
		cout << char(196); // Horizontal line
	}
	cout << char(191) << endl; // Top right corner

	// Popup base
	for (int i = 13; i < 19; i++)
	{
		outputPosition(11, i);
		cout << char(179) << "                              " << char(179) << endl; // Vertical lines
	}

	// Popup bottom
	outputPosition(11, 19);
	cout << char(192); // Bottom left corner
	for (int i = 0; i < 30; i++)
	{
		cout << char(196); // Horizontal line
	}
	cout << char(217) << endl; // Bottom right corner

	outputPosition(39, 13);
	cout << " x";
}

// Print team name logo
void printTeamNameLogo()
{
	outputPosition(8, 6);
	cout << "  _________ _      _____________  ____" << endl;
	outputPosition(8, 7);
	cout << " / ___/ __ \\ | /| / / __/ __/ _ \\/ __/" << endl;
	outputPosition(8, 8);
	cout << "/ /__/ /_/ / |/ |/ /\\ \\/ _// , _/\\ \\  " << endl;
	outputPosition(8, 9);
	cout << "\\___/\\____/|__/|__/___/___/_/|_/___/  " << endl;
}

// Print cow drawing
void printCow()
{
	outputPosition(14, 21);
	cout << "__n__n__" << endl;
	outputPosition(7, 22);
	cout << ".------`-\\00/-'" << endl;
	outputPosition(6, 23);
	cout << "/  ##  ## (oo)" << endl;
	outputPosition(5, 24);
	cout << "/ \\##  __  ./" << endl;
	outputPosition(8, 25);
	cout << "\\ /   \\ /" << endl;

}

// Print reverted cow drawing
void printRevertedCow()
{
	cout << " __n__n__           " << endl;
	cout << " '-/00\\-`------.    " << endl;
	cout << "   (oo) ##  ##  \\   " << endl;
	cout << "     \\.  __  ##/ \\  " << endl;
	cout << "      \\ /   \\ /     " << endl;

}

// Print bull drawing
void printBull()
{
	cout << "           __(__)__" << endl;
	cout << "    .------`-\\00/-'" << endl;
	cout << "   /         (oo)" << endl;
	cout << "  / \\    __  ./" << endl;
	cout << "     \\ /   \\ /" << endl;

}

// Print reverted bull drawing
void printRevertedBull()
{
	outputPosition(28, 24);
	cout << "__(__)__" << endl;
	outputPosition(28, 25);
	cout << "'-/00\\-`------." << endl;
	outputPosition(30, 26);
	cout << "(oo)         \\" << endl;
	outputPosition(32, 27);
	cout << "\\.  __    / \\" << endl;
	outputPosition(33, 28);
	cout << "\\ /   \\ /" << endl;

}

// Print grass drawing
void printGrass()
{
	outputPosition(2, 23);
	cout << "--^-----^------^^----^^-----^---^^--------^^----^-" << endl;
	outputPosition(2, 24);
	cout << "                    ^                     ^     " << endl;
	outputPosition(2, 25);
	cout << "                 ^^                     ^     " << endl;
	outputPosition(2, 27);
	cout << "   ^         ^        ^^           ^^         ^ " << endl;
	outputPosition(2, 28);
	cout << "        ^^           ^            ^    ^      " << endl;
	outputPosition(2, 29);
	cout << "  ^            ^             ^^             ^ " << endl;
}

// Prints all parts of the console game design
void printConsoleDesign()
{
	printGameFrame();
	printTeamNameLogo();
	printGrass();
	printCow();
	printRevertedBull();
}

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

// Generates random number in range of min & max
int getRandomNumber(int min, int max)
{
	static bool first = true;

	if (first)
	{
		srand(time(NULL));
		first = false;
	}

	return min + rand() % ((max + 1) - min);
}

// Check if guessed number is in range
bool isGuessingInRange(int guessing, int min, int max)
{
	if (guessing < min || guessing > max)
	{
		return false;
	}
	return true;
}

// Separate numbers to digits
void separateNumber(int numberOfDigits,
	int randomNumber[],
	int guessedNumber[],
	int number,
	int guessing)
{
	for (int i = 0; i < numberOfDigits; i++)
	{
		switch (numberOfDigits)
		{
		case 3:
			// Initializing digits of generated number to an array
			randomNumber[0] = number / 100;
			randomNumber[1] = number / 10 % 10;
			randomNumber[2] = number % 10;

			// Initializing digits of guessed number to an array
			guessedNumber[0] = guessing / 100;
			guessedNumber[1] = guessing / 10 % 10;
			guessedNumber[2] = guessing % 10;

			break;

		case 4:
			// Initializing digits of generated number to an array
			randomNumber[0] = number / 1000;
			randomNumber[1] = number / 100 % 10;
			randomNumber[2] = number / 10 % 10;
			randomNumber[3] = number % 10;

			// Initializing digits of guessed number to an array
			guessedNumber[0] = guessing / 1000;
			guessedNumber[1] = guessing / 100 % 10;
			guessedNumber[2] = guessing / 10 % 10;
			guessedNumber[3] = guessing % 10;

			break;

		case 5:
			// Initializing digits of generated number to an array
			randomNumber[0] = number / 10000;
			randomNumber[1] = number / 1000 % 10;
			randomNumber[2] = number / 100 % 10;
			randomNumber[3] = number / 10 % 10;
			randomNumber[4] = number % 10;

			// Initializing digits of guessed number to an array
			guessedNumber[0] = guessing / 10000;
			guessedNumber[1] = guessing / 1000 % 10;
			guessedNumber[2] = guessing / 100 % 10;
			guessedNumber[3] = guessing / 10 % 10;
			guessedNumber[4] = guessing % 10;

			break;

		default:
			break;
		}
	}
}

// Check if there are equal digits in a number
bool checkForEqualDigits(int num, int numberOfDigits)
{
	int arr[5] = { 0 };

	switch (numberOfDigits)
	{
	case 3:
		// Initializing digits of number to an array
		arr[0] = num / 100;
		arr[1] = num / 10 % 10;
		arr[2] = num % 10;

		break;

	case 4:
		// Initializing digits of number to an array
		arr[0] = num / 1000;
		arr[1] = num / 100 % 10;
		arr[2] = num / 10 % 10;
		arr[3] = num % 10;

		break;

	case 5:
		// Initializing digits of number to an array
		arr[0] = num / 10000;
		arr[1] = num / 1000 % 10;
		arr[2] = num / 100 % 10;
		arr[3] = num / 10 % 10;
		arr[4] = num % 10;

		break;

	default:
		break;
	}

	// Check for equal numbers
	for (int i = 0; i < numberOfDigits; i++)
	{
		for (int j = i + 1; j < numberOfDigits; j++)
		{
			if (arr[i] == arr[j])
			{
				return true;
			}
		}
	}

	return false;
}

// Game logic
void bullsAndCows(int min, int max, int numberOfDigits, string nickname)
{
	printConsoleDesign();

	int number = 0;
	int guessing = 0;
	int randomNumber[5] = { 0 }, guessedNumber[5] = { 0 };
	int cows = 0, bulls = 0;

	// Generate random number in range
	number = getRandomNumber(min, max);

	// Check if there are equal numbers
	while ((checkForEqualDigits(number, numberOfDigits)))
	{
		number = 0;
		number = getRandomNumber(min, max); // New generation
	}

	outputPosition(11, 13);
	cout << "Hi " << nickname << ", Enter your guessing!";

	outputPosition(24, 14);
	cout << number << endl;

	// Check if guessed number is valid
	while (!(isGuessingInRange(guessing, min, max)) || (checkForEqualDigits(guessing, numberOfDigits)))
	{
		// Guessed number input
		outputPosition(24, 15);
		cin >> guessing;

		if (!(isGuessingInRange(guessing, min, max)))
		{
			printPopup();
			outputPosition(13, 14);
			cout << "Your number is out of range";
			outputPosition(13, 15);
			cout << "Please enter number between";
			outputPosition(13, 16);
			cout << min << " & " << max;
			outputPosition(29, 18);
			cout << "Press Enter";

			guessing = 0;

			char pressedKey = ' ';
			pressedKey = _getch();

			while (pressedKey != '\r')
			{
				pressedKey = ' ';
				pressedKey = _getch();
			}

			system("CLS");
			printConsoleDesign();

			outputPosition(15, 13);
			cout << "Hi " << nickname << ", Enter again!";

			outputPosition(24, 14);
			cout << number << endl;
		}

		else if (checkForEqualDigits(guessing, numberOfDigits))
		{
			printPopup();
			outputPosition(13, 14);
			cout << "Your number has two or more";
			outputPosition(13, 15);
			cout << "equal digits";
			outputPosition(13, 16);
			cout << "Please enter valid number ";
			outputPosition(29, 18);
			cout << "Press Enter";

			guessing = 0;

			char pressedKey = ' ';
			pressedKey = _getch();

			while (pressedKey != '\r')
			{
				pressedKey = ' ';
				pressedKey = _getch();
			}

			system("CLS");
			printConsoleDesign();

			outputPosition(15, 13);
			cout << "Hi " << nickname << ", Enter again!";

			outputPosition(24, 14);
			cout << number << endl;
		}
	}

	while (number != guessing)
	{
		for (int i = 0; i < numberOfDigits; i++)
		{
			// Separate generated number and guessed number to numberOfDigits
			separateNumber(numberOfDigits,
				randomNumber,
				guessedNumber,
				number,
				guessing);

			// Check numberOfDigits
			for (int j = 0; j < numberOfDigits; j++)
			{
				// Check for bulls
				if (randomNumber[i] == guessedNumber[j] && i == j)
				{
					bulls++;
				}

				// Check for cows
				if (randomNumber[i] == guessedNumber[j] && i != j)
				{
					cows++;
				}
			}
		}

		printPopup();

		// Get guessed cows and bulls
		outputPosition(13, 14);
		cout << "Cows - " << cows;
		outputPosition(13, 15);
		cout << "Bulls - " << bulls;

		// Reset variables for new input
		cows = 0;
		bulls = 0;
		guessing = 0;

		// Input again
		outputPosition(13, 16);
		cout << "Please enter number again" << endl;

		outputPosition(29, 18);
		cout << "Press Enter";

		guessing = 0;

		char pressedKey = ' ';
		pressedKey = _getch();

		while (pressedKey != '\r')
		{
			pressedKey = ' ';
			pressedKey = _getch();
		}

		system("CLS");
		printConsoleDesign();

		outputPosition(15, 13);
		cout << "Hi " << nickname << ", Enter again!";

		outputPosition(24, 14);
		cout << number << endl;

		// Check if guessed number is valid
		while (!(isGuessingInRange(guessing, min, max)) || (checkForEqualDigits(guessing, numberOfDigits)))
		{
			// Guessed number input
			outputPosition(24, 15);
			cin >> guessing;

			if (!(isGuessingInRange(guessing, min, max)))
			{
				printPopup();
				outputPosition(13, 14);
				cout << "Your number is out of range";
				outputPosition(13, 15);
				cout << "Please enter number between";
				outputPosition(13, 16);
				cout << min << " & " << max;
				outputPosition(29, 18);
				cout << "Press Enter";

				guessing = 0;

				char pressedKey = ' ';
				pressedKey = _getch();

				while (pressedKey != '\r')
				{
					pressedKey = ' ';
					pressedKey = _getch();
				}

				system("CLS");
				printConsoleDesign();

				outputPosition(15, 13);
				cout << "Hi " << nickname << ", Enter again!";

				outputPosition(24, 14);
				cout << number << endl;
			}

			else if (checkForEqualDigits(guessing, numberOfDigits))
			{
				printPopup();
				outputPosition(13, 14);
				cout << "Your number has two or more";
				outputPosition(13, 15);
				cout << "equal digits";
				outputPosition(13, 16);
				cout << "Please enter valid number ";
				outputPosition(29, 18);
				cout << "Press Enter";

				guessing = 0;

				char pressedKey = ' ';
				pressedKey = _getch();

				while (pressedKey != '\r')
				{
					pressedKey = ' ';
					pressedKey = _getch();
				}

				system("CLS");
				printConsoleDesign();

				outputPosition(15, 13);
				cout << "Hi " << nickname << ", Enter again!";

				outputPosition(24, 14);
				cout << number << endl;
			}
		}
	}

	// Success message
	printPopup();
	outputPosition(13, 14);
	cout << "You've got it correct.";
	outputPosition(13, 15);
	cout << "Congrats!";
	outputPosition(15, 18);
	cout << "Press Enter to go back";

	guessing = 0;

	char pressedKey = ' ';
	pressedKey = _getch();

	while (pressedKey != '\r')
	{
		pressedKey = ' ';
		pressedKey = _getch();
	}
}

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

// Print out rules option
void printRules(string menuOptions[], int selectedOption)
{
	system("ClS");
	printConsoleDesign();

	// Print rules text
	outputPosition(7, 13);
	cout << "A computer gives a random number and if";
	outputPosition(3, 14);
	cout << "you guess a digit and its position in the number,";
	outputPosition(3, 15);
	cout << "you get a BULL, or if you don't guess its place";
	outputPosition(19, 16);
	cout << "you get a COW.";
	outputPosition(8, 17);
	cout << "That's why it's called bulls and cows. ";

	outputPosition(25, 20);
	cout << "Press Enter to go back!";

	char pressedKey = ' ';
	pressedKey = _getch();

	while (pressedKey != '\r')
	{
		pressedKey = ' ';
		pressedKey = _getch();
	}

	system("CLS");
	printMenuOptions(menuOptions, selectedOption);
}

void settings(string nickname, string menuOptions[])
{
	printConsoleDesign();

	outputPosition(22, 12);
	cout << "Hi " << nickname;
	outputPosition(17, 13);
	cout << "Welcome to settings!";

	outputPosition(16, 15);
	cout << "Change your nickname?";

	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;

	for (int i = 0; i < 2; i++)
	{
		// Print selected option
		if (i == selectedOption)
		{
			outputPosition(20, i + 16);
			cout << "-> " << menuOptions[i];
		}

		// Print not selected option
		else
		{
			outputPosition(20, i + 16);
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

		for (int i = 0; i < 2; i++)
		{
			// Print selected option
			if (i == selectedOption)
			{
				outputPosition(20, i + 16);
				cout << "-> " << menuOptions[i];
			}

			// Print not selected option
			else
			{
				outputPosition(20, i + 16);
				cout << "   " << menuOptions[i];
			}
		}

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Yes
			case 0:
				system("CLS");
				printPopup();

				break;

				// No - Go back
			case 1:
				system("CLS");
				exitStatement = false;
				break;

			default:
				break;
			}
		}
	}
}

// Moving arround the menu using keyboard
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
				settings(nickname, changeNicknameOptions);
				break;

				// Exit
			case 3:
				exitStatement = false;
				cout << "Press any key to exit";
				break;

			default:
				break;
			}
		}
	}
}

int main()
{
	// Nickname by default
	string nickname = "Player";

	// Array of strings with all the main menu options
	string mainMenuOptions[4] = { "Start", "Rules", "Settings", "Exit" };

	// Array of strings with all the difficulties menu options
	string gameDifficultyMenuOptions[4] = { "Easy", "Normal", "Hard", "Go back" };

	// Array of strings with all the change nickname menu options
	string changeNicknameOptions[2] = { "Yes", "No" };

	mainMenu(mainMenuOptions, gameDifficultyMenuOptions, changeNicknameOptions, nickname);
	return 0;
}