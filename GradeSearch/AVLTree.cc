#include "AVLTree.h"

AVLTree::AVLTree(ofstream* fout){
	root=NULL;
	make_heap(vHeap.begin(), vHeap.end(), compare);
	this->fout = fout;
}

AVLTree::~AVLTree(){

}

bool AVLTree::Insert(StudentData* pStu){
	/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
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
	/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
	stack<AVLNode*> s;	 

	return true;
}

bool AVLTree::Search(char* name){
	AVLNode *pCur = root; // 변수 명 변경 가능



	/* 
	아래 작성된 코드는 검색한 노드를 vector를 이용한 heap에 저장하는 코드로
	이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제
	*/
	
	StudentData* pSD = pCur->getSD(); // pCur은 name을 가진 AVL 노드를 가리킴
	vHeap.push_back( make_pair( make_pair(pSD->getAvgGrade(), pSD->getStudentID()), pSD));
	push_heap(vHeap.begin(), vHeap.end(), compare);

	return true;
}

bool AVLTree::Rank(){
	/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
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