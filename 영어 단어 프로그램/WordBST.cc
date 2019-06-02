
#include "WordBST.h"
#include "WordNode.h"

WordBST::WordBST()
{
	root = '\0';
}

WordBST::~WordBST()
{
	WordNode* pcur = root;
	if (pcur)
	{
		Postorder(pcur->GetLeft());
		Postorder(pcur->GetRight());
		delete pcur;
	}
}

void WordBST::Insert(WordNode * node) //insert function
{
	WordNode *p = root, *pp = NULL; 
	while (p) //Find the location of the node
	{
		pp = p;
		if (strcmp(node->GetWord(), p->GetWord()) < 0) //insert node is less than the current node
			p = p->GetLeft(); //Move to left
		else if (strcmp(node->GetWord(),p->GetWord()) > 0)//insert node is greater than the current node
			p = p->GetRight(); //Move to right
		else //insert node == current node
		{
			return;
		}
	}

	if (root != NULL)
	{
		if (strcmp(node->GetWord(), pp->GetWord()) < 0) //word of insert node is less than the current node
			pp->SetLeft(node); //Inserted to the left of the parent node,
		else
			pp->SetRight(node); //Inserted to the right of the parent node.
	}
	else root = node; //root is node;
	return;
}
WordNode * WordBST::Delete(char * word) //bst delete
{
	WordNode *p = root, *q = 0;
	WordNode *p1 = new WordNode;
	while (p) { //Location Found
		q = p;
		if (strcmp(word, p->GetWord()) < 0) {//delete node is less than the current node
			p = p->GetLeft();
		}
		else if (strcmp(word,p->GetWord()) > 0) {//delete node is greater than the current node
			p = p->GetRight();
		}
		else if (strcmp(word, p->GetWord()) == 0)
		{
			break;
		}
	}
	if (p == NULL) //p is NULL
		return 0;

	if (p->GetLeft() == 0 && p->GetRight() == 0) //no child nodes
	{
		if (q == 0)
			root = 0;
		else if (q->GetLeft() == p)
			q->SetLeft(0);
		else q->SetRight(0);
		//Initializing the direction of the parent node to NULL
		p1->SetWord(p->GetWord()); //insert data
		p1->SetMean(p->GetMean());
		delete p; //delete
		return p1; //return data
	}
	if (p->GetLeft() == 0) //only have right child node
	{
		if (q == p) root = p->GetLeft(); //p is root
		else if (q->GetLeft() == p) q->SetLeft(p->GetLeft());
		else q->SetRight(p->GetRight());
		//Initializing rigth child node of the parent node to right childe node of right child node
		p1->SetWord(p->GetWord()); //insert data
		p1->SetMean(p->GetMean());
		delete p;

	}
	if (p->GetRight() == 0) //only have left child node
	{
		if (q == p) root = p->GetLeft(); //p is root
		else if (q->GetLeft() == p)
			q->SetLeft(p->GetLeft());
		else
			q->SetRight(p->GetLeft());
		//Initializing left child node of the parent node to left childe node of left child node
		p1->SetWord(p->GetWord());
		p1->SetMean(p->GetMean());
		delete p;
		
	}
	return p1;

	//have two childe node
	WordNode *prevprev = p, *prev = p->GetRight(), *curr = p->GetRight()->GetLeft();

	while (curr)
	{
		prevprev = prev;
		prev = curr;
		curr = curr->GetLeft(); //move to left
	}
	p->SetMean(prev->GetMean()); //insert data
	p->SetWord(prev->GetWord());
	if (prevprev == p) prevprev->SetRight(prev->GetRight()); //left child node for parent node is right child node of delete node
	else prevprev->SetLeft(prev->GetRight());

	p1->SetWord(prev->GetWord()); //set data
	p1->SetMean(prev->GetMean());
	delete prev;
	return p1;
}
WordNode * WordBST::Search(char * word)
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	WordNode* pcur = root;
	int num;
	char* mean = 0;
	while (pcur)
	{
		if (strcmp(word, pcur->GetWord()) < 0) //search node is less than the current node
		{
			pcur = pcur->GetLeft(); //move to left
		}
		if (strcmp(word, pcur->GetWord()) > 0)//search node is greater than the current node
		{
			pcur = pcur->GetRight(); //move to right
		}
		else if (strcmp(word, pcur->GetWord()) == 0) //same
		{
			return pcur;
		}
	}
	return 0;
}
void WordBST::Inorder(WordNode* pcur)
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	if (pcur)
	//	Using a recursive function
	{
		Inorder(pcur->GetLeft()); //move to left
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		Inorder(pcur->GetRight()); //move to right

	}
	fout.close();
}
void WordBST::Preorder(WordNode* pcur)
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	//	Using a recursive function
	if (pcur)
	{
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		Preorder(pcur->GetLeft()); //move to left
		Preorder(pcur->GetRight()); //move to right
	}
	fout.close();
}
void WordBST::Postorder(WordNode* pcur)
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	//	Using a recursive function
	if (pcur)
	{
		Postorder(pcur->GetLeft()); //move to left
		Postorder(pcur->GetRight()); //move to left
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
	}
	fout.close();
}
void WordBST::Levelorder()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	WordNode* pcur = root;
	while (pcur)
	{
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl; //print
		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		if (pcur->GetLeft())
			q.push(pcur->GetLeft()); //stored queue
		if (pcur->GetRight())
			q.push(pcur->GetRight());
		if (q.empty()) //queue is NUL
			return;
		pcur = q.front(); //First storage node
		q.pop(); //delete
	}

	fout.close();
}
void WordBST::I_Preorder()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	WordNode* pcur = root;
	if (!root)
	{
		return;
	}
	while (1)
	{
		while (pcur) //Frist Printed, move to the left as possible
		{
			cout << pcur->GetWord() << " " << pcur->GetMean() << endl; //print
			fout << pcur->GetWord() << " " << pcur->GetMean() << endl; //log.txt save
			s.push(pcur); //push to stack, pcur
			pcur = pcur->GetLeft(); //move to left
		}
		if (s.empty())
			return;
		pcur = s.top(); //Recently node stored in
		s.pop();
		pcur = pcur->GetRight();
	}
	fout.close();
}
void WordBST::I_Inorder()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	WordNode* pcur = root;
	while (1)
	{
		while (pcur) //	Go to the left as possible
		{
			s.push(pcur);
			pcur = pcur->GetLeft();
		}
		if (s.empty())
			return;
		pcur = s.top();//Recently node stored in
		s.pop();
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl;

		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		pcur = pcur->GetRight();
	}
	fout.close();
}
void WordBST::I_Postorder()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	WordNode* pcur = root;
	stack<WordNode*> s1;
	if (root == NULL)
	{
		return;
	}
	s.push(root); //push to root
	while (1)
	{
		//Go and save
		pcur = s.top(); //Recently node stored in
		s1.push(pcur);
		s.pop(); //delete
		if (pcur->GetLeft())
			s.push(pcur->GetLeft());
		if (pcur->GetRight())
			s.push(pcur->GetRight());
		if (s.empty())
			break;
	}
	while (1)
	{
		if (s1.empty())
			break;
		cout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		fout << pcur->GetWord() << " " << pcur->GetMean() << endl;
		s1.pop(); //delete
	}
	fout.close();
}
bool WordBST::Print(char * order)
{
	WordNode* pcur = root;
	//In order to move along
	if (strcmp(order, "R_IN") == 0) //inorder 
	{
		Inorder(pcur);
	}
	else if (strcmp(order, "R_PRE") == 0)//preorder
	{
		Preorder(pcur);
	}
	else if (strcmp(order, "R_POST") == 0)//postorder
	{
		Postorder(pcur);
	}
	else if (strcmp(order, "I_PRE") == 0)//preorder
	{
		I_Preorder();
	}
	else if (strcmp(order, "I_IN") == 0)//inorder
	{
		I_Inorder();
	}
	else if (strcmp(order, "I_POST") == 0)//postorder
	{
		I_Postorder();
	}
	else if (strcmp(order, "I_LEVEL") == 0)//levelorder
	{
		Levelorder();
	}

	return true;
}

bool WordBST::Save()
{
	ofstream out;
	out.open("memorizing_word.txt",ios::app);

	WordNode* pcur = root;
	if (root == NULL)
	{
		return false;
	}
	while (1)
	{
		//preorder
		while (pcur)
		{
			out << pcur->GetWord() << " " << pcur->GetMean() << endl; //stored in a file
			s.push(pcur); 
			pcur = pcur->GetLeft();
		}
		if (s.empty()) //stack is NULL
			return true;
		pcur = s.top(); //Recently node stored in
		s.pop(); //delete
		pcur = pcur->GetRight(); //move to right
	}
	out.close();

	return false;
}
