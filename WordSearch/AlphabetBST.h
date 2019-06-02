#ifndef _ALPHABETBST_H_

#define _ALPHABETBST_H_



#include "AlphabetNode.h"



#define MAX_WORD 100	// Maximum MEMORIZING Words



class AlphabetBST

{
private:
	stack<AlphabetNode*> s;
	queue<AlphabetNode*> q;
public:

	AlphabetNode * root;

	int WordCnt;


public:

	AlphabetBST();

	~AlphabetBST();



	void Insert(AlphabetNode * node);	// run


	bool			Print(char * order);						// PRINT


	AlphabetNode *	Search(char alpabet);			// LOAD, MOVE, TEST, SEARCH, UPDATE

	bool			Save();							// SAVE

	void Inorder(AlphabetNode * pcur, char* order);

	void Preorder(AlphabetNode * pcur, char* order);

	void Postorder(AlphabetNode * pcur, char* order);

	void Levelorder(char* order);

	void I_Preorder(char* order);

	void I_Inorder(char* order);

	void I_Postorder(char* order);
};



#endif