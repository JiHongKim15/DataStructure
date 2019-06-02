#include "AlphabetBST.h"

AlphabetBST::AlphabetBST()
{
	root = '\0';
	WordCnt = 0;

	char arr[26] = { 'P', 'H', 'X', 'D', 'L', 'T', 'Z', 'B', 'F', 'J', 'N', 'R', 'V', 'Y', 'A', 'C', 'E', 'G', 'I', 'K', 'M', 'O', 'Q', 'S', 'U', 'W' };
	//insert
	//make alphabet bst
	AlphabetNode *p = root, *pp = NULL;
	for (int i = 0; i < 26; i++) {
		p = root;
		AlphabetNode *pnew = new AlphabetNode;
		pnew->SetAlphabet(arr[i]); //data
		pnew->SetLeft(NULL);
		pnew->SetRight(NULL);
		if (root == NULL) {
			root = pnew;
		}
		else {
			while (p)
			{
				pp = p;
				if (pnew->GetAlphabet() < p->GetAlphabet() && p->GetLeft() != NULL)//insert node is less than the current node
					p = p->GetLeft();
				else if (pnew->GetAlphabet() > p->GetAlphabet() && p->GetRight() != NULL)//insert node is greater than the current node
					p = p->GetRight();
				else {
					break;
				}
			}
			if (root != NULL)
			{
				if (pnew->GetAlphabet() < p->GetAlphabet())//word of insert node is less than the current node
					p->SetLeft(pnew);
				else
					p->SetRight(pnew);
			}
		}
	}
}

AlphabetBST::~AlphabetBST()
{
}

void AlphabetBST::Insert(AlphabetNode * node)
{
	AlphabetNode *p = root, *pp = NULL;
	while (p)//Find the location of the node
	{
		pp = p;
		if (node->GetAlphabet() < p->GetAlphabet())//insert node is less than the current node
			p = p->GetLeft();
		else if (node->GetAlphabet() > p->GetAlphabet())// insert node is greater than the current node

			p = p->GetRight();
		else //insert node == current node
		{
			return;
		}
	}
	if (root != NULL)
	{
		if (node->GetAlphabet() < pp->GetAlphabet()) //word of insert node is less than the current node

			pp->SetLeft(node);//Inserted to the left of the parent node,
		else
			pp->SetRight(node); //Inserted to the right of the parent node.
	}
	else root = node;//root is node;
	return;
}
void AlphabetBST::Inorder(AlphabetNode* pcur, char* order)
{//	Using a recursive function
	//	Same way with wordBST
	if (pcur)
	{
		Inorder(pcur->GetLeft(), order);
		pcur->GetBST()->Print(order);
		Inorder(pcur->GetRight(), order);
	}
}
void AlphabetBST::Preorder(AlphabetNode* pcur, char* order)
{//	Using a recursive function
 //	Same way with wordBST

	if (pcur)
	{
		pcur->GetBST()->Print(order);
		Preorder(pcur->GetLeft(), order);
		Preorder(pcur->GetRight(), order);
	}
}
void AlphabetBST::Postorder(AlphabetNode* pcur, char* order)
{//	Using a recursive function
 //	Same way with wordBST

	if (pcur)
	{
		Postorder(pcur->GetLeft(), order);
		Postorder(pcur->GetRight(), order);
		pcur->GetBST()->Print(order);
	}
}
void AlphabetBST::Levelorder(char* order)
{//	Same way with wordBST

	AlphabetNode* pcur = root;

	while (pcur)//Frist Printed, move to the left as possible
	{
		pcur->GetBST()->Print(order);
		if (pcur->GetLeft())
			q.push(pcur->GetLeft());//stored queue
		if (pcur->GetRight())
			q.push(pcur->GetRight());
		if (q.empty())//queue is NUL
			return;
		pcur = q.front();//First storage node
		q.pop();
	}
}
void AlphabetBST::I_Preorder(char* order)
{//	Same way with wordBST

	AlphabetNode* pcur = root;

	while (1)
	{
		while (pcur)
		{
			pcur->GetBST()->Print(order); //Go to print wordBST of the alphabet BST Node
			s.push(pcur);//push to stack, pcur
			pcur = pcur->GetLeft();
		}
		if (s.empty())
			return;
		pcur = s.top();
		s.pop();
		pcur = pcur->GetRight();
	}
}
void AlphabetBST::I_Inorder(char* order)
{//	Same way with wordBST

	AlphabetNode* pcur = root;
	while (1)
	{
		while (pcur)//	Go to the left as possible
		{
			s.push(pcur);
			pcur = pcur->GetLeft();
		}
		if (s.empty())
			return;
		pcur = s.top();//Recently node stored in
		s.pop();
		pcur->GetBST()->Print(order); //Go to print wordBST of the alphabet BST Node
		pcur = pcur->GetRight();
	}
}
void AlphabetBST::I_Postorder(char* order)
{//	Same way with wordBST

	AlphabetNode* pcur = root;
	int num = 0;
	stack<AlphabetNode*> s1;
	if (!root)
		return;
	s.push(root);//push to root
	while (1)
	{//Go and save
		pcur = s.top(); //Recently node stored in
		s1.push(pcur);
		s.pop();
		if (pcur->GetLeft())
			s.push(pcur->GetLeft());
		if (pcur->GetRight())
			s.push(pcur->GetRight());
		if (s.empty())
			break;
	}
	while (1)
	{
		s1.top()->GetBST()->Print(order); //Go to print wordBST of the alphabet BST Node
		s1.pop();
		if (s1.empty())
			break;
	}

}
bool AlphabetBST::Print(char * order)
{
	//In order to move along

	AlphabetNode* pcur = root;


	if (root == NULL)
	{
		return false;
	}

	if (strcmp(order, "R_IN") == 0)
	{
		Inorder(pcur, order);
	}
	else if (strcmp(order, "R_PRE") == 0)
	{
		Preorder(pcur, order);
	}
	else if (strcmp(order, "R_POST") == 0)
	{
		Postorder(pcur, order);
	}
	else if (strcmp(order, "I_PRE") == 0)
	{
		I_Preorder(order);
	}
	else if (strcmp(order, "I_IN") == 0)
	{
		I_Inorder(order);
	}
	else if (strcmp(order, "I_POST") == 0)
	{
		I_Postorder(order);
	}
	else if (strcmp(order, "I_LEVEL") == 0)
	{
		Levelorder(order);
	}

}
AlphabetNode * AlphabetBST::Search(char alpabet)
{
	AlphabetNode* pcur = root;
	ofstream fout;
	fout.open("log.txt", ios::app);
	if (alpabet > 90) //Changing lowercase to uppercase
	{
		alpabet = alpabet - 32;
	}

	if (!pcur)
	{
		return 0;
	}
	while (pcur)
	{
		if (alpabet < pcur->GetAlphabet())//search node is less than the current node
		{
			pcur = pcur->GetLeft();
		}
		if (alpabet > pcur->GetAlphabet())//search node is greater than the current node
		{
			pcur = pcur->GetRight();
		}
		if (alpabet == pcur->GetAlphabet())//same
		{
			return pcur;
		}
	}
	return 0;
}

bool AlphabetBST::Save()
{
	AlphabetNode* pcur = root;
	ofstream fout;
	fout.open("memorizing_word.txt");
	while (1)
	{
		//preorder
		while (pcur)
		{
			pcur->GetBST()->Save(); //wordBST save of current node
			s.push(pcur);
			pcur = pcur->GetLeft();
		}
		if (s.empty()) //stack is NULL
			return 1;
		pcur = s.top(); //Recently node stored in
		s.pop();
		pcur = pcur->GetRight(); //move to right
	}
	fout.close();
}
