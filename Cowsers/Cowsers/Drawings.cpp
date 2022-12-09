#include <iostream>
#include "Output.h"

using namespace std;

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

// Prints popup box
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

// Print bull drawing
void printBull()
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
	printBull();
}
