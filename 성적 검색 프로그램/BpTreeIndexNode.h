#ifndef _BPTREEINDEXNODE_H_
#define _BPTREEINDEXNODE_H_

#include "BpTreeNode.h"

class BpTreeIndexNode : public BpTreeNode{
private:
	map <double, BpTreeNode*> mapIndex;
	
public:
	BpTreeIndexNode(){}
	~BpTreeIndexNode(){}
	
	void insertIndexMap(double n, BpTreeNode* pN){
		// �ڵ� �ۼ�
	}

	void deleteMap(double n){
		// �ڵ� �ۼ�
	}

	map <double, BpTreeNode*>* getIndexMap()	{ return &mapIndex; }
};

#endif