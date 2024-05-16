#include <iostream>
#include "Custom_queue.h"

const int N = 41;
const int M = 3;

int main()
{
	using namespace std;
	
	Queue<int> input(N);
	
	for(int i = 1;i<=N;i++)
		input.Add(i);

	int temp;
	for(int i = 1;input.GetSize() != 1;i++)
	{
		temp = input.Remove();
		if(i % M == 0)
			continue;
		else
			input.Add(temp);
	}
	
	cout << "마지막 남는 하나의 값은 " << input.Remove() << " 입니다!\n";
	
	return 0;
}
