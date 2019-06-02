#include "Manager.h"

Manager::Manager()
{
	graph = NULL; //graph
	fout.open("log.txt", ios::app); //log.txt open
	load = 0;
	int d = 0; //directed
	int w = 0; //weighted
}

Manager::~Manager()
{
	fout.close(); //file close
}

void Manager::run(const char* command_txt)
{
	ifstream fin;		fin.open(command_txt);
		
	if(!fin) //command not exist
	{
		fout<<"[ERROR] command file open error!"<<endl;
		return;
	}
	
	char*	str=NULL;
	char*	str2=NULL;
	char	buf[128]={0};

	while(fin.getline(buf, 64)) //received form a file
	{
		str=strtok(buf, " \t\n"); //token
		
		if(strcmp(str, "LOAD") == 0) //LOAD
		{
			if((str=strtok(NULL, " \t\n")) == NULL )
				printErrorCode(100);

			if(load == 1) //running load
			{
				printErrorCode(100);
			}
			else if((str2=strtok(NULL, " \t\n")) != NULL || !LOAD(str))//command after load is not exist or LOAD false
			{
				printErrorCode(100);
			}
			load = 1;
		}
		else if (strcmp(str, "PRINT") == 0) //Print
		{
			if ((str2 = strtok(NULL, " \t\n")) != NULL || !PRINT())//Print false
				printErrorCode(200);
		}
		else if (strcmp(str, "BFS") == 0) //BFS
		{
			if ((str2 = strtok(NULL, " \t\n")) == NULL || !mBFS(atoi(str2))) // command after load is not exist or BFS false
				printErrorCode(300);
		}
		else if (strcmp(str, "DFS") == 0) //DFS
		{
			if ((str2 = strtok(NULL, " \t\n")) == NULL || !mDFS(atoi(str2))) // command after load is not exist or DFS false
				printErrorCode(400);
		}
		else if (strcmp(str, "DFS_R") == 0) //DFS_R
		{
			if ((str2 = strtok(NULL, " \t\n")) == NULL || !mDFS_R(atoi(str2))) // command after load is not exist or DFS_R false
				printErrorCode(500);
		}
		else if (strcmp(str, "Kruskal") == 0) //Kruskal
		{
			if ((str2 = strtok(NULL, " \t\n")) != NULL || !mKruskal()) //kruskal false
				printErrorCode(600);
		}
		else if (strcmp(str, "Dijkstra") == 0) //Dijkstra
		{
			if ((str2 = strtok(NULL, " \t\n")) == NULL || !mDijkstra(atoi(str2))) // command after load is not exist or Dijkstra false
				printErrorCode(700);
			
		}
		else if (strcmp(str, "EXIT") == 0) //EXIT
		{
			return;
		}
		else
		{
			printErrorCode(100);
		}
		fout<<endl;
	}	
	fin.close();
}

bool Manager::LOAD(char* filename)
{
	char*	str=NULL;
	char*	str2=NULL;
	char	buf[128]={0};
	char	buf2[128]={0};

	ifstream fin;
	fin.open(filename);
	
	if(!fin)
	{
		return false;
	}
	
	fin.getline(buf, 64);
	strcpy(buf2, buf);

	char* type = NULL;
	char* directed = NULL;
	char* weighted = NULL;
	char* size;
	int from;

	type = strtok(buf, " "); //type
	directed = strtok(NULL, " "); //direted
	weighted = strtok(NULL, " "); //weighted

	d = atoi(directed); //directed
	w = atoi(weighted); //weighted
	
	fin.getline(buf2, 64); //file receive

	size = strtok(buf2, " "); //size

	if (strcmp(type, "L") == 0) //List
	{
		graph = new ListGraph(atoi(type), atoi(directed), atoi(weighted), atoi(size)); //list graph

		while (fin.getline(buf, 64))
		{
			str = strtok(buf, " ");
			str2 = strtok(NULL, " ");
			if (str2 == NULL)//after number is not exist
			{
				from = atoi(str); //from = str
				continue;
			}
			graph->insertEdge(from, atoi(str), atoi(str2)); //from = from, to = str, weight = str2
		}
	}
	else if (strcmp(type, "M") == 0) //Matrix
	{
		graph = new MatrixGraph(atoi(type), atoi(directed), atoi(weighted), atoi(size));//matrix graph

		for (int i= 0; fin.getline(buf, 64); i++)
		{
			for (int j = 0; j < atoi(size) ; j++)
			{
				if (j == 0)
					str = strtok(buf, " ");
				else
					str = strtok(NULL, " ");
				graph->insertEdge(i, j, atoi(str));//insert from -= i, to = j, weight = str
			}
		}
	}
	else
		return false;
	return true;
}

bool Manager::PRINT()
{
	if (!graph)
		return false;

	fout << "======== PRINT ========" << endl;
	graph->printGraph(&fout); //print
	fout << "=======================" << endl;
	return true;
}

bool Manager::mDijkstra(int from)
{
	if (!graph)
		return false;
	if (d == 0 || w == 0) //if directed 0 or weighted 0
		return false;
	fout << "======= Dijkstra ======" << endl;
		Dijkstra(graph, from, &fout); //dijkstra funciton
	fout << "=======================" << endl;
	return true;
}

bool Manager::mKruskal()
{
	if (!graph)
		return false;
	if (d == 1 || w == 0) //if directed 1 or weighted 0
		return false;
	fout << "======= Kruskal =======" << endl;
	Kruskal(graph, &fout); //Kruskal function
	fout << "=======================" << endl;
	return true;
}

bool Manager::mBFS(int ver)
{
	if (!graph)
		return false;
	if (d == 1 || w == 1) //if directed 1 or weighted 1
		return false;
	fout << "========= BFS =========" << endl;
	BFS(graph, ver, &fout); //BFS function
	fout << "=======================" << endl;
	return true;	
}

bool Manager::mDFS_R(int ver)
{
	if (!graph)
		return false;

	if (d == 1 || w == 1)//if directed 1 or weighted 1
		return false;
	vector<bool> visit(graph->getSize());//vector visit
	fout << "======== DFS_R ========" << endl;
	DFS_R(graph, &visit, ver, &fout);//DFS_R function
	fout << "\n=======================" << endl;
	return true;
}

bool Manager::mDFS(int ver)
{
	if (!graph)
		return false;
	if (d == 1 || w == 1)//if directed 1 or weighted 1
		return false;
	fout << "========= DFS =========" << endl;
	DFS(graph, ver, &fout); //DFS function
	fout << "=======================" << endl;
	return true;
}

void Manager::printErrorCode(int n)
{
	fout<<"======== ERROR ========"<<endl;
	fout<<n<<endl;
	fout<<"======================="<<endl;
}