#ifndef CUSTOM_ADLIST_HPP_
#define CUSTOM_ADLIST_HPP_
#include "../Custom_list/Custom_list.h"

namespace {using namespace std;}

// ADList Private Method
template<typename datatype>
bool ADList<datatype>::isFull() const
{
	return vertex == vertex_count;
}

// ADList Public Method
// 생성자 & 파괴자
template<typename datatype>
ADList<datatype>::ADList(const int Vertex_counts) : vertex(Vertex_counts), edge(0), vertex_count(0)
{
	dataArr = new datatype[vertex];
	nodeArr = new List<node>;
}

template<typename datatype>
ADList<datatype>::~ADList()
{
	delete [] dataArr;
	delete nodeArr;
}

// 리스트 수정 메서드
template<typename datatype>
void ADList<datatype>::insertVertex(const datatype Data)
{
	if(isFull())
		dataArr[vertex_count++] = Data;
	else
	{
		cout << "정점을 더 이상 넣을 수 없습니다.\n";
		exit(-1);
	}
}

template<typename datatype>
void ADList<datatype>::insertEdge(const datatype Vertex1, const datatype Vertex2)
{
	int index1 = -1, index2 = -1;
	for(int i = 0;i<vertex_count;i++)
	{
		if(dataArr[i] == Vertex1)
			index1 = i;
		if(dataArr[i] == Vertex2)
			index2 = i;
	}
	if(index1 == -1 || index2 == -1)
	{
		cout << "해당 정점이 존재하지 않습니다.\n";
		exit(-1);
	}
	else
	{
		
	}
}
#endif