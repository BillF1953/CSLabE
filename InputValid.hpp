/*********************************************************************
** Program Filename: InputValid Header
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: A program that takes user input and outputs averages and sums.
** Input: User Input
** Output: Verified types
** Citations: "Using cin to get user input." Username "Zaita" Dec 1, 2008 at 6:15pm http://www.cplusplus.com/forum/articles/6046/
********************************************************************/



#ifndef INPUTVALID_HPP
#define INPUTVALID_HPP

#include<ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::getline;
using std::endl;
using std::cout;
using std::cin;
using std::stringstream;


class InputValid {

private:
	string input;

public:
	InputValid();
	int validateInt();
	double validateDouble();
	double validatePrice();
	string validateString();
	char validateChar();



};

#endif // !1
