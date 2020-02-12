/* 
	Author: Kyle Smart
	Assignment: Caesar Cipher
	Description: Using functions, pass by value, pass by reference, and pass by const-reference,
	make a Caesar Cipher that encrypts user inputed messages by a user inputed shift amount,
	decrypt a user inputed message by a user inputed shift amount, and brute forces a user inputed
	message.
	Due: 2/12/2020
	Class: CS2250
*/

#include <iostream>
#include <string>

using namespace std;

//Constants
const string ENCRYPT_MSG = "Please enter the message to encrypt: ";
const string DECRYPT_MSG = "Please enter the message to decrypt: ";

//Method prototypes
void encrypt(string& toEncrypt, int shiftAmount);
void decrypt(string& toDecrypt, int shiftAmount);
void bruteForce(string& toBruteForce);
int menu();
int askForShiftAmount();
void askForString(string& userInput, const string& messageToDisplay);

int main()
{
	//Vars
	int userInput;
	string userString;
	int userShiftAmount;

	//Welcome message
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	do 
	{
		//Get user input for the menu
		userInput = menu();
		
		//Take valid user input and run the appropreate method
		switch (userInput) 
		{
			case 1: 
				askForString(userString, ENCRYPT_MSG);
				userShiftAmount = askForShiftAmount();
				encrypt(userString, userShiftAmount);
				break;
			case 2: 
				askForString(userString, DECRYPT_MSG);
				userShiftAmount = askForShiftAmount();
				decrypt(userString, userShiftAmount);
				cout << "Decrypted as: " << endl;
				cout << userString << endl;
				break;
			case 3:
				askForString(userString, DECRYPT_MSG);
				cout << "Decrypted as: " << endl;
				bruteForce(userString);
				break;
			case 4:
				break;
			default:
				cout << "ERROR" << endl;
				break;
		}
	}
	//Get user input
	while (userInput != 4);

	//Sends goodbye message
	cout << "Thank you Caesar!  See ya!" << endl;

	return 0;
}


//This method encrypts a message inputed from the user
void encrypt(string& toEncrypt, int shiftAmount) 
{
	while (shiftAmount < 1 || shiftAmount > 25) 
	{
		cout << "Invalid choice, Please enter the shift value (1-25): " << endl;
		cin >> shiftAmount;
	}


	for (int i = 0; i < toEncrypt.length(); ++i)
	{
		if ((char)(toEncrypt[i]) > '@' && (char)(toEncrypt[i]) < '[')
		{
			toEncrypt[i] += shiftAmount;

			if ((char)(toEncrypt[i]) > 'Z')
			{
				toEncrypt[i] -= 26;
			}
		}
		else if ((char)(toEncrypt[i]) > '`' && (char)(toEncrypt[i]) < '{')
		{
			toEncrypt[i] += shiftAmount;

			//Since the lowercase letters are near the end of the ascii table I also check for negatives
			if ((char)(toEncrypt[i]) > 'z' || (char)(toEncrypt[i]) < 0)
			{
				toEncrypt[i] -= 26;
			}
		}
	}

	//Encrypted message printed to user
	cout << "Encrypted as: " << endl;
	cout << toEncrypt << endl;
}


//This function decrypts the message for the user
void decrypt(string& toDecrypt, int shiftAmount)
{
	//Checks for valid input for shift amount
	while (shiftAmount < 1 || shiftAmount > 25)
	{
		cout << "Invalid choice, Please enter the shift value (1-25): " << endl;
		cin >> shiftAmount;
	}

	for (int i = 0; i < toDecrypt.length(); ++i)
	{
		if ((char)(toDecrypt[i]) > '@' && (char)(toDecrypt[i]) < '[')
		{
			toDecrypt[i] -= shiftAmount;

			if (toDecrypt[i] < 'A')
			{
				toDecrypt[i] += 26;
			}
		}
		else if ((char)(toDecrypt[i]) > '`' && (char)(toDecrypt[i]) < '{')
		{
			toDecrypt[i] -= shiftAmount;

			if (toDecrypt[i] < 'a')
			{
				toDecrypt[i] += 26;
			}
		}
	}	
}


//This function brute forces a message to decrypt by passing it to the decrypt function 25 times
void bruteForce(string& toBruteForce)
{
	for (int i = 1; i < 26; ++i)
	{
		decrypt(toBruteForce, 1);

		//Sends each decrypted message to user
		cout << toBruteForce << endl;
	}
}


//This method prints out the menu and asks the user for input for said menu
int menu() 
{
	int userInput;
	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "**************************************" << endl;
	cout << "Please make a menu selection(1-4):" << endl;
	cin >> userInput;
	
	while (userInput < 1 || userInput > 4) 
	{
		cout << "Invalid choice, Please make a menu selection (1-4): " << endl;
		cin >> userInput;
	}

	//Eats the white space made by cin
	cin.ignore();
	
	return userInput;
}

//This method asks the user for the shift amount
int askForShiftAmount()
{
	int shiftAmount;

	cout << "Please enter the shift value (1-25): " << endl;
	cin >> shiftAmount;

	return shiftAmount;
}

//This method asks the user for the strings and displays the correct message to the user
void askForString(string& userString, const string& messageToDisplay)
{
	if (messageToDisplay == ENCRYPT_MSG) 
	{
		cout << ENCRYPT_MSG << endl;
	}
	else 
	{
		cout << DECRYPT_MSG << endl;
	}

	getline(cin, userString);
}