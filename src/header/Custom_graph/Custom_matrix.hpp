#ifndef CUSTOM_MATRIX_HPP_
#define CUSTOM_MATRIX_HPP_
#include "../errorCode.h"
#include "../Custom_stack/Custom_stack.h"
#include <iomanip>
namespace
{
	using namespace std;
}

//ADMatrix Private Method
template<typename datatype>
bool ADMatrix<datatype>::isFull() const
{
	return vertex_count == vertex;
}

template<typename datatype>
void ADMatrix<datatype>::findVertex(int indexArr[], const datatype Vertex1, const datatype Vertex2)
{
	indexArr[0] = -1;
	indexArr[1] = -1;
	
	for(int i = 0;i<vertex && (indexArr[0] == -1 || indexArr[1] == -1);i++)
	{
		if(dataArr[i] == Vertex1)
			indexArr[0] = i;
		if(dataArr[i] == Vertex2)
			indexArr[1] = i;
	}
	
	if(indexArr[0] == -1 || indexArr[1] == -1)
		throw ERROR_CORD::NOT_FIND;
}

// ADMatrix Public Method
// 생성자 & 파괴자
template<typename datatype>
ADMatrix<datatype>::ADMatrix(const int Vertex_counts, const int Mode) : vertex(Vertex_counts), edge(0), vertex_count(0), mode(Mode)
{
	dataArr = new datatype[vertex];
	matrix = new int*[vertex];
	for(int i = 0;i<vertex;i++)
		matrix[i] = new int[vertex];
}

template<typename datatype>
ADMatrix<datatype>::~ADMatrix()
{
	for(int i = 0;i<vertex;i++)
		delete [] matrix[i];
	delete [] matrix;
	delete [] dataArr;
}

// 메트릭스 수정 메서드
template<typename datatype>
void ADMatrix<datatype>::insertVertex(datatype Data)
{
	if(!isFull())
		dataArr[vertex_count++] = Data;
	else
	{
		cout << "정점을 더이상 넣을 수 없습니다.\n";
		exit(-1);
	}
}

template<typename datatype>
void ADMatrix<datatype>::insertEdge(const datatype Vertex1, const datatype Vertex2, const int Weight)
{
	if(!isFull())
	{
		cout << "정점이 가득 차있지않습니다. 추가하세요.\n";
		datatype insert_vel;
		while(!isFull())
		{
			cout << vertex - vertex_count << "번 남았습니다. : ";
			(cin>>insert_vel).ignore(2,'\n');
			insertVertex(insert_vel);
		}
	}
	int index[2];
	try
	{
		findVertex(index, Vertex1, Vertex2);
	}
	catch(char* ERROR_CORD)
	{
		cout << "insertEdge() : 정점을 " << ERROR_CORD;
		exit(-1);
	}
	if(matrix[index[0]][index[1]] == 0)
	{
		matrix[index[0]][index[1]] = Weight;
		edge++;
		if(mode)
			return;
		matrix[index[1]][index[0]] = Weight;
	}
}

template<typename datatype>
void ADMatrix<datatype>::deleteEdge(const datatype Vertex1, const datatype Vertex2)
{
	int index[2];
	try
	{
		findVertex(index, Vertex1, Vertex2);
	}
	catch(char* ERROR_CORD)
	{
		cout << "deleteEdge() : 정점을 " << ERROR_CORD;
		exit(-1);
	}
	matrix[index[0]][index[1]] = 0;
	if(mode)
		return;
	matrix[index[1]][index[0]] = 0;
}

template<typename datatype>
void ADMatrix<datatype>::graphTravel(const datatype Vertex) const
{
	int index = -1;
	for(int i = 0;i<vertex;i++)
	{
		if(dataArr[i] == Vertex)
		{
			index = i;
			break;
		}
	}
	cout << "정점 " << dataArr[index] << "와 인접한 정점은 ";
	for(int i = 0;i<vertex;i++)
	{
		if(matrix[index][i])
			cout << dataArr[i] << "(" << matrix[index][i] << ")";
	}
	cout << "이다.\n";
}

template<typename datatype>
void ADMatrix<datatype>::showGraph() const
{
	cout << '\t';
	for(int i = 0;i<vertex;i++)
		cout << setw(2) << dataArr[i] << '\t';
	cout << endl;
	for(int i = 0;i<vertex;i++)
	{
		cout << dataArr[i] << '\t';
		for(int j = 0;j<vertex;j++)
			cout << setw(2) << matrix[i][j] << '\t';
		cout << endl;
	}
}

template<typename datatype>
void ADMatrix<datatype>::floyd_Algorithm()
{
	for(int i = 0;i<vertex;i++)
	{
		for(int j = 0;j<vertex;j++)
			matrix[i][j] = findEdgeweight(dataArr[i],dataArr[j]);
	}
}

template<typename datatype>
int ADMatrix<datatype>::findEdgeweight(const datatype startVertex, const datatype targetVertex)
{
	int index[2];
	findVertex(index,startVertex,targetVertex);
	Stack<int> DFS(vertex);
	
	return 0;
}
#endif