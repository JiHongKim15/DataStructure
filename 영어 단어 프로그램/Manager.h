#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "CircularLinkedList.h"
#include "AlphabetBST.h"
#include "Queue.h"
#include <utility>
#include <iostream>
using namespace std;
class Manager
{
public:
	CircularLinkedList * cll;	// MEMORIZED Circular Linked List
	AlphabetBST	* bst;			// MEMORIZING BST
	Queue * queue;				// TO_MEMORIZE Queue
	int m_cnt;
public:
	Manager();
	~Manager();
	void run(const char * command);	// ifstream fin; fin.open(command); // and read all line
	bool LOAD();
	bool ADD();
	bool MOVE();
	bool SAVE();
	bool TEST();
	bool SEARCH();
	bool PRINT();
	bool UPDATE();
};



#endif