#ifndef CUSTOM_GRAPH_H_
#define CUSTOM_GRAPH_H_
#include "../Custom_list/Custom_list.h"

template<typename A>
class ADMatrix{
	int mode;
	int vertex;
	int edge;
	int vertex_count;
	int** matrix;
	A* dataArr;
	bool isFull() const;
	void findVertex(int indexArr[], const A Vertex1, const A Vertex2);
	int findEdgeweight(const A startVertex,const A targetVertex);
public:
	// 생성자 & 파괴자
	ADMatrix(const int Vertex_counts, const int Mode = nonDir);
	~ADMatrix();
	// 메트릭스 수정 메서드
	void insertVertex(const A Data);
	void insertEdge(const A Vertex1, const A Vertex2, const int Weight = 1);
	void deleteEdge(const A Vertex1, const A Vertex2);
	// 메트릭스 출력 메서드
	void showGraph() const;
	void graphTravel(const A Vertex) const;
	// 알고리즘
	void floyd_Algorithm();
	// 자료구조
	enum{nonDir,Dir};
};

template<typename B>
class ADList{
	int vertex;
	int edge;
	int vertex_count;
	B* dataArr;
	List<B>* nodeArr;
	bool isFull() const;
	void findVertex(int indexArr[], const B Vertex1, const B Vertex2);
public:
	// 생성자 & 파괴자
	ADList(const int Vertex_counts);
	~ADList();
	// 리스트 수정 메서드
	void insertVertex(const B Data);
	void insertEdge(const B Vertex1, const B Vertex2);
	void deleteEdge(const B Vertex1, const B Vertex2);
	void graphTravel(const B Vertex) const;
};

#include "Custom_matrix.hpp"
#include "Custom_adlist.hpp"
#endif