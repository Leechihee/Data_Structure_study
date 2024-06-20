#include <iostream>
#include <string>
#include "header/Custom_graph/Custom_graph.h"

using namespace std;

int main()
{
	ADMatrix<char> test(7,1);
	
	char input[] = {'a','b','c','d','e','f','g'};
	
	int arrSize = sizeof(input)/sizeof(char);
	
	for(int i = 0;i<arrSize;i++)
		test.insertVertex(input[i]);
	
	//a
	test.insertEdge(input[0],input[1],5);
	test.insertEdge(input[0],input[2],4);
	test.insertEdge(input[0],input[3],2);
	//b
	test.insertEdge(input[1],input[2],1);
	test.insertEdge(input[1],input[4],2);
	//c
	test.insertEdge(input[2],input[4],3);
	//d
	test.insertEdge(input[3],input[2],1);
	test.insertEdge(input[3],input[5],1);
	//f
	test.insertEdge(input[5],input[6],2);
	//g
	test.insertEdge(input[6],input[2],1);
	
	// test.floyd_Algorithm();
	
	test.showGraph();
	return 0;
}