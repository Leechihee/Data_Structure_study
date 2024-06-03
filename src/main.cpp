#include <iostream>
#include <vector>

using namespace std;

int hesh(int Key);

int main()
{
	vector<int> input = {4371,1326,6175,4199,4344,9679};
	vector<int> hesh_table[3] = {vector<int>(9,0)};
	
	int collsion = 0;
	//LinearSearch
	for(int i = 0;i<sizeof(input)/sizeof(int);)
	{
		int index = hesh(input[i]) + collsion;
		if(hesh_table[0][index] == 0)
		{
			hesh_table[0][index] = input[i];
			i++;
		}
		else
			collsion++;
	}
	collsion = 0;
	//SquareSearch
	for(int i = 0;i<sizeof(input)/sizeof(int);)
	{
		int index = hesh(input[i]) + (collsion*collsion);
		if(hesh_table[0][index] == 0)
		{
			hesh_table[0][index] = input[i];
			i++;
		}
		else
			collsion++;
	}
	//DoubleHeshSearch
	for(int i = 0;i<sizeof(input)/sizeof(int);)
	{
		int index = hesh(input[i]) + doublehesh(input[i]);
		if(hesh_table[0][index] == 0)
		{
			hesh_table[0][index] = input[i];
			i++;
		}
		else
			collsion++;
	}
	return 0;
}

int hesh(int Key)
{
	return (Key/10)%10;
}