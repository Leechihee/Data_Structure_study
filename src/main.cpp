#include <iostream>
#include <string>
#include "header/Custom_graph/Custom_graph.h"

using namespace std;

int main()
{
	ADMatrix<string> test(5);

	string arr[] = {"a","b","c","d","e"};
	for(int i = 0;i<5;i++)
		test.insertVertex(arr[i]);
	// test.showGraph();
	return 0;
}