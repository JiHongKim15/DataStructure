#include "ListGraph.h"

ListGraph::ListGraph(bool type, bool directed, bool weighted, int size) : Graph(type, directed, weighted, size)
{
	m_List = new map<int, int>[size]; //list graph size is size
}

ListGraph::~ListGraph()
{
}

void ListGraph::getIncidentEdges(int vertex, map<int, int>* m)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (connectCheck(vertex, i))//connect on
		{
			m[i][m[vertex].begin()->first + m_List[vertex][i]] = vertex;//calculate
		}
	}

}

void ListGraph::insertEdge(int from, int to, int weight)
{
	m_List[from].insert(make_pair(to, weight)); //connect
}
int ListGraph::connectCheck(int from, int to) //connect check
{
	map<int, int> ::iterator i;
	i = m_List[from].begin();

	for (; i != m_List[from].end(); i++) {
		if (to == i->first) //connect on
		{
			if (i->second)
				return i->second; //return weight
		}
	}
	return 0;

}
bool ListGraph::printGraph(ofstream* fout)
{
	map<int, int> ::iterator it;
	for(int i=0; i < m_Size; i++)
	{
		it = m_List[i].begin();
		*fout << i << " ";
		while (it != m_List[i].end()) //print
		{
			*fout << it->first << "," << it->second << " ";
			it++; //iterator next
		}
		*fout << endl;
	}
	return true;
}