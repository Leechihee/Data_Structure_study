#include <iostream>
#include <string>
#include "header/Custom_graph/Custom_graph.h"

using namespace std;

int main()
{
	ADMatrix<int> test(5);
	
	for(int i = 1;i<=5;i++)
		test.insertVertex(i);
	
	test.insertEdge(1,5);
	test.insertEdge(1,4);
	test.graphTravel(1);
	test.graphTravel(5);
	test.deleteEdge(1,5);
	test.graphTravel(1);
	test.graphTravel(5);
	return 0;
}