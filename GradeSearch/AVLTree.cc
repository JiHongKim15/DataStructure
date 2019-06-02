#include "AVLTree.h"

AVLTree::AVLTree(ofstream* fout){
	root=NULL;
	make_heap(vHeap.begin(), vHeap.end(), compare);
	this->fout = fout;
}

AVLTree::~AVLTree(){

}

bool AVLTree::Insert(StudentData* pStu){
	/* �Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����*/
	AVLNode* pNew = new AVLNode;
	pNew->setSD(pStu);	
	char	*pName = pStu->getName();
	int		rotation = 0;

	if(root == NULL){
		root = pNew;
		return true;
	}

	

}

bool AVLTree::Print(){
	/* �Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����*/
	stack<AVLNode*> s;	 

	return true;
}

bool AVLTree::Search(char* name){
	AVLNode *pCur = root; // ���� �� ���� ����



	/* 
	�Ʒ� �ۼ��� �ڵ�� �˻��� ��带 vector�� �̿��� heap�� �����ϴ� �ڵ��
	�̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����
	*/
	
	StudentData* pSD = pCur->getSD(); // pCur�� name�� ���� AVL ��带 ����Ŵ
	vHeap.push_back( make_pair( make_pair(pSD->getAvgGrade(), pSD->getStudentID()), pSD));
	push_heap(vHeap.begin(), vHeap.end(), compare);

	return true;
}

bool AVLTree::Rank(){
	/* �Ʒ� �ۼ��� �ڵ�� �̿� �Ǵ� ����, ������ ������ -- ���� ���� �� �� �ּ� ����*/
	if(vHeap.empty())		return false;

	StudentData* pStu;
	
	while(!vHeap.empty()){
		pStu = vHeap.front().second;
		pop_heap(vHeap.begin(), vHeap.end(), compare);
		vHeap.pop_back();
		printStudentInfo(pStu);
	}
	return true;
}

void AVLTree::printStudentInfo(StudentData* pStudentData){

}