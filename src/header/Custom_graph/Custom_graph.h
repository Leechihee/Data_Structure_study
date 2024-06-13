#ifndef CUSTOM_GRAPH_H_
#define CUSTOM_GRAPH_H_
#include "../Custom_list/Custom_list.h"

template<typename A>
class ADMatrix{
	int vertex;
	int edge;
	int vertex_count;
	int** matrix;
	A* dataArr;
	bool isFull() const;
public:
	// 생성자 & 파괴자
	ADMatrix(const int Vertex_counts);
	~ADMatrix();
	// 메트릭스 수정 메서드
	void insertVertex(const A Data);
	void insertEdge(const A Vertex1, const A Vertex2);
	void showGraph() const;
	void showInfor() const;
};

template<typename B>
class ADList{
	int vertex;
	int edge;
	int vertex_count;
	B* dataArr;
	class node{
	public:
		B key;
		class node* next = NULL;
	};
	List<node>* nodeArr;
	bool isFull() const;
public:
	// 생성자 & 파괴자
	ADList(const int Vertex_counts);
	~ADList();
	// 리스트 수정 메서드
	void insertVertex(const B Data);
	void insertEdge(const B Vertex1, const B Vertex2);
};

#include "Custom_matrix.hpp"
#include "Custom_adlist.hpp"
#endif