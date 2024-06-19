#include <iostream>
#include <string>
#include "header/Custom_graph/Custom_graph.h"

using namespace std;

int main()
{
	ADList<int> test(5);
	
	for(int i = 0;i<5;i++)
		test.insertVertex(i);
	
	test.insertEdge(1,4);
	test.graphTravel(1);
	return 0;
}