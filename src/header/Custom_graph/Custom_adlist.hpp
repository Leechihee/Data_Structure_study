#ifndef CUSTOM_ADLIST_HPP_
#define CUSTOM_ADLIST_HPP_
#include "../Custom_list/Custom_list.h"
#include "../errorCode.h"

namespace
{
	using namespace std;
}

// ADList Private Method
template<typename datatype>
void ADList<datatype>::findVertex(int indexArr[], const datatype Vertex1, const datatype Vertex2)
{
	for(int i = 0;i<vertex_count && (indexArr[0] == -1 || indexArr[1] == -1);i++)
	{
		if(dataArr[i] == Vertex1)
			indexArr[0] = i;
		if(dataArr[i] == Vertex2)
			indexArr[1] = i;
	}
	if(indexArr[0] == -1 || indexArr[1] == -1)
		throw ERROR_CORD::NOT_FIND;
}

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
	nodeArr = new List<datatype>[vertex];
}

template<typename datatype>
ADList<datatype>::~ADList()
{
	delete [] dataArr;
	delete [] nodeArr;
}

// 리스트 수정 메서드
template<typename datatype>
void ADList<datatype>::insertVertex(const datatype Data)
{
	if(!isFull())
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
	int index[2] = {-1,-1};
	try
	{
		findVertex(index, Vertex1, Vertex2);
	}
	catch(char* ERROR_CORD)
	{
		cout << "insertEdge() : 정점을 " << ERROR_CORD;
		exit(-1);
	}
	if(!(nodeArr[index[0]].FindData(Vertex2)+1))
	{
		nodeArr[index[0]].Insert(1,Vertex2);
		nodeArr[index[1]].Insert(1,Vertex1);
		edge++;
	}
}

template<typename datatype>
void ADList<datatype>::deleteEdge(const datatype Vertex1, const datatype Vertex2)
{
	int index[2] = {-1,-1};
	try
	{
		findVertex(index, Vertex1, Vertex2);
	}
	catch(char* ERROR_CORD)
	{
		cout << "deleteEdge() : " << ERROR_CORD;
		exit(-1);
	}
	nodeArr[index[0]].Delete(nodeArr[index[0]].FindOrAdd(dataArr[index[1]]));
	nodeArr[index[1]].Delete(nodeArr[index[1]].FindOrAdd(dataArr[index[0]]));
}

template<typename datatype>
void ADList<datatype>::graphTravel(const datatype Vertex) const
{
	int index = -1;
	for(int i = 0;i<vertex_count;i++)
	{
		if(dataArr[i] == Vertex)
		{
			index = i;
			break;
		}
	}
	cout << "정점 " << dataArr[index] << "와 인접한 정점은 ";
	nodeArr[index].show();
	cout << "이다.\n";
}
#endif