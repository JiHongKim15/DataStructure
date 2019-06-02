#include "Queue.h"

Queue::Queue()
{
	pHead = '\0';//initializing head
	QCnt = 0;
}

Queue::~Queue()//Destructor
{
	WordNode* pnode;//new WordNode
	while (1) {//infinite loof
		if (pHead->GetNext() == NULL) {
			break;
		}//if head is the last node, break
		pnode = pHead;
		pHead = pHead->GetNext();//move head to the next node
		delete pnode;
	}
}

void Queue::Push(WordNode * node)//insert node
{
	if (pHead == NULL) {
		pHead = node;//if head is empty, insert node to pHead
		QCnt++;
	}
	else {//if head is not empty
		WordNode* pnode = pHead;//It will be the last node.
		while (pnode->GetNext() != NULL) {
			pnode = pnode->GetNext();
		}//go to the last node
		pnode->SetNext(node);//insert node into the next of last node.
		QCnt++;
	}
}

WordNode * Queue::Pop()//delete node. FIFO.
{
	WordNode* pnode = pHead; //deleted node
	WordNode* pTemp = new WordNode; //dynamic allocated to the returned node
	if (pnode->GetNext() == NULL) {
		pHead = NULL;
		pTemp->SetWord(pnode->GetWord());
		pTemp->SetMean(pnode->GetMean());//store pnode's data to pTemp
		delete pnode;//delete
		return pTemp;//return pnode's data
	}
	else {
		pHead = pnode->GetNext();//moving head
		pTemp->SetWord(pnode->GetWord());
		pTemp->SetMean(pnode->GetMean());//store pnode's data
		delete pnode;//delete
		return pTemp;//return pnode's data
	}
}

WordNode * Queue::Search(char * word)//Searching node
{
	WordNode* pnode = pHead;//searching node
	while (pnode->GetNext() != NULL) {//move pnode
		if (strcmp(pnode->GetWord(), word) == 0) {//if that's what user want,
			return pnode;//return that node
		}
		pnode = pnode->GetNext();
	}
	return 0;
}

bool Queue::Print()//Print nodes
{
	WordNode* pnode = pHead;//searching node
	if (pHead == NULL)//if there's nothing to print.
	{
		cout << "======== ERROR =======" << endl;
		cout << "700" << endl;
		cout << "=======================" << endl;
	}
	if (pnode != NULL) {//else
		while (1) {
			if (pnode == NULL) {//if this is end of the node,
				break;//escape the loof
			}
			cout << pnode->GetWord() << " " << pnode->GetMean() << endl;//print data
			pnode = pnode->GetNext();//move pnode
		}
		return true;
	}
}

bool Queue::Save()//store datas to the last node
{
	ofstream out;//file output stream
	out.open("to_memorize_word.txt");//open text file
	WordNode* pnode = pHead;
	if (pHead == NULL)//if there's nothing to save
	{
		return false;
	}
	if (pnode != NULL) {//else
		while (pnode != NULL) {//if it's the last node, escape loof.
			out << pnode->GetWord() << " " << pnode->GetMean() << endl;//file output
			pnode = pnode->GetNext();//move pnode
		}
		return true;
	}
}

