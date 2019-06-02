#include "CircularLinkedList.h"
#include <fstream>
CircularLinkedList::CircularLinkedList()
{
	pHead = '\0';
}
CircularLinkedList::~CircularLinkedList()
{
	WordNode* pnode = pHead;
	if (pHead->GetNext() == pHead) {
		pHead = NULL;
		delete pnode;
	}
	else {
		while (pHead->GetNext() != pHead) {
			pnode = pHead;
			pHead = pHead->GetNext();
			delete pnode;
		}
	}
}

void CircularLinkedList::Insert(WordNode * node)
{
	if (pHead == NULL) {
		pHead = node;
		node->SetNext(pHead);
	}
	else {
		WordNode* pnode = pHead;
		while (pnode->GetNext() != pHead) {
			pnode = pnode->GetNext();
		}
		pnode->SetNext(node);
		node->SetNext(pHead);
	}
}

WordNode * CircularLinkedList::Search(char * word)
{
	WordNode* pnode = pHead;
	int n = 0;
	if (pnode == NULL) {
		return 0;
	}
	else
	{
		if (pnode == pHead) {
			if (strcmp(pnode->GetWord(), word) == 0) {
				return pnode;
				n++;
			}
			pnode = pnode->GetNext();
		}
		while (pnode != pHead) {
			if (strcmp(pnode->GetWord(), word) == 0) {
				return pnode;
				n++;
			}
			pnode = pnode->GetNext();
		}
		if (n == 0) {
			return 0;
		}

	}
}

bool CircularLinkedList::Print()
{
	ofstream fout;
	fout.open("log.txt", ios::app);

	WordNode* pnode = pHead;
	if (pHead == NULL)
	{
		fout << "======== ERROR =======" << endl;
		fout << "700" << endl;
		fout << "=======================" << endl;
		cout << "======== ERROR =======" << endl;
		cout << "700" << endl;
		cout << "=======================" << endl;
	}
	if (pnode != NULL) {
		if (pHead->GetNext() == pHead) {
			fout << pnode->GetWord() << " " << pnode->GetMean() << endl;
			cout << pnode->GetWord() << " " << pnode->GetMean() << endl;
		}
		else {
			fout << pnode->GetWord() << " " << pnode->GetMean() << endl;
			cout << pnode->GetWord() << " " << pnode->GetMean() << endl;
			pnode = pnode->GetNext();
			while (pnode != pHead) {
				fout << pnode->GetWord() << " " << pnode->GetMean() << endl;
				cout << pnode->GetWord() << " " << pnode->GetMean() << endl;
				pnode = pnode->GetNext();
			}
			return true;
		}
	}
}
bool CircularLinkedList::Save()
{
	ofstream out;
	out.open("memorized_word.txt");
	WordNode* pnode = pHead;
	if (pnode != NULL) {
		out << pnode->GetWord() << " " << pnode->GetMean() << endl;
		pnode = pnode->GetNext();
		while (pnode != pHead) {
			if (pnode->GetWord() == NULL)
				break;
			out << pnode->GetWord() << " " << pnode->GetMean() << endl;
			pnode = pnode->GetNext();
		}
		return true;
	}
}