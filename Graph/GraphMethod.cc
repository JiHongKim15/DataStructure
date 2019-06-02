#include "GraphMethod.h"

bool BFS(Graph* graph, int baseV, ofstream* fout)
{
	bool *visit = new bool[graph->getSize()]; //visit
	for (int i = 0; i < graph->getSize(); i++) //reset
		visit[i] = false;

	queue<int> Q;
	Q.push(baseV); //push baseV
	visit[baseV] = true; //baseV visit
	int cur;

	while (!Q.empty())
	{
		cur = Q.front();
		*fout << cur << " ";//print
		Q.pop(); //delete
		for (int i = 0; i<graph->getSize(); i++)
		{
			if (visit[i] == false && graph->connectCheck(cur,i)) //node not visit and connect on
			{
				Q.push(i); //push i
				visit[i] = true; //node visit
			}
		}
	}
	*fout << endl;
	return true;
}

bool DFS(Graph* graph, int baseV, ofstream* fout)
{
	stack<int> S;
	S.push(baseV);//stack push baseV

	bool *visit = new bool[graph->getSize()];//viist
	for (int i = 0; i < graph->getSize(); i++)//reset
		visit[i] = false;
	int cur;

	while (!S.empty())
	{
		cur = S.top();
		*fout << cur << " "; //print
		S.pop();

		if (visit[cur] == false) //cur visit?
			visit[cur] = true;
		for (int i = graph->getSize()-1; i >= 0; i--)
		{
			if (visit[i] == false && graph->connectCheck(cur, i)) //not visit node and connect on
			{
				S.push(i);//stack i push
			}
		}
	}
	*fout << endl;
	return true;
}

bool DFS_R(Graph* graph, vector<bool>* visit, int baseV, ofstream* fout)
{
	(*visit)[baseV] = true;
	int cur = baseV;
	*fout << cur << " ";

	for (int i = 0; i < graph->getSize(); i++)
	{
		if (visit->at(i) == false && graph->connectCheck(cur, i)) //no visit node and connect on
		{
			DFS_R(graph,visit, i, fout); //recursive function
		}
	}
	return true;
}

bool Kruskal(Graph* graph, ofstream* fout)
{
	multimap < int, pair<int, int> > weight; //multimap


	for(int i=0; i<graph->getSize(); i++)
	{
		for (int j = i+1; j < graph->getSize(); j++) {
			if (graph->connectCheck(i, j)) { //connect on
				weight.insert(pair<int, pair<int, int> >(graph->connectCheck(i, j), pair<int, int>(i, j))); //insert wegiht, from, to
			}
		}
	}

	multimap< int, pair<int, int> >::iterator it; //iterator
	it = weight.begin();
	int s1, s2;
	int sum = 0;

	vertexSet a(graph->getSize()); //vertexSet class

	for (;it != weight.end(); it++) //when iterator is not end
	{
		s1 = a.Find(it->second.first); s2 = a.Find(it->second.second); //s1 = from, s2 = to
		if (s1 != s2) {
			a.Union(it->second.first, it->second.second); //union
			*fout << it->first << " "; //print
			sum += it->first; //sum weight
		}
	}
	*fout << "\n" << sum << endl; //sum weight
	return true;
}

bool Dijkstra(Graph* graph, int baseV, ofstream* fout)
{
	*fout << baseV << endl;
	map<int, int >* len = new map<int, int> [graph->getSize()];
	bool *visit = new bool[graph->getSize()];
	memset(visit, false, graph->getSize()); //reset
	int cur = baseV;
	int curDistance = 0;
	len[baseV][0] = -1; //reset
		for (int i = 0; i < graph->getSize(); i++)
		{
			visit[cur] = true;
			curDistance = MAX;
			graph->getIncidentEdges(cur, len); //incidentEdges function
			for (int j = 0; j < graph->getSize(); j++)
			{
				if (!len[j].empty())//len is not empty
				if (!visit[j] && curDistance > len[j].begin()->first) //if the distance is sort
				{
					curDistance = len[j].begin()->first; //change
					cur = j;
				}
			}
		}
	
	//print
	int weight;
	map< int, int>::iterator it;
	int path;
	for (int i = 0; i < graph->getSize(); i++, it++)
	{
		it = len[i].begin();
		if (i != baseV) //baseV is not print
		{
			*fout << "[" << i << "] ";
			while (it->second != baseV)
			{
				*fout << it->second << " "; //path print
				it = len[it->second].begin();
			}
			*fout << it->second;
			*fout << " (" << len[i].begin()->first << ")" << endl; //distance print
		}
	}

	
	return true;
}