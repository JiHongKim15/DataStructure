#include "Manager.h"
#include <fstream>


Manager::Manager()
{
	cll = new CircularLinkedList; //memorized
	bst = new AlphabetBST; //memorizing
	queue = new Queue; //to memorized
	m_cnt = 0;
}

Manager::~Manager()
{
	delete cll;
	delete bst;
	delete queue;
}

void Manager::run(const char * command)
{
	ifstream fin;
	fin.open(command);
	char com[50][50];
	int i = 0;
	if (!fin) //no command.txt
	{
		//ERROR PRINT
		cout << "======== ERROR ========" << endl;
		cout << "100" << endl;
		cout << "=======================" << endl;
		return;
	}
	while (!fin.eof()) {
		fin >> com[i];
		i++;
	}
	bool b = true; //true / false judgment
	ofstream fout;
	fout.open("log.txt"); //save log
	while (1) {
		if (strncmp((com[m_cnt]), "EXIT", 4) == 0) {
			exit(0);
		}
		else if (strncmp((com[m_cnt]), "LOAD", 4) == 0) { //into LOAD

			b = LOAD();
			if (b == true) //load success
			{
				
				cout << "======== LOAD =========" << endl;
				cout << "Success" << endl;
				cout << "=======================" << endl;//output "success"

				fout << "======== LOAD =========" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;//file output
			}
			else 
			{
				cout << "======== ERROR ========" << endl;
				cout << "100" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "100" << endl;
				fout << "=======================" << endl;
			}//Error code
		}
		else if (strncmp((com[m_cnt]), "ADD", 3) == 0) {//if command says ADD
			b = ADD();
			if (b == true)
			{
				cout << "======== ADD ==========" << endl;
				cout << "Success" << endl;
				cout << "=======================" << endl;//output "success"

				fout << "======== ADD ==========" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;
			}
			else
			{
				cout << "======== ERROR ========" << endl;
				cout << "200" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "200" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "MOVE", 4) == 0) {//if command says MOVE
			b = MOVE();
			if (b == true)
			{
				cout << "======== MOVE =========" << endl;
				cout << "Success" << endl;
				cout << "=======================" << endl;//output "success"

				fout << "======== MOVE =========" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;
			}
			else
			{
				cout << "======== ERROR ========" << endl;
				cout << "300" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "300" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "PRINT", 5) == 0) {//if command says PRINT
			b = PRINT();
			if(b == false)
			{
				cout << "======== ERROR ========" << endl;
				cout << "700" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "700" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "UPDATE", 6) == 0) {//if command says UPDATE
			b = UPDATE();
			if (b == true)
			{
				cout << "======== UPDATE =======" << endl;
				cout << "Success" << endl;
				cout << "=======================" << endl;

				fout << "======== UPDATE =======" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;
			}
			else
			{
				cout << "======== ERROR ========" << endl;
				cout << "800" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "800" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "SEARCH", 6) == 0) {//if command says SEARCH
			b = SEARCH();
		
			if(b == false)
			{
				cout << "======== ERROR ========" << endl;
				cout << "600" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "600" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "TEST", 4) == 0) {//if command says TEST
			b = TEST();
			if (b == true)
			{
				cout << "======== TEST ==========" << endl;
				cout << "Pass" << endl;
				cout << "=======================" << endl;

				fout << "======== TEST =========" << endl;
				fout << "Pass" << endl;
				fout << "=======================" << endl;
			}
			else
			{
				cout << "======== ERROR ========" << endl;
				cout << "500" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "500" << endl;
				fout << "=======================" << endl;
			}
		}
		else if (strncmp((com[m_cnt]), "SAVE", 4) == 0) {//if command says SAVE
			b = SAVE();
			if (b == true)
			{
				cout << "======== SAVE =========" << endl;
				cout << "Success" << endl;
				cout << "=======================" << endl;

				fout << "======== SAVE =========" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;
			}
			else
			{
				cout << "======== ERROR ========" << endl;
				cout << "400" << endl;
				cout << "=======================" << endl;
				fout << "======== ERROR ========" << endl;
				fout << "400" << endl;
				fout << "=======================" << endl;
			}
		}
		m_cnt++;
	}

	fin.close();
}
bool Manager::LOAD()
{
	ifstream ze;
	ifstream ng;
	ifstream ed;

	ze.open("to_memorize_word.txt");
	ng.open("memorizing_word.txt");
	ed.open("memorized_word.txt");//load files for queue, BST, CLL

	ofstream fout;
	fout.open("log.txt");//open test file to file output
	int i = 0;
	ifstream fin_com;
	fin_com.open("command.txt");//load command.txt for catch Error
	char arr[50][50];
	while (!fin_com.eof()) {
		fin_com.getline(arr[i], 50);
		if (strncmp("LOAD", arr[i], 4) == 0)
			break;
		i++;
	}//find 'LOAD' at command.txt
	if (strlen(arr[i]) != 4) {//in command.txt, if LOAD has something at it's right side
		cout << "======== ERROR ========" << endl;
		cout << "100" << endl;
		cout << "=======================" << endl;
		fout << "======== ERROR ========" << endl;
		fout << "100" << endl;
		fout << "=======================" << endl;
	}
	if (!ze)
		return false;
	if (!ng)
		return false;
	if (!ed)
		return false;
	//if file doesn't open

	int cnt = 0;
	
	char a;
	for (cnt = 0; !ze.eof(); cnt++)
	{
		WordNode* w_n = new WordNode;
		char* A1 = new char[32];
		
		ze >> A1;
		if (A1[0] < 65)
			continue;
		w_n->SetWord(A1);

		char* A2 = new char[32];
		ze >> A2;


		w_n->SetMean(A2);

		queue->Push(w_n);
	}//load text file and push node at the queue
	AlphabetNode* A = new AlphabetNode;
	for (cnt = 0; !ng.eof(); cnt++)
	{
		WordNode* w_n = new WordNode;
		char* A1 = new char[32];
		char* A2 = new char[32];

		ng >> A1;
		a = A1[0];
		
		if (a < 65)
			continue;

		w_n->SetWord(A1);
		cnt++;
		ng >> A2;

		w_n->SetMean(A2);

		A = bst->Search(a);
		A->GetBST()->Insert(w_n);

		bst->WordCnt++;
		if (bst->WordCnt > 100)
		{
			break;
		}
	}//load text file and push node at the BST
	for (cnt = 0; !ed.eof(); cnt++)
	{
		WordNode* w_n = new WordNode;
		char* A1 = new char[32];
		char* A2 = new char[32];

		ed >> A1;
		if (A1[0] < 65)
			continue;
		w_n->SetWord(A1);
		ed >> A2;


		w_n->SetMean(A2);

		cll->Insert(w_n);
	}//load text file and push node at the CLL

	ze.close();
	ed.close();
	ng.close();
	return true;
}
bool Manager::ADD() // ADD word.txt at queue
{
	ifstream fin;
	fin.open("word.txt");//word text
	if (!fin)
	{
		return false;
	}//if file open is fail

	int i = 0;
	while (!fin.eof())
	{
		char* a1 = new char[32];
		char* a2 = new char[32];
		WordNode* w_n = new WordNode;//dynamic allocated to node
		fin >> a1;
		w_n->SetWord(a1);
		fin >> a2;
		w_n->SetMean(a2);//store data at new node w_n
		if (queue->Search(a1)) {//if queue already has that word
			i++;//doesn't push
		}
		else {//else
			queue->Push(w_n);//push
			i++;
		}
	}
	return true;
}
bool Manager::MOVE()
{
	ifstream fin_move;
	fin_move.open("command.txt");
	char arr[256][256];
	char word[256][256];

	int i = 0, Movenum = 0;
	while (!fin_move.eof()) {
		fin_move >> arr[i];
		if (i == m_cnt) { //find "MOVE" txt
			i++;
			fin_move >> arr[i]; //the move command
			Movenum = atoi(arr[i]);        
			break;
		}
		i++;
	}
	if (queue->QCnt < Movenum) {
		return false;//if queue doesn't has that much
	}
	ifstream fin_tomem;
	fin_tomem.open("to_memorize_word.txt");
	if (!fin_tomem) {
		return false;
	}//file open
	i = 0;
	char temp[50];   //temp

	ofstream fout_mem;
	fout_mem.open("memorizing_word.txt", ios::app);
	for (int k = 0; k < Movenum; k++) {
		WordNode * pword = new WordNode;
		fin_tomem >> word[i];
		pword->SetWord(word[i]);//set word
		strcpy(temp, word[i]);
		pword->SetNext(NULL);
		i++;
		fin_tomem >> word[i];
		pword->SetMean(word[i]);//set data

		if (temp[0] > 96 && temp[0] < 123) {
			temp[0] = temp[0] - 32;
		}//change first alphabet to 
		bst->Search(temp[0])->GetBST()->Insert(pword);//insert to BST
		fout_mem << pword->GetWord() << " " << pword->GetMean() << endl;//file output
		i++;
	}
	return true;
}
bool Manager::SAVE()
{
	bool a, b, c;
	a = queue->Save(); //queue save
	b = cll->Save(); //cll save
	c = bst->Save(); //bst save

	if (a == false || b == false || c == false) //save false
	{
		return false;
	}
	return true;
}
bool Manager::TEST()
{
	ifstream fin_com;
	fin_com.open("command.txt");
	char arr_com[256][256];   //command open
	char arr_w[50];         //word
	char arr_m[50];         //mean
	char temp[50];
	int i = 0;
	WordNode * pnode = new WordNode;
	if (!fin_com) {
		return false;
	}
	while (!fin_com.eof()) {
		fin_com >> arr_com[i];
		if (i == m_cnt) { //find "TEST"
			i++;
			fin_com >> arr_com[i];
			strcpy(arr_w, arr_com[i]); //the TEST command
			strcpy(temp, arr_com[i]);
			i++;
			fin_com >> arr_com[i];
			strcpy(arr_m, arr_com[i]);
			break;
		}
		i++;
	}   //find word and mean from command file


	for (int j = 0; j < strlen(arr_com[i]); j++) //Changing the uppercase to lowercase
	{
		if (arr_com[i][j] < 97)
		{
			arr_com[i][j] = arr_com[i][j] + 32;
		}
	}
	if (temp[0] > 96 && temp[0] < 123) {
		temp[0] = temp[0] - 32;
	}
	//changing the first alphabet
	if (bst->Search(temp[0])->GetBST()->Search(arr_w) == 0) {
		return false;
	}//cannot found
	else {
		if (strcmp(bst->Search(temp[0])->GetBST()->Search(arr_w)->GetMean(), arr_m) == 0) {//word is found
			pnode = bst->Search(temp[0])->GetBST()->Delete(arr_w);//mean's right
			cll->Insert(pnode);//insert to circular linked list
			return true;
		}
	}
}
bool Manager::SEARCH()
{
	ifstream fin;
	ofstream fout;
	fout.open("log.txt", ios::app);
	fin.open("command.txt");
	char arr[50][50];
	memset(arr, NULL, sizeof(arr));
	int i = 0;

	while (!fin.eof()) {
		fin >> arr[i];
		if (m_cnt == i) { //find "SEARCH"
			i++;
			fin >> arr[i]; //the SEARCH command save
			break;
		}
		i++;
	}

	char a;
	a = arr[i][0];

	for (int j = 0; j < strlen(arr[i]); j++)//Changing the uppercase to lowercase
	{
		if (arr[i][j] < 97)
		{
			arr[i][j] = arr[i][j] + 32;
		}
	}
	AlphabetNode* B;
	WordNode* C;

	B = bst->Search(a); //Alphabet bst search

	C = B->GetBST()->Search(arr[i]); //Wordnode access to one of the search alphabetBST

	if (C == 0) //search false
	{
		return false;
	}

	cout << "======== SEARCH =======" << endl; //print
	cout << C->GetWord() << " " << C->GetMean() << endl;
	cout << "=======================" << endl;


	fout << "======== SEARCH =======" << endl;
	fout << C->GetWord() << " " << C->GetMean() << endl;
	fout << "=======================" << endl;
	
	fout.close();
	return true;
}
bool Manager::PRINT()
{
	ifstream fin;
	fin.open("command.txt");
	ofstream fout;
	fout.open("log.txt", ios::app);

	char arr[50][50];
	char a;
	memset(arr, NULL, sizeof(arr));
	int i = 0;

	while (!fin.eof()) {
		fin >> arr[i];
		if (m_cnt == i) { //find "PRINT" command
			i++;
			fin >> arr[i];
			if (strcmp(arr[i], "MEMORIZING") == 0) 
			{
				fin >> arr[i + 1];
			}
			break;
		}
		i++;
	}
	bool b = true;
	if (strcmp(arr[i], "TO_MEMORIZE") == 0) //to queue
	{
		fout << "======== PRINT ========" << endl;
		fout << "=======================" << endl;
		cout << "======== PRINT ========" << endl;
		queue->Print();
		cout << "=======================" << endl;
	}
	else if (strcmp(arr[i], "MEMORIZING") == 0) //to bst
	{
		fout << "======== PRINT ========" << endl;
		fout << "=======================" << endl;
		cout << "======== PRINT ========" << endl;
		b = bst->Print(arr[i+1]);
		cout << "=======================" << endl;
	}
	else if (strcmp(arr[i], "MEMORIZED") == 0) //to cll
	{
		fout << "======== PRINT ========" << endl;
		fout << "=======================" << endl;
		cout << "======== PRINT ========" << endl;
		cll->Print();
		cout << "=======================" << endl;
	}
	else
	{
		return false;
	}
	return true;
}
bool Manager::UPDATE()
{
	ifstream fin;
	fin.open("command.txt");
	ofstream fout;
	fout.open("log.txt", ios::app);
	char arr[32][32];
	char a;
	memset(arr, NULL, sizeof(arr));
	int i = 0;

	while (!fin.eof()) {
		fin >> arr[i];
		if (m_cnt == i) { //find "UPDATE" command
			i++;
			fin >> arr[i];
			fin >> arr[i + 1];
			break;
		}
		i++;
	}

	for (int j = 0; j < strlen(arr[i]); j++) //Changing the uppercase to lowercase
	{
		if (arr[i][j] < 97)
		{
			arr[i][j] = arr[i][j] + 32;
		}
	}
	a = arr[i][0];

	AlphabetNode* B1;
	WordNode* C1;
	WordNode* C2;
	WordNode* C3;
	
	B1 = bst->Search(a); //bst search
	C1 = B1->GetBST()->Search(arr[i]); //Wordnode access to one of the search alphabetBST
	C2 = queue->Search(arr[i]); //queue search
	C3 = cll->Search(arr[i]); //cll search

	if(C1==0 && C2 == 0 && C3 ==0)
		return false;

	fout << "======== UPDATE =======" << endl;

	cout << "======== UPDATE =======" << endl;
	
	//print
	if (C1 != 0) {
		fout << C1->GetWord() << " " << C1->GetMean() << "->";
		cout << C1->GetWord() << " " << C1->GetMean() << "->";

		C1->SetMean(arr[i + 1]); //mean change
		fout << C1->GetMean() << endl;
		cout << C1->GetMean() << endl;
	}
	if (C2 != 0) {
		fout << C2->GetWord() << " " << C2->GetMean() << "->";
		cout << C2->GetWord() << " " << C2->GetMean() << "->";

		C2->SetMean(arr[i + 1]); //mean change
		fout << C2->GetMean() << endl;
		cout << C2->GetMean() << endl;
	}
	if (C3 != 0) {
		fout << C3->GetWord() << " " << C3->GetMean() << "->";
		cout << C3->GetWord() << " " << C3->GetMean() << "->";

		C3->SetMean(arr[i + 1]); //mean change
		fout << C3->GetMean() << endl;
		cout << C3->GetMean() << endl;
	}
	fout << "=======================" << endl;
	cout << "=======================" << endl;
	return true;
}
