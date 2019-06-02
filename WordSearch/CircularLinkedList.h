#ifndef _CIRCULARLINKEDLIST_H_
#define _CIRCULARLINKEDLIST_H_

//circular linked list
//do not any exeption handling.

#include "WordNode.h"
#include<iostream>
using namespace std;
class CircularLinkedList
{
public:
	WordNode * pHead;   // Circular Linked List Head Pointer public:
	CircularLinkedList();
	~CircularLinkedList();
	void      Insert(WordNode * node);         // LOAD, TEST
	WordNode *   Search(char * word);            // SEARCH, UPDATE
	bool      Print();                     // PRINT
	bool      Save();                        // SAVE 
};
#endif