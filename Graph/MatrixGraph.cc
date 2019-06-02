#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(bool type, bool directed, bool weighted, int size) : Graph(type, directed, weighted, size)
{

	m_Mat = new int *[size];

	for (int i = 0; i<size; i++)
		m_Mat[i] = new int[size];
}

MatrixGraph::~MatrixGraph()
{
}

void MatrixGraph::getIncidentEdges(int vertex, map<int, int>* m)
{	

	for (int i = 0; i < m_Size; i++)
	{
		if (connectCheck(vertex, i))//connect on
		{
			m[i][m[vertex].begin()->first + m_Mat[vertex][i]] = vertex;//calculate
		}
	}
}

void MatrixGraph::insertEdge(int from, int to, int weight)
{
	m_Mat[from][to] = weight; //connect, weight
}

bool	MatrixGraph::printGraph(ofstream* fout)
{
	for (int i = 0; i < m_Size; i++)
	{
		for (int j = 0; j < m_Size; j++)
		{
			*fout << m_Mat[i][j] << " "; //print
		}
		*fout << endl;
	}
	return true;
}

int MatrixGraph::connectCheck(int from, int to)
{
	if (m_Mat[from][to]) //weight exist
		return m_Mat[from][to]; //weight return
	return 0;
}
