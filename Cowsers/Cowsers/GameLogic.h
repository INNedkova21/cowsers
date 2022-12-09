#pragma once
#include <string>
using namespace std;

// Generates random number in range of min & max
int getRandomNumber(int min, int max);
// Check if guessed number is in range
bool isGuessingInRange(int guessing, int min, int max);
// Separate numbers to digits
// Separate numbers to digits
void separateNumber(int numberOfDigits,
	int randomNumber[],
	int guessedNumber[],
	int number,
	int guessing);
// Check if there are equal digits in a number
bool checkForEqualDigits(int num, int numberOfDigits);
// Game logic
void bullsAndCows(int min, int max, int numberOfDigits, string nickname);