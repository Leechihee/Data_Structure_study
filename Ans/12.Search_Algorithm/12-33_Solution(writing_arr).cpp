#include <iostream>
#include <vector>

using namespace std;

int hesh(int Key);
int doublehesh(int Key);

int main()
{
	vector<int> input = {4371,1326,6175,4199,4344,9679};
	vector<int> hesh_table[3] = {vector<int>(9,0),vector<int>(9,0),vector<int>(9,0)};
	
	int collsion = 0;
	//LinearSearch
	for(int i = 0;i<input.size();)
	{
		int index = (hesh(input[i]) - collsion)%10;
		if(hesh_table[0][index] == 0)
		{
			hesh_table[0][index] = input[i];
			collsion = 0;
			i++;
		}
		else
			collsion++;
	}
	collsion = 0;
	//SquareSearch
	for(int i = 0;i<input.size();)
	{
		int index = (hesh(input[i]) + (collsion*collsion))%10;
		if(hesh_table[1][index] == 0)
		{
			hesh_table[1][index] = input[i];
			collsion = 0;
			i++;
		}
		else
			collsion++;
	}
	collsion = 0;
	//DoubleHeshSearch
	for(int i = 0;i<input.size();)
	{
		int index = (hesh(input[i]) + collsion)%10;
		if(hesh_table[2][index] == 0)
		{
			hesh_table[2][index] = input[i];
			collsion = 0;
			i++;
		}
		else
			collsion = doublehesh(input[i]);
	}
	
	cout << "LinearSearch Result\n";
	for(int i = 0;i<hesh_table[0].size();i++)
		cout << hesh_table[0][i] << " ";
	cout << "\nSquareSearch Result\n";
	for(int i = 0;i<hesh_table[1].size();i++)
		cout << hesh_table[1][i] << " ";
	cout << "\nDoubleHeshSearch Result\n";
	for(int i = 0;i<hesh_table[2].size();i++)
		cout << hesh_table[2][i] << " ";
	cout << endl;
	return 0;
}

int hesh(int Key)
{
	return (Key/10)%10;
}

int Max(int num1, int num2)
{
	return num1<num2 ? num2 : num1;
}

int doublehesh(int Key)
{
	return Max(1,(Key/100)%10);
}