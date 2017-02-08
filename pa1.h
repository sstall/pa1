//pa1.h
//Samuel Stall
//Contains the information of the magicSquare object and defines its functions
#include <iostream>
#include <stdio.h>

//Defines the object magicSquare
class magicSquare {

private:
	int size;
	int ** sq;
	makeSquare();
	void rowSums();
	void colSums();
	void diaSums();
	int** tempArray();
	void deleteArray(int** arr);

public:
	magicSquare(int size);
	printSquare();
	switchLRSquare();
	switchTBSquare();
	checkSums();
};
//Constructor for magicSquare, takes in an int and then calls the function makeSquare() on the magicSquare being constructed
/**
@param int size
*/
magicSquare::magicSquare(int size) {
	this->size = size;
	makeSquare();
}
//Defines the values for the magicSquare the function is called onto
magicSquare::makeSquare() {

	sq = new int*[size];
	for(int i = 0; i < size; i++) {
		sq[i] = new int[size];
	}
//Initializes all values in the size of the magicSquare to zero
	for(int i = 0; i < size; i++)	{
		for(int j = 0; j < size; j++) {
			sq[i][j] = 0;
		}
	}

	//Sets first postion for values for the magicSquare and sets value to initial value of 1
	int x = size / 2;
	int y = size - 1;
	int value = 1;

	while(value <= size * size) {

		//Checks if both coordinates are out of bounds
		if(x == -1 && y == size) {
			x = 0;
			y = size - 2;
		}
		else{
			//Checks if the x coordinate decremented out of bounds and wraps around if it does
			if(x < 0) {
				x = size - 1;
			}
			//Checks if the y coordinate incremented out of bounds and wraps around if it does
			if(y == size) {
				y = 0;
			}
		}
		//Checks if there is a value already containted at the current position
		if(sq[x][y] != 0) {
			++x;
			y -= 2;
		}

		//Sets the current position's value to the current value and increments value
		sq[x][y] = value++;


		//Sets the position to the next position
		--x;
		++y;
	}

}

//Prints out all values contained in a magicSquare's array
magicSquare::printSquare() {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%4d", sq[i][j]);
		}
		std::cout << std::endl;
	}

	checkSums();
}

//Switches the left and right columns of a magicSquare's array
magicSquare::switchLRSquare() {
	int** temp = tempArray();
	for(int i = 0; i < size; i++) {
		temp[i][0] = sq[i][0];
		sq[i][0] = sq[i][size - 1];
		sq[i][size - 1] = temp[i][0];
	}
	deleteArray(temp);
}

//Switches the top and bottom rows of a magicSquare's array
magicSquare::switchTBSquare() {
	int** temp = tempArray();
	for(int j = 0; j < size; j++) {
		temp[0][j] = sq[0][j];
		sq[0][j] = sq[size - 1][j];
		sq[size - 1][j] = temp[0][j];
	}
	deleteArray(temp);
}

//Creates temporary two dimensional array
int** magicSquare::tempArray() {
	int** temp = new int*[size];
	for(int i = 0; i < size; i++) {
		temp[i] = new int[size];
	}
	//Initializes all values in the size of the magicSquare to zero
	for(int i = 0; i < size; i++)	{
		for(int j = 0; j < size; j++) {
			temp[i][j] = 0;
		}
	
	}

	return temp;
}

void magicSquare::deleteArray(int** arr) {
	for(int i = 0; i < size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

//Checks all sums by row, column, and diagonal
magicSquare::checkSums() {
	rowSums();
	colSums();
	diaSums();
}


//Prints out the sum of each row
void magicSquare::rowSums() {
	std::cout << "Checking the sums of every row:	      ";
	int sum = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			sum += sq[i][j];
		}
	std::cout << sum << " ";
	sum = 0;
	}
	std::cout << std::endl;
}

//Prints out the sum of each column
void magicSquare::colSums() {
	std::cout << "Checking the sums of every column:    ";
	int sum = 0;
	for(int j = 0; j < size; j++) {
		for(int i = 0; i < size; i++) {
			sum += sq[i][j];
		}
	std::cout << sum << " ";
	sum = 0;
	}
	std::cout << std::endl;
}

//Prints out the sums of each diagonal
void magicSquare::diaSums() {
	std::cout << "Checking the sums of every diagonal:  ";
	int sum = 0;
	for(int i = 0, j = 0; i < size && j < size; i++, j++) {
		sum += sq[i][j];
	}
	std::cout << sum << " ";

	sum = 0;
	for(int i = size - 1, j = size - 1; i > -1, j > -1; i--, j--) {
		sum += sq[i][j];
	}
	std::cout << sum << std::endl;
}