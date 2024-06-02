#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int hesh(int key,int table_size);
int NextPrime(int num);
vector<int>* Rehesh(vector<int>* Before_table,int& table_size);

int main()
{
	int size = 13;
	vector<int>* hesh_table = new vector<int>[size];
	for(int i = 0;i<size;i++)
		hesh_table[i] = vector<int>(0);
	int arr[] = {26,14,95,56,617,19,164,38,350,90};
	for(int i = 0;i<sizeof(arr)/sizeof(int);i++)
		hesh_table[hesh(arr[i],size)].push_back(arr[i]);
	cout << "Rehesh 전\n";
	for(int i = 0;i<size;i++)
	{
		if(hesh_table[i].size() == 0)
			continue;
		cout << i << " : ";
		for(int j = 0;j<hesh_table[i].size();j++)
			cout << hesh_table[i][j] << " ";
		cout << endl;
	}
	hesh_table = Rehesh(hesh_table,size);
	cout << "Rehesh 후\n";
	for(int i = 0;i<size;i++)
	{
		if(hesh_table[i].size() == 0)
			continue;
		cout << i << " : ";
		for(int j = 0;j<hesh_table[i].size();j++)
			cout << hesh_table[i][j] << " ";
		cout << endl;
	}
	delete [] hesh_table;
	return 0;
}

int hesh(int key,int table_size)
{
	return key%table_size;
}

int NextPrime(int num)
{
	if(num <= 1)
		return 2;
	else if(num == 2)
		return 3;
	else if(num == 3)
		return 5;
	else
	{
		bool isNotPrime = true;
		while(isNotPrime)
		{
			num++;
			for(int i = 2;i<=sqrt(num);i++)
			{
				if(num%i == 0)
				{
					isNotPrime = true;
					break;
				}
				isNotPrime = false;
			}
		}
	}
	return num;
}

vector<int>* Rehesh(vector<int>* Before_table,int& table_size)
{
	int NewSize = NextPrime(table_size*2);
	vector<int>* NewTable = new vector<int>[NewSize];
	for(int i = 0;i<NewSize;i++)
		NewTable[i] = vector<int>(0);
	for(int i = 0;i<table_size;i++)
	{
		for(int j = 0;j<Before_table[i].size();j++)
			NewTable[hesh(Before_table[i][j],NewSize)].push_back(Before_table[i][j]);
	}
	delete [] Before_table;
	table_size = NewSize;
	return NewTable;
}