#include <iostream>

using namespace std;

int bineryfind(int input[], int begin, int end, int target);
int main()
{
	int size = 100,target;
	cin >> target;
	int num[size];
	for(int i = 1;i<=size;i++)
		num[i] = i;
	
	cout << bineryfind(num,0,size,target);
	return 0;
}

int bineryfind(int input[], int begin, int end, int target)
{
	int result;
	if(end - begin < 10)
	{
		for(int i = begin;i<end;i++)
		{
			if(input[i] == target)
				return i;
		}
		return -1;
	}
	int center = (begin + end) / 2;
	if(target < input[center-1])
		result = bineryfind(input,begin,center,target);
	else
		result = bineryfind(input,center,end,target);
	return result;
}
