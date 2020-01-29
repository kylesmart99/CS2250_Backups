/*
Author: Kyle Smart
Class: CS2250
Assignment: Lab: GPA
Description: This program prompts the user and asks for their name, age, the school they are currently enrolled in, and their GPA. Depending on the value of the users GPA will change the 
message sent to the user. The GPA will be checked if the GPA is above 3.0, above 2.0, and less than 2.0. 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Declaring Vars
	string name;
	int age;
	float gpa;
	string school;
	
	//Ask the user for their name, age, gpa, and school.
	cout << "Please enter your full name (first middle last)" << endl;
	getline(cin, name);
	
	cout << "Please enter your age" << endl;
	cin >> age;

	cout << "Please enter your gpa" << endl;
	cin >> gpa;
	cin.ignore();

	cout << "Please enter your school name" << endl;
	getline(cin, school);

	//Check the users gpa and sent the respective message to the user
	if (gpa >= 3.0) 
	{
		cout << "Welcome " << name << ", age " << age << ". Congratulations on your gpa of " << gpa << " at " << school << endl;
	}
	else if (gpa >= 2.0) 
	{
		cout << "Welcome " << name << ", age " << age << ". You can graduate with your current gpa of " << gpa << ", but might want to try a little harder at " << school << endl;
	}
	else 
	{
		cout << "Welcome " << name << ", age " << age << ". Unfortunately, you can not graduate with your current gpa of " << gpa << " at " << school << endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
