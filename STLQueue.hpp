/****************************************************************************************
** Class Filename: STLQueue.hpp
** Author: Parker Howell
** Date: 3-4-16
** Description: Class will ask a user to enter a percentage, of which, random values will 
**              be entered into a queue (deque). The user will be asked to enter a second 
**              value for the percetage chance that a value will be removed from the from
**              the front of the queue. The user will be asked to also enter an amout of 
**              rounds to possibly add, and possibly remove elements to and/ or the 
**              queue. Resuslt are printed to the screen.
****************************************************************************************/

#ifndef STLQUEUE_HPP
#define STLQUEUE_HPP

#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <iomanip>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

class STLQueue
{
private:
	int addPercent,              // what percentage of numbers should be added.
		remPercent,              // the percentage chance of removing a number.
		rounds,                  // how many rounds to add and/or remove numbers.
		currentRound;            // waht round it is.
 double numOfElements,           // sum of elements there have been in every round. 
		avg;                     // aveerage of numOfElements for all rounds.
   std::deque<int> buffQueue;    // deque container for the elements.

public:




	/****************************************************************************************
	** Function: Default Constructor
	** Description: Creates a STLQueue object to simulate a Buffer Queue. After creating your
	**              object, call init() and run() to see it do its thang.
	****************************************************************************************/
	STLQueue();
	


	// default destructor
	~STLQueue();




	/****************************************************************************************
	** Function: init()
	** Description: Prompts the user for the 3 values needed for the simulation. First is the
	**              percentage chance that a random value will be created and added to the
	**              queue. The second is the percentage chance that a value will be removed
	**              from the queue. The third prompt asks the user how many rounds they want
	**              to run the simulation for.
	****************************************************************************************/
	void init();




	/****************************************************************************************
	** Function: run()
	** Description: For every round, run will see if values are to be added or subtracted and
	**              update the queue. It will then calculate the average number of elements
	**              in the queue. Followed by printing the values and average to the consile.
	****************************************************************************************/
	void run();




	/****************************************************************************************
	** Function: genValue()
	** Description: Takes the user enterd chance of adding a value, and checks to see if a
	**              random value between 1 - 100 meets that threshold. If it does a random
	**              value is added to the queue.
	****************************************************************************************/
	void genValue();




	/****************************************************************************************
	** Function: remValue()
	** Description: If the queue isn't empty, see if a random value between 1 - 100 meets the
	**              user enterd percentage chance that an element should be removed from the
	**              queue. If it does, remove the element from the front of the queue.
	****************************************************************************************/
	void remValue();




	/****************************************************************************************
	** Function: average()
	** Description: Sums the size of the queue for every round, and then finds the average
	**              size of the queue for those rounds.
	****************************************************************************************/
	void average();




	/****************************************************************************************
	** Function: print()
	** Description: Prints out the current round information. This is followed by all of the
	**              values in the queue. Next it prints the average queue lengeh.
	****************************************************************************************/
	void print();

};

#endif