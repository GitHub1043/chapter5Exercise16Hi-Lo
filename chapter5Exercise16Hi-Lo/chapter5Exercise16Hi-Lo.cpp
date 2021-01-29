// This program simulates a Hi-Lo game where the user guesses whether a number is high or low
// Written by: Ayden Holgate
// Date: Jan. 29, 2021

// chapter5Exercise16Hi-Lo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void HiLo(int number, int risk, int& points){
	int predict, HiLo;

	cout << "Predict (1 = high, 0 = low): ";
	cin >> predict;

	while (predict < 0 || predict > 1){
		cout << "Please enter a valid number." << endl;
		cout << "Predict (1 = high, 0 = low): ";
		cin >> predict;
}

	cout << "The number is " << number << endl;

	if(number >= 1 && number <= 6){
		HiLo  = 0;
	}
	else if(number >= 8 && number <= 13){
		HiLo = 1;
	}
	else if (number == 7){
		HiLo = 3; // This is to ensure the user will lose points. The user cannot enter anything other than 0 or 1 for their prediction, making sure they never put '3'.
	}

	if((predict == 0 && HiLo == 0) || (predict == 1 && HiLo == 1)){
		points = points + (risk * 2);
		cout << "You Win." << endl;
	}
	else{
		points = points - risk;
		cout << "You Lose." << endl;
	}

	cout << "You have " << points << " points" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{// Start of program
	int number, risk, points = 1000;
	char play = 'Y';

	srand(time(0));

	cout << "You have " << points << " points" << endl;

	while(play == 'Y'){
		cout << "How many points to risk: ";
		cin >> risk;

		number = rand() % 13 + 1;
	
		HiLo(number, risk, points);

		cout << "Play again? (Y/N) ";
		cin >> play;
	}

	cout << "Final Score: " << points << endl;

	return 0;
}// End of program

