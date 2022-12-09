#include <iostream>
#include <string>
#include "output.h"
#include "drawings.h"
#include "menus.h"

using namespace std;

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