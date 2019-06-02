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
		// 内靛 累己
	}

	void deleteMap(double n){
		// 内靛 累己
	}

	map <double, BpTreeNode*>* getIndexMap()	{ return &mapIndex; }
};

#endif