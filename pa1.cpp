//pa1.cpp COP3503 Project 1
//Samuel Stall
//Creates a magic square the size specified by the user and then prints out the sums of the magic square
#include <iostream>
#include <stdlib.h>
#include "pa1.h"

//Declares each function before main
int userInput();
bool isOdd(int n);

int main() {
	//Calls the function userInput() to get the size of the magic square
	int size = userInput();

	//Constructs an object of type magicSquare using the size given by the user
	magicSquare sq1 = magicSquare(size);

	//Prints out all the values in the magic square
	std::cout << "Magic Square #1 is: " << std::endl;
	sq1.printSquare();
	std::cout << std::endl;

	//Switches some values of the magic square and then prints the values out
	std::cout << "Magic Square #2 is: " << std::endl;
	sq1.switchLRSquare();
	sq1.switchTBSquare();
	sq1.printSquare();
	std::cout << std::endl;

	//Does some switching again and print out
	std::cout << "Magic Square #3 is: " << std::endl;
	sq1.switchLRSquare();
	sq1.printSquare();
	std::cout << std::endl;

	//Does some more switching and print out
	std::cout << "Magic Square #4 is: " << std::endl;
	sq1.switchTBSquare();
	sq1.switchLRSquare();
	sq1.printSquare();
	std::cout << std::endl;

	return 0;
}

//Takes in user input and checks that it is an int and odd, loops until a valid value was enetered, and then returns the int
int userInput() {
	char inputC[128];
	int inputI = 0;
	do{
		std::cout << "Enter the size of a magic square: ";
		std::cin >> inputC;
		std::cout << std::endl;

		//Converts the character array into an int, returning 0 if it wasn't able to
		inputI = atoi(inputC);

		if(inputI == 0) {
			std::cout << "Please enter a valid input. Odd integers 1-15." << std::endl;
			continue;
		}
		else if(inputI < 1 || inputI > 15) {
			std::cout << "Please enter a valid input. Odd integers 1-15." << std::endl;
			continue;
		}
		else if(!isOdd(inputI)) {
			std::cout << "Please enter a valid input. Odd integers 1-15." << std::endl;
			continue;
		}

	}while((inputI < 1 || inputI > 15) || !isOdd(inputI));

	return inputI;
}

//Checks if an integer is odd
bool isOdd(int n) {
	bool odd = false;
	for(int i = 1; i <= 15; i += 2) {
		if(n == i) {
			odd = true;
		}
	}

	return odd;
}


