#ifndef CUSTOM_MATRIX_HPP_
#define CUSTOM_MATRIX_HPP_

namespace {using namespace std;}

//ADMatrix Private Method
template<typename datatype>
bool ADMatrix<datatype>::isFull() const
{
	return vertex_count == vertex;
}

// ADMatrix Public Method
// 생성자 & 파괴자
template<typename datatype>
ADMatrix<datatype>::ADMatrix(const int Vertex_counts) : vertex(Vertex_counts), edge(0), vertex_count(0)
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
void ADMatrix<datatype>::insertEdge(const datatype Vertex1, const datatype Vertex2)
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
	int index1 = -1, index2 = -1;
	for(int i = 0;i<vertex;i++)
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
		if(matrix[index1][index2] == 0)
		{
			matrix[index1][index2] = 1;
			matrix[index2][index1] = 1;
			edge++;
		}
	}
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
			cout << dataArr[i] << " ";
	}
	cout << "이다.\n";
}
#endif