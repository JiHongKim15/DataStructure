#include "BpTree.h"

BpTree::BpTree(ofstream* fout, int order = 3){
	root = NULL;
	this->order = order;
	this->fout = fout;
}

BpTree::~BpTree(){

}

void BpTree::Insert(StudentData* pStu){
	/* �� ���� ���� �� �� �ּ� ����
	�Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ �����ϸ�
	�״�� �̿��� ���, �ݵ�� �ּ� �ۼ�
	*/
	double key = pStu->getAvgGrade();	// key = avgGrade
	map<int, StudentData*> value;			// value = map< id, student data* >
	value.insert( make_pair(pStu->getStudentID(), pStu) );	

	if(root == NULL){ // empty B+ tree
		BpTreeNode* pDataNode = new BpTreeDataNode;	// make new data node		
		pDataNode->insertDataMap(key, value);	// insert grade data
		root = pDataNode;
		return;
	}
		
	BpTreeNode* pDataNode = searchDataNode(key);	// seach data node with key
	
	map<double, map<int, StudentData*> > *m = pDataNode->getDataMap();

	/*
	�ڵ� �ۼ�  (����: if(m->find(key) == m->end()))
	*/
}

BpTreeNode* BpTree::searchDataNode(double n){
	/* �� ���� ���� �� �� �ּ� ����
	�Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ �����ϸ�
	�״�� �̿��� ���, �ݵ�� �ּ� �ۼ�
	*/

	BpTreeNode* pCur = root;
	map<double, BpTreeNode*>::iterator itIndex;

	while(pCur->getMostLeftChild() != NULL){ 
		itIndex = pCur->getIndexMap()->begin();

		if(n < itIndex->first){ 
			pCur = pCur->getMostLeftChild();
		}else{
			while(true){
				itIndex++;
				if(itIndex == pCur->getIndexMap()->end() || n < itIndex->first){
					itIndex--;
					pCur = itIndex->second;
					break;
				}
			}
		}
	}

	return pCur;
}

void BpTree::splitDataNode(BpTreeNode* pDataNode){
	/* �� ���� ����� �� �ּ� ����
	�Ʒ� ������ data node�� map���� split�� �߻��ϴ� data�� ��ġ�� �Ϲ�ȭ�� ���̴�.
	(�ٸ� ��Ƽ������ �̵��ϴ� �����͵��� ù ��° ���������� index node�� ����Ǵ� �������� ��ġ)
	*/
	int splitPosition_data = ceil((order-1)/2.0) + 1;

	/*
	�ڵ� �ۼ�
	*/
}

void BpTree::splitIndexNode(BpTreeNode* pIndexNode){
	/* �� ���� ����� �� �ּ� ����
	�Ʒ� ������ index node�� map���� split�� �߻��ϴ� index�� ��ġ�� �Ϲ�ȭ�� ���̴�.
	(�θ� ���� �̵�(����X)�ϴ� �������� ��ġ, ���� index ���ʹ� �ٸ� ��Ƽ������ �̵�)
	*/
	int splitPosition_index = ceil(order/2.0);

	/*
	�ڵ� �ۼ�
	*/
}

bool BpTree::exceedDataNode(BpTreeNode* pDataNode){
	/* �Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����*/
	map <double, map<int, StudentData*> > *m = pDataNode->getDataMap();

	if(m->size() > order-1)		return true;
	else								return false;
}

bool BpTree::exceedIndexNode(BpTreeNode* pIndexNode){
	/* �Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����*/
	map <double, BpTreeNode*>* m = pIndexNode->getIndexMap();
	
	if(m->size() > order-1)		return true;
	else								return false;
}



bool BpTree::Print(){

	return true;
}

bool BpTree::Search(double a, double b, int year){

	return true;
}

void BpTree::printStudentInfo(StudentData* pStudentData){

}