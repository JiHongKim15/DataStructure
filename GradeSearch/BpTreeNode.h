#ifndef _BpTreeNode_H_
#define _BpTreeNode_H_

#include "Year.h"

class BpTreeNode{
private:
	BpTreeNode* pParent;
	BpTreeNode* pMostLeftChild;

public:
	BpTreeNode(){
		pParent = NULL;
		pMostLeftChild = NULL;
	}

	void setMostLeftChild(BpTreeNode* pN)	{ pMostLeftChild = pN; }
	void setParent(BpTreeNode* pN)				{ pParent = pN; }
	
	BpTreeNode* getParent()						{ return pParent;	}
	BpTreeNode* getMostLeftChild()				{ return pMostLeftChild; }

	/*
	virtual 함수 추가
	*/
};

#endif