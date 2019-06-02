#ifndef _BPTREEDATANODE_H_
#define _BPTREEDATANODE_H_

#include "BpTreeNode.h"

class BpTreeDataNode : public BpTreeNode
{
private:
	map <double, map<int, StudentData*> > mapData;
	BpTreeNode* pNext;
	BpTreeNode* pPrev;

public:
	BpTreeDataNode(){
		pNext = NULL;
		pPrev = NULL;
	}

	void setNext(BpTreeNode* pN)	{ pNext = pN; }
	void setPrev(BpTreeNode* pN)	{ pPrev = pN; }
	BpTreeNode* getNext()				{ return pNext; }
	BpTreeNode* getPrev()				{ return pPrev; }	

	void insertDataMap(double avgGrade, map<int, StudentData*> m){
		// �ڵ� �ۼ�
	}

	void deleteMap(double n){
		// �ڵ� �ۼ�
	}	

	map< double, map<int, StudentData*> > *getDataMap()		{ return &mapData; }
};

#endif