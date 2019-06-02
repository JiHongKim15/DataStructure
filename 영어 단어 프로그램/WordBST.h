#ifndef _WORDBST_H_

#define _WORDBST_H_



#include "WordNode.h"


class WordBST

{

private:

	WordNode * root;	// Word BST Root
	queue<WordNode*> q;
	stack<WordNode*> s;


public:

	WordBST();

	~WordBST();


	void		Insert(WordNode * node);			// LOAD, MOVE

	WordNode *	Delete(char * word);				// TEST

	WordNode *	Search(char * word);				// ADD, TEST, SEARCH, UPDATE

	bool		Print(char * order);							// PRINT

	bool		Save();								// SAVE


	void Inorder(WordNode * pcur);

	void Preorder(WordNode * pcur);

	void Postorder(WordNode * pcur);

	void I_Inorder();

	void Levelorder();

	void I_Preorder();

	void I_Postorder();
};
#endif