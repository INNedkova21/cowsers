#include <iostream>
#include <conio.h> // _getch()
#include "drawings.h"
#include "output.h"
#include "menus.h"

using namespace std;

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

	// Press enter to go back
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