/****************************************************************************************
** Class Filename: STLStack.hpp
** Author: Parker Howell
** Date: 3-4-16
** Description: Class will prompt a user to enter a string to be turned into a
**              palindrome. 
****************************************************************************************/

#ifndef STLSTACK_HPP
#define STLSTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

class STLStack
{
private:
	std::string inputString;       // user input to be turned into a palindrome
	std::vector<char> veccy;       // holds the entered string

public:




	/****************************************************************************************
	** Function: Default Constructor
	** Description: Creates a STLStack object to simulate a Buffer Queue. After creating your
	**              object, call init() and run() to see it do its thang.
	****************************************************************************************/
	STLStack();


	// default destructor
	~STLStack();




	/****************************************************************************************
	** Function: init()
	** Description: Prompts the user for a string to convert to a palindrome. That string is
	**              then added into a vector as individual chars.
	****************************************************************************************/
	void init();
	
	
	
	
	/****************************************************************************************
	** Function: run()
	** Description: Calls printAll() and then printNPop(), which together print all of the
	**              values of the vector from front to back, then print and pop all of the
	**              elements again, but from back to front.
	****************************************************************************************/
	void run();
	
	
	
	
	/****************************************************************************************
	** Function: printAll()
	** Description: Prints all of the values in the vector from front to back.
	****************************************************************************************/
	void printAll();
	
	
	
	
	/****************************************************************************************
	** Function: printNPop()
	** Description: For all of the elements in the vector, it prints the last value and then
	**              pops it out of the vector. Repeats with the new last element.
	****************************************************************************************/
	void printNPop();

};

#endif