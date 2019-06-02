#ifndef _VERTEXSET_H_
#define _VERTEXSET_H_

#include <iostream>

class vertexSet
{
private:
	int* m_Parent;
	int m_Size;

public:
	vertexSet(int size) {
		m_Size = size; 
		m_Parent = new int[m_Size];
		
		for (int i = 0; i < m_Size; i++)
		{
			m_Parent[i] = -1; //reset -1
		}
	}
	~vertexSet() {};
	
	int Find(int ver)
	{
		while (m_Parent[ver] >= 0) //root find
			ver = m_Parent[ver];
		return ver; //root
	}

	void Union(int v1, int v2)
	{
		m_Parent[v1] = v2; //parent setting
	}
};
#endif
