#include <iostream>
#include <string>
#include "header/Custom_graph/Custom_graph.h"

using namespace std;

int main()
{
	ADList<int> test(5);
	
	for(int i = 1;i<=5;i++)
		test.insertVertex(i);
	
	test.insertEdge(1,3);
	test.insertEdge(1,2);
	test.graphTravel(1);
	return 0;
}