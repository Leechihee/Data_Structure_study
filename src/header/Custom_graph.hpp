#ifndef CUSTOM_GRAPH_HPP_
#define CUSTOM_GRAPH_HPP_

template<typename datatype>
ADMatrix<datatype>::ADMatrix(const int Vertex) : vertex(Vertex), edge(0)
{
	matrix = new datatype*[vertex];
	for(int i = 0;i<vertex;i++)
		matrix[i] = new datatype[vertex];
}

#endif