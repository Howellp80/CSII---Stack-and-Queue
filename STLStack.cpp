/****************************************************************************************
** Class Filename: STLStack.cpp
** Author: Parker Howell
** Date: 3-4-16
** Description: Class will prompt a user to enter a string to be turned into a
**              palindrome.
****************************************************************************************/

#include "STLStack.hpp"




/****************************************************************************************
** Function: Default Constructor
** Description: Creates a STLStack object to simulate a Buffer Queue. After creating your
**              object, call init() and run() to see it do its thang.
****************************************************************************************/
STLStack::STLStack()
{
}



// default destructor
STLStack::~STLStack()
{
}




/****************************************************************************************
** Function: init()
** Description: Prompts the user for a string to convert to a palindrome. That string is 
**              then added into a vector as individual chars.
****************************************************************************************/
void STLStack::init()
{
	system(CLEAR_SCREEN);
	std::cout << "Please enter a string to convert into a Palindrome." << std::endl;
	
	std::cin.ignore();
	std::getline(std::cin, inputString);

	std::copy(inputString.begin(), inputString.end(), std::back_inserter(veccy));
}




/****************************************************************************************
** Function: run()
** Description: Calls printAll() and then printNPop(), which together print all of the 
**              values of the vector from front to back, then print and pop all of the 
**              elements again, but from back to front.
****************************************************************************************/
void STLStack::run()
{
	printAll();
	printNPop();

	std::cout << "Press \"Enter\" to return to the main menu." << std::endl;
	std::cin.get();
}




/****************************************************************************************
** Function: printAll()
** Description: Prints all of the values in the vector from front to back.
****************************************************************************************/
void STLStack::printAll()
{
	std::vector<char>::iterator itty = veccy.begin();

	while (itty != veccy.end()){
		std::cout << *itty;
		itty++;
	}
}




/****************************************************************************************
** Function: printNPop()
** Description: For all of the elements in the vector, it prints the last value and then 
**              pops it out of the vector. Repeats with the new last element.
****************************************************************************************/
void STLStack::printNPop()
{
	while (!veccy.empty()){
		std::cout << veccy.back();
		veccy.pop_back();
	}
	std::cout << std::endl;
}


