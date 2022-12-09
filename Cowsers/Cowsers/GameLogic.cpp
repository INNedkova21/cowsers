#include <iostream>
#include <cstdlib> // srand()
#include <conio.h> // _getch()
#include "drawings.h"
#include "output.h"

using namespace std;

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

	// Check if there are equal digits
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

		// Out of range digits warning
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

		// Equal digits warning
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

		// Press enter to go back
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

			// Out of range digits warning
			if (!(isGuessingInRange(guessing, min, max)))
			{
				printPopup();
				outputPosition(13, 14);
				cout << "Your number is out of range";
				outputPosition(13, 15);
				cout << "Please enter number between";
				outputPosition(13, 16);
				cout << min << " & " << max;

				// Press enter to go back
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

			// Equal digits warning
			else if (checkForEqualDigits(guessing, numberOfDigits))
			{
				printPopup();
				outputPosition(13, 14);
				cout << "Your number has two or more";
				outputPosition(13, 15);
				cout << "equal digits";
				outputPosition(13, 16);
				cout << "Please enter valid number ";

				// Press enter to go back
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

	// Press enter to go back
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