/*
Author: Kyle Smart
Class: CS2250
Date: 1/30/2020
Description: This code takes user input and creates a shape. The first use input will be on a menu, asking the use what shape they
want to make, the second input will be asking the user what will be the dimentions of the shape. After the shape is made, the use will
be taken back to the menu and asked again if they want to make a shape. This loop continues until the user enters the quit menu option.
*/

#include <iostream>

using namespace std;

//Function prototypes
void asciiSquare();
void asciiRightTriangle();
void asciiIsoscelesTriangle();
void asciiHourglass();
void asciiDiamond();
int menu();

int main()
{
	//Vars
	int userInput;

	//Printing out Welcome message
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;

	//Gets user input
	userInput = menu();

	//Calls proper method based on userInput
	while (userInput != 6)
	{
		switch (userInput)
		{
		case 1:
			asciiSquare();
			userInput = menu();
			break;
		case 2:
			asciiRightTriangle();
			userInput = menu();
			break;
		case 3:
			asciiIsoscelesTriangle();
			userInput = menu();
			break;
		case 4:
			asciiHourglass();
			userInput = menu();
			break;
		case 5:
			asciiDiamond();
			userInput = menu();
			break;
		default:
			cout << "You have not selected a valid menu option, please try again." << endl;
			cout << "Please select a menu option(1-6)" << endl;
			cin >> userInput;
			break;
		}
	}

	//Closing statement to user
	cout << "Thank you for using our application!  Good-bye!" << endl;
}

//Function for printing the menu
int menu()
{
	//Vars
	int userInput;

	//Menu to Print to the console
	cout << "********************************************************************************" << endl;
	cout << "* Please select a menu option(1 - 6) :" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "********************************************************************************" << endl;
	cout << "Please select a menu option(1-6)" << endl;
	cin >> userInput;

	return userInput;
}

//Function for making the square
void asciiSquare()
{
	//Vars
	int userSize;

	//Prompts user for size
	cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
	cin >> userSize;

	//Checks if user inputed a correct value
	while (userSize < 1 || userSize > 20)
	{
		cout << "You have not selected an appropriate size, please try again." << endl;
		cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
		cin >> userSize;
	}

	//Draws the square
	for (int i = 0; i < userSize; ++i)
	{
		for (int j = 0; j < userSize; ++j)
		{
			cout << '*';
		}
		cout << endl;
	}
}

//Function for making the Right Triangle
void asciiRightTriangle()
{
	//Vars
	int userSize;

	//Prompts user for size
	cout << "You have selected a right triangle!  What size should your right triangle be (1-20)?" << endl;
	cin >> userSize;

	//Checks if user inputed a correct value
	while (userSize < 1 || userSize > 20)
	{
		cout << "You have not selected an appropriate size, please try again." << endl;
		cout << "You have selected a right triangle!  What size should your right triangle be (1-20)?" << endl;
		cin >> userSize;
	}

	//Draws the right triangle
	for (int i = 0; i < userSize; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << '*';
		}
		cout << endl;
	}
}

//Funciton for making the Isosceles Triangle
void asciiIsoscelesTriangle()
{
	//Vars
	int userSize;
	int asterisksToPrint = 1;

	//Prompts user for size
	cout << "You have selected a isosceles triangle!  What size should your isosceles triangle be (1-20)?" << endl;
	cin >> userSize;

	while (userSize < 1 || userSize > 20)
	{
		cout << "You have not selected an appropriate size, please try again." << endl;
		cout << "You have selected a isosceles triangle!  What size should your isosceles triangle be (1-20)?" << endl;
		cin >> userSize;
	}

	//Draws the isosceles triangle
	for (int i = 0; i < userSize; ++i)
	{
		//The white space
		for (int j = userSize - i; j > 1; --j)
		{
			cout << " ";
		}

		//The *
		for (int k = asterisksToPrint; k > 0; --k)
		{
			cout << "*";
		}

		asterisksToPrint += 2;
		cout << endl;
	}

}

void asciiHourglass()
{
	//Vars
	int userSize;
	int asterisksToPrint;
	int sizeOfBase;

	//Prompts user for size
	cout << "You have selected an hourglass!  What size should your hourglass be (1-20)?" << endl;
	cin >> userSize;

	//Check for valid input
	while (userSize < 1 || userSize > 20)
	{
		cout << "You have not selected an appropriate size, please try again." << endl;
		cout << "You have selected an hourglass!  What size should your hourglass be (1-20)?" << endl;
		cin >> userSize;
	}

	//Set up vars for top hourglass
	asterisksToPrint = (userSize * 2) - 1;
	sizeOfBase = (userSize * 2) - 1;

	//Draws the top part of the hourglass
	for (int i = 0; i < userSize; ++i)
	{
		//The white space
		for (int j = asterisksToPrint; j < sizeOfBase; ++j)
		{
			cout << " ";
			++j;
		}

		//The *
		for (int k = asterisksToPrint; k > 0; --k)
		{
			cout << "*";
		}

		asterisksToPrint -= 2;
		cout << endl;
	}

	//Set up var for bottom hourglass
	asterisksToPrint = 3;

	//Draws the bottom part of the hourglass
	for (int i = 1; i < userSize; ++i)
	{
		//The white space
		for (int j = userSize - i; j > 1; --j)
		{
			cout << " ";
		}

		//The *
		for (int k = asterisksToPrint; k > 0; --k)
		{
			cout << "*";
		}

		asterisksToPrint += 2;
		cout << endl;
	}
}

void asciiDiamond()
{
	//Vars
	int userSize;
	int asterisksToPrint;
	int sizeOfBase;

	//Prompts user for size
	cout << "You have selected an diamond!  What size should your diamond be (1-20)?" << endl;
	cin >> userSize;

	//Check for valid input
	while (userSize < 1 || userSize > 20)
	{
		cout << "You have not selected an appropriate size, please try again." << endl;
		cout << "You have selected an diamond!  What size should your diamond be (1-20)?" << endl;
		cin >> userSize;
	}

	asterisksToPrint = 1;

	//Draws top part of diamond
	for (int i = 0; i < userSize; ++i)
	{
		//The white space
		for (int j = userSize - i; j > 1; --j)
		{
			cout << " ";
		}

		//The *
		for (int k = asterisksToPrint; k > 0; --k)
		{
			cout << "*";
		}

		asterisksToPrint += 2;
		cout << endl;
	}

	asterisksToPrint = (userSize * 2) - 3;
	sizeOfBase = (userSize * 2) - 1;
	//Draws bottom part of diamond
	for (int i = 1; i < userSize; ++i)
	{
		//The white space
		for (int j = asterisksToPrint; j < sizeOfBase; ++j)
		{
			cout << " ";
			++j;
		}

		//The *
		for (int k = asterisksToPrint; k > 0; --k)
		{
			cout << "*";
		}

		asterisksToPrint -= 2;
		cout << endl;
	}
}