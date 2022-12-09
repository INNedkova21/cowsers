#pragma once
#include <string>
using namespace std;

// Print all menu options 
void printMenuOptions(string arrWithOptions[], int selectedOption);
// Move arround the difficulties menu using keyboard
void gameDifficultyMenu(string gameDifficultyMenuOptions[], string mainMenuOptions[], string nickname);
// Move arround the main menu using keyboard
void mainMenu(string mainMenuOptions[], string gameDifficultyMenuOptions[], string changeNicknameOptions[], string nickname);