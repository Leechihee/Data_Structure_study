#ifndef CUSTOM_GRAPH_H_
#define CUSTOM_GRAPH_H_

template<typename datatype>
class ADMatrix{
	int vertex;
	int edge;
	datatype** matrix;
public:
	ADMatrix(const int Vertex);
};

#include "Custom_graph.hpp"
#endif