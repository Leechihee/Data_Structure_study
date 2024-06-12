#ifndef CUSTOM_GRAPH_H_
#define CUSTOM_GRAPH_H_

template<typename datatype>
class ADMatrix{
	int vertex;
	int edge;
	int vertex_count;
	int** matrix;
	datatype* dataArr;
	bool isFull() const;
public:
	// 생성자 & 파괴자
	ADMatrix(const int Vertex_counts);
	~ADMatrix();
	// 메트릭스 수정 메서드
	void insertVertex(datatype Data);
	void insertEdge(const datatype Vertex1, const datatype Vertex2);
	void showGraph() const;
	void showInfor() const;
};

#include "Custom_matrix.hpp"
#endif