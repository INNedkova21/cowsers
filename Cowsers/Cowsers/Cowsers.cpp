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

// Print all menu options 
void printMenuOptions(string arrWithOptions[], int numOfOptions, int selectedOption)
{
	for (int i = 0; i < numOfOptions; i++)
	{
		// Print selected option
		if (i == selectedOption)
		{
			outputPosition(2, i + 1);
			cout << "-> " << arrWithOptions[i];
		}

		// Print not selected option
		else
		{
			outputPosition(2, i + 1);
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
void bullsAndCows(int min, int max, int numberOfDigits)
{
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

	cout << number << endl;

	// Guessed number input
	cin >> guessing;

	// Check if guessed number is in range
	while (!(isGuessingInRange(guessing, min, max)))
	{
		cout << "Your number is out of range" << endl;
		cout << "Please enter a number between " << min << " & " << max << endl;

		guessing = 0;
		cin >> guessing; // If not - input again
	}

	// Check if there are equal digits in a number
	while ((checkForEqualDigits(guessing, numberOfDigits)))
	{
		cout << "Your number has two or more equal digits" << endl;
		cout << "Please enter a valid number " << endl;

		guessing = 0;
		cin >> guessing; // If yes - input again
	}

	while (number != guessing)
	{
		for (int i = 0; i < numberOfDigits; i++)
		{
			// Separate generated number and guessed number to numberOfDigits
			separateNumber(numberOfDigits, randomNumber, guessedNumber, number, guessing);

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

		// Get guessed cows and bulls
		cout << "Cows - " << cows << endl;
		cout << "Bulls - " << bulls << endl;

		// Reset variables for new input
		cows = 0;
		bulls = 0;
		guessing = 0;

		// Input again
		cout << "Please enter a number again" << endl;
		cin >> guessing;

		// Check if guessed number is in range
		while (!(isGuessingInRange(guessing, min, max)))
		{
			cout << "Your number is out of range" << endl;
			cout << "Please enter a number between " << min << " & " << max << endl;

			guessing = 0;
			cin >> guessing; // If not - input again
		}

		//Check if there are equal digits in a number
		while ((checkForEqualDigits(guessing, numberOfDigits)))
		{
			cout << "Your number has two or more equal digits" << endl;
			cout << "Please enter a valid number " << endl;

			guessing = 0;
			cin >> guessing; // If yes - input again
		}
	}

	// Success message
	cout << "You've got it correct. Congrats!" << endl;
}

void gameDifficultyMenu(string arr[], int n)
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
		if (selectedOption != n - 1 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		printMenuOptions(arr, n, selectedOption);

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Easy mode
			case 0:
				system("CLS");

				bullsAndCows(100, 999, 3);

				break;

				// Normal mode
			case 1:
				system("CLS");
				bullsAndCows(1000, 9999, 4);
				break;

				// Hard mode
			case 2:
				system("CLS");
				bullsAndCows(10000, 99999, 5);
				break;

			default:
				break;
			}
		}
	}
}

// Moving arround the menu using keyboard
void mainMenu(string mainMenuOptions[],
	int mainMenuOptionsSize,
	string gameDifficultyMenuOptions[],
	int gameDifficultyMenuOptionsSize)
{
	int selectedOption = 0;
	char pressedKey = ' ';

	printMenuOptions(mainMenuOptions,
		mainMenuOptionsSize,
		selectedOption);

	while (true)
	{
		pressedKey = _getch();

		// Moving up through the menu
		if (selectedOption != 0 && pressedKey == (char)72)
		{
			selectedOption--;
		}

		// Moving down through the menu
		if (selectedOption != mainMenuOptionsSize - 1 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		printMenuOptions(mainMenuOptions,
			mainMenuOptionsSize,
			selectedOption);

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
			case 0:
				system("CLS");
				gameDifficultyMenu(gameDifficultyMenuOptions,
					gameDifficultyMenuOptionsSize);
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
	// Array of strings with all the game numberOfDigits menu options
	string gameDifficultyMenuOptions[3] = { "Easy", "Normal", "Hard" };

	mainMenu(mainMenuOptions, 4, gameDifficultyMenuOptions, 3);
}