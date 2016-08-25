/*********************************************************************
** Program Filename: InputValid
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: A program that takes user input and outputs averages and sums.
** Input: User Input
** Output: Verified types
** Citations: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
********************************************************************/


#include "InputValid.hpp"

InputValid::InputValid()
{
	input = "";
}
/*********************************************************************
** Function:  validateInt
** Description: validates numbers
** Parameters: void
** Pre-Conditions: getChoice()
** Post-Conditions: Switch
** Citation: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/
int InputValid::validateInt()
{

	int myNumber = 0;
	bool isNotNumber = true;
	while (isNotNumber) {
		// cout << "Please enter a valid number: ";

		getline(cin, input);

		for (int i = 0; i < input.length(); i++) {

			if (isdigit(input[i]) == false) {

				cout << "Invalid number, please try again" << endl;
				break;
			}
			if (i == input.length() - 1) {
				isNotNumber = false;

			}

		}


	}
	stringstream myStream(input);
	myStream >> myNumber;
	return myNumber;


}
/*********************************************************************
** Function:  validateDouble
** Description: gets validates array Entries as doubles
** Parameters: void
** Pre-Conditions: getChoice()
** Post-Conditions: Switch
** Citation: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/

double InputValid::validateDouble()
{

	double myNumber = 0.0;

	while (true) {
		// cout << "Please enter a valid number: ";

		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
			break;
		cout << "Invalid number, please try again" << endl;
	}
	return  myNumber;


}

/*********************************************************************
** Function:  validatePrice
** Description: gets validates Entries as prices of Format XXXX.00
** Parameters: void
** Pre-Conditions: getChoice()
** Post-Conditions: Switch
** Citation: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/

double InputValid::validatePrice()
{

	double myNumber = 0.0;
	bool isNotPrice = true;
	while (isNotPrice) {
		// cout << "Please enter a valid number: ";

		getline(cin, input);

		for (int i = 0; i < input.length(); i++) {
			if (input[input.length() - 3] != '.') {

				cout << "Invalid Price, please try again. Must be in the form of standard U.S. Price" << endl;
				break;

			}

			if (i != input.length() - 3) {
				if (isdigit(input[i]) == false) {

					cout << "Invalid Price, please try again" << endl;
					i == input.length();
				}
				if (i == input.length() - 1) {
					isNotPrice = false;

				}

			}
		}


	}
	stringstream myStream(input);
	myStream >> myNumber;
	return myNumber;


}

/*********************************************************************
** Function:  validateString
** Description: Allows a string to be entered with spaces
** Parameters: void
** Pre-Conditions: variable
** Post-Conditions: variable
** Citation: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/
string InputValid::validateString()
{

	
	
	bool isNotAlphaNumeric = true;
	while (isNotAlphaNumeric) {
		

		getline(cin, input);

		for (int i = 0; i < input.length(); i++) {

			if (isalnum(input[i]) == false && isspace(input[i]) == false && ispunct(input[i]) == false){

				cout << "Invalid String, please try again" << endl;
				break;
			}
			if (i == input.length() - 1) {
				
				isNotAlphaNumeric = false;

			}

		}


	}
	
	return input;
}

/*********************************************************************
** Function:  validateChar
** Description: Allows a single char to be entered
** Parameters: void
** Pre-Conditions: variable
** Post-Conditions: variable
** Citation: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/

char InputValid::validateChar()
{
	char myChar = { 0 };

	while (true) {

		getline(cin, input);

		if (input.length() == 1) {
			myChar = input[0];
			break;
		}

		cout << "Invalid character, please try again" << endl;
	}

	return myChar;

}

