/****************************************************************************************
** Program Filename: Main.cpp
** Author: Parker Howell
** Date: 3-4-16
** Description: Main menu asks the user if they want to create a Buffer Queue or a 
**              Palindrome Stack in a STL container test.
****************************************************************************************/

#include "STLQueue.hpp"
#include "STLStack.hpp"
#include <iostream>
#include <cstdlib>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

int main(){

	int menu;


	// main menu
	do {
		system(CLEAR_SCREEN);
		std::cout << "Welcome to a Buffer Queue (really a deque) and "
			      << "Palindrome Stack demo." << std::endl;
		std::cout << " [1] - Buffer Queue" << std::endl;
		std::cout << " [2] - Palindrome Stack" << std::endl;
		std::cout << " [3] - EXIT" << std::endl;
		std::cin >> menu;

		// validate menu choice
		while (menu < 1 || menu > 3){
			std::cout << "Please choose 1 - 3." << std::endl;
			std::cin >> menu;
		}

		// if the user didn't exit
		if (menu != 3){
			
			//if the user chose the Buffer Queue
			if (menu == 1){

				STLQueue myQueue;
				myQueue.init();
				myQueue.run();
			}

			// the user chose the Palindrome Stack
			else { // (menu == 2)

				STLStack myStack;
				myStack.init();
				myStack.run();
			}
		}

	// did the user exit?
	} while (menu != 3);
	
	return 0;
}