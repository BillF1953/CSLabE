/*********************************************************************
** Program Filename: main LabE
** Author: Tyler Forrester
** Date: 7/22/2016
** Description: A program that develops a circular node structure to hold chars
** Input: User Input
** Output: Print Chars
** Citation : C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
**********************************************************************/


#include <iostream>
#include "InputValid.hpp"


/*********************************************************************
** Structure: Node
** Description: vessel carrying a char with the ability to link
**Initializes char and * to node to NULL
** Pre-Conditions: Creation of Queue, main()
** Post-Conditions: rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

struct node {
	node() : character('\0'), next(NULL){}  // node constructor
	char character;  // item contained
	node *next; // pointer to next node in list
};


bool isEmpty(node*head);
char menu(); 
void insertAsFirstElement(node  *&head, node *&back, char character); 
void insertNode(node *&head, node *&back, char character); 
void showList(node * &head);
int getChoice(InputValid valid);
bool showHead(node *&head);
bool remove(node *&head, node *&last);
bool insert(node *&head, node *&back, char character);

/*********************************************************************
** Function: main
** Description: Displays menu of options for adding chars to queue, showing and removing chars
** Paramters: none
** Pre-Conditions: Start of program
** Post-Conditions: Rest of program
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
** C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/



int main() {
	InputValid valid = InputValid();   // bring in validation class
	node *head = NULL;  // initializes head pointer to null
	node *back = NULL; // intializes back pointer to null
	
	cout << "\nWelcome to Assignment1\n";
	do {
		
		menu(); // display menu
		int choice = getChoice(valid); // get choice
		char character; // initialize char
		
		if (choice == 4) {

			break;   // quit on 4 

		}
	
		switch (choice) // switch 
		{

		case 1: cout << "Please enter a single Character: ";  // Prompts user for a char
			character = valid.validateChar();   // uses input validation file from Lab A to validate char
			if (!(insert(head, back, character))) {  // tries to insert char into an empty character in linked structure
				insertNode(head, back, character); // creates node to store char
			}   
			break; 
		case 2: if (isEmpty(head)) {  // check if node has been created

				cout << "This queue is empty";

				}
				else {
					showHead(head); // displays head and removes char for the container
				}
				break; 
		case 3: showList(head);  // displays head and rest of queue removing the char stored in every containers
			break; 
		}



	} while (true); // breaks on 4

	while(remove(head, back)); // frees allocated memory on exit

}

/*********************************************************************
** Function: isEmpty
** Description: Checks if a Node has been created
** Paramters: node * head
** Pre-Conditions: case 2 and case 3 of switch 
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/
	
bool isEmpty(node*head) {

	if (head == NULL)
		return true;
	else
		return false; 

}
/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options for Sum Game
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


char menu() {


	cout << "\nPlease Select a Number\n\n";
	cout << "1. Add a Char to your Queue.\n";
	cout << "2. Display and Remove the first item in your Queue.\n";
	cout << "3. Display and Remove the entire Queue.\n";
	cout << "4. Quit the Program.\n\n";

	
}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {

	int choice;
	choice = valid.validateInt();
	while (choice < 1 || choice > 4) {

		cout << "The only valid choices are 1-4. Please re-enter.\n";
		choice = valid.validateInt();

	}

	return choice;


}
/*********************************************************************
** Function: remove
** Description: frees memory on exit
** Paramters: node * &head, node *&back
** Pre-Conditions: Quit the Program
** Post-Conditions: Exit
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool remove(node *&head, node *&last) {

	if (isEmpty(head)){
		//cout << "A node never existed" << endl;

		}
	else if (head == last) { // last delete when pointer->next points to itself
		delete head; // delete
		head == NULL;  // set head to Null
		last == NULL;  // set last to null
		return false; // return false to break loop
	}
	
	else
	{

		node *temp = head;  // set node pointer equal to head
		head = head->next;  // set move head to next node
		delete temp;  // delete old head
		return true;  // continue to delete

	}


}


/*********************************************************************
** Function: insert
** Description: searches structure for null node, if found sets character = to new character, and returns true
** Paramters: node * &head, node *&back, char character
** Pre-Conditions: Select of Case 1 Insert Char
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool insert(node *& head, node *& back, char character)
{ 
	if (isEmpty(head)) { // checks if any nodes are present

		return false;  // returns false

	}
	if (head->character == '\0') { // if head has null character 

		head->character = character;  // set head character to passed character
		return true; // return true 
	}

	else if (head != back) { // if more than one more node 

		node * current = head->next;  // set current equal to next node 

		while (current != head) {   // while current not equal to first node

			if (current->character == '\0') {  // search for null char
				
				current->character = character;   // set value to new character
				return true;  // return true
			
			}

			current = current->next;  // move to next node in structure

		}
	
	}
	
	else {

		return false;  // otherwise return that value was not inserted into an old node

	}



}


/*********************************************************************
** Function: insertAsFirstElement
** Description: creates node, inserts char, points all pointer to first node
** Paramters: node * &head, node *&back, char charater
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void insertAsFirstElement(node  *&head, node *&back, char character) {
	
	node *temp = new node;  // create first node for first element
	temp->character = character;  // assign value to temps char
	temp->next = head;   // assign s point next to itself 
	head = temp;   // head (start) = temp 
	back = temp;  // back (end) = temp
	
}

/*********************************************************************
** Function: insertNodes
** Description: calls firstElement to create first node or creates node and points back->next to new variable, keeps temp->next pointed to head
** sets back to new node
** Paramters: node * &head, node *&back, char character
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/
void insertNode(node *&head, node *&back, char character) { // pass by reference so they can be modified

	if (isEmpty(head)){
		insertAsFirstElement(head, back, character); // if empty calls insert As FirstElement //consider doing this in main
		
	} 
	else {
		node *temp = new node;  // creates new node
		temp->character = character;  // assigns pass character
		temp->next = head;  // assigns temp->next to head (i.e. creates a circle with the last element always point to the first element
		back->next = temp;   // moves the last pointer to point at the new temp
		back = temp;   // sets back to this node


	}

}

/*********************************************************************
** Function:  showHead()
** Description: If character has been removed, deals with empty queue cases otherwise prints out and sets char to '\0'
** Paramters: node * &head
** Pre-Conditions: showList(), choice = 2 or 3 
** Post-Conditions: Rest of program
** Citation: 
*********************************************************************/

bool showHead(node *&head){ // passes head
		
	if (head->character == '\0') {

		if (isEmpty(head->next)) {
			cout << "The queue is empty.\n"; // list is empty when head is empty and next node doesn't exist
			return false;
		}
		else {
			if (head->next->character == '\0') {

				cout << "The queue is empty.\n"; // list is empty when both head and next node character are null
				return false; 
			}
			
		}
	}
	else {
		cout << "The first member of the queue is " << head->character << ". "; // Presents head as the first member of the queue
		head->character = '\0';

		if (isEmpty(head->next)){
			return false;   // if only one node returs false 
		}
		else {
			return true;  // otherwise returns ture 
		}
	}
	
}

/*********************************************************************
** Function:  showList()
** Description: Covers 4 control cases: Empty Queue,  1 node queue, all chars remove, and displays existing chars 
** Paramters: node * &head, 
** Pre-Conditions: choice 3
** Post-Conditions: Rest of program
** Citation:  C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/


void showList(node * &head) {  

	if (!(isEmpty(head))) {  // if head is empty skip this section

		if (showHead(head)) { // uses showhead to check for multiple nodes 

			node * current = head->next;  // set point to next item in linked structure
						
			 if (current->character == '\0') {  // if linked structure characters have already been removed 

			//	cout << "The rest of this structure stores no characters" << endl; testing
				
			 }	

			 else {
				 cout << "Members of the queue are"; // poorly formatted display of more members. 

				 while (current != head && current->character != '\0') { // while current is moving around the stucture and is not null

					 cout << " " << current->character ;   // display character
					 current->character = '\0';   //  null character
					 current = current->next;   // move through list 

				 }

				 cout << "." << endl;
			 }
		}
		else {

		//	cout << "The head is the only node in the queue.\n"; // testing linked structure only has one node

		}
	}
	else {
		
		cout << "This queue is empty";  // if no nodes have been initialized

	}


}