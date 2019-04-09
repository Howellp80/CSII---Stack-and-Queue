/****************************************************************************************
** Class Filename: STLQueue.cpp
** Author: Parker Howell
** Date: 3-4-16
** Description: Class will ask a user to enter a percentage, of which, random values will
**              be entered into a queue (deque). The user will be asked to enter a second
**              value for the percetage chance that a value will be removed from the from
**              the front of the queue. The user will be asked to also enter an amout of
**              rounds to possibly add, and possibly remove elements to and/ or the
**              queue. Resuslt are printed to the screen.
****************************************************************************************/

#include "STLQueue.hpp"




/****************************************************************************************
** Function: Default Constructor
** Description: Creates a STLQueue object to simulate a Buffer Queue. After creating your
**              object, call init() and run() to see it do its thang.
****************************************************************************************/
STLQueue::STLQueue()
{
	numOfElements = 0;
	avg = 0;
	currentRound = 0;
}



// default destructor
STLQueue::~STLQueue()
{
}




/****************************************************************************************
** Function: init()
** Description: Prompts the user for the 3 values needed for the simulation. First is the
**              percentage chance that a random value will be created and added to the
**              queue. The second is the percentage chance that a value will be removed
**              from the queue. The third prompt asks the user how many rounds they want 
**              to run the simulation for.
****************************************************************************************/
void STLQueue::init()
{
	system(CLEAR_SCREEN);

	//seed the psudo-random num generator
	srand(static_cast<unsigned long>(time(0)));


	// get the percentage of values to be added
	std::cout << "What percentage of values should be added to the Buffer? (0 - 100)"
		<< std::endl;
	std::cin >> addPercent;

	// validate addPercent
	while (addPercent < 0 || addPercent > 100){
		std::cout << "Please enter a value between 0 - 100." << std::endl;
		std::cin >> addPercent;
	}


	// get the percentage chance of removing a value
	std::cout << "What percentage chance should there be of removing a value? (0 - 100)"
		<< std::endl;
	std::cin >> remPercent;

	// validate remPercent
	while (remPercent < 0 || remPercent > 100){
		std::cout << "Please enter a value between 0 - 100." << std::endl;
		std::cin >> remPercent;
	}


	// get the amount of rounds to run
	std::cout << "How many rounds would you like this to run for? (1 - 10000)"
		<< std::endl;
	std::cin >> rounds;

	// validate rounds
	while (rounds < 1 || rounds > 10000){
		std::cout << "Please enter a value between 1 - 10000." << std::endl;
		std::cin >> rounds;
	}
	system(CLEAR_SCREEN);
}




/****************************************************************************************
** Function: run()
** Description: For every round, run will see if values are to be added or subtracted and 
**              update the queue. It will then calculate the average number of elements 
**              in the queue. Followed by printing the values and average to the consile.
****************************************************************************************/
void STLQueue::run()
{
	for (int i = 0; i < rounds; i++){
		currentRound++; 
		genValue();
		remValue();
		average();
		print();
		
	}

	std::cout << "Please press \"Enter\" to return to the main menu." << std::endl;
	std::cin.ignore();
	std::cin.get();
}




/****************************************************************************************
** Function: genValue()
** Description: Takes the user enterd chance of adding a value, and checks to see if a 
**              random value between 1 - 100 meets that threshold. If it does a random
**              value is added to the queue.
****************************************************************************************/
void STLQueue::genValue()
{
	int chance = rand() % 100 + 1;
	if (chance <= addPercent)
		buffQueue.push_back(rand());
}




/****************************************************************************************
** Function: remValue()
** Description: If the queue isn't empty, see if a random value between 1 - 100 meets the
**              user enterd percentage chance that an element should be removed from the
**              queue. If it does, remove the element from the front of the queue.
****************************************************************************************/
void STLQueue::remValue()
{
	if (!buffQueue.empty()){
		int chance = rand() % 100 + 1;
		if (chance <= remPercent)
			buffQueue.pop_front();
	}
}




/****************************************************************************************
** Function: average()
** Description: Sums the size of the queue for every round, and then finds the average 
**              size of the queue for those rounds.
****************************************************************************************/
void STLQueue::average()
{
	numOfElements += buffQueue.size();
	avg = numOfElements / currentRound;
}




/****************************************************************************************
** Function: print()
** Description: Prints out the current round information. This is followed by all of the 
**              values in the queue. Next it prints the average queue lengeh.
****************************************************************************************/
void STLQueue::print()
{
	std::cout << "Round: " << currentRound << std::endl;

	for (unsigned int i = 0; i < buffQueue.size(); i++){
		std::cout << buffQueue[i] << std::endl;
	}
	
	std::cout << std::showpoint << std::fixed << std::setprecision(3);
	std::cout << "Average Queue length: " << avg << std::endl << std::endl;
}






