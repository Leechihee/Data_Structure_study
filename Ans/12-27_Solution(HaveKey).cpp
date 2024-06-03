#include <iostream>
#include <vector>
#include "./header/Custom_tree.h"

using namespace std;

bool HaveKey(const vector<int> arr, const int Key);

int main()
{
	vector<int> arr = {12,45,789,32,56,78,2,3,456,85,265,42};
	
	if(HaveKey(arr,42))
		cout << "해당 Vector 내부에 42가 존재합니다\n";
	else
		cout << "해당 Vector 내부에 42가 존재하지 않습니다\n";

	return 0;
}

bool HaveKey(const vector<int> arr, const int Key)
{
	BStree<int> find42;
	for(int i = 0;i<arr.size();i++)
		find42.Insert(arr[i]);
	return find42.KeySearch(Key);
}