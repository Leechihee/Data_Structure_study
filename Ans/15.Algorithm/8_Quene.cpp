#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

bool _8_Quene(int count, vector<int>& arr);
bool promising(int count, vector<int> arr);

int main()
{
	vector<int> point(8);
	int input;
	for(int i = 0;i<4;i++)
	{
		cin>>input;
		point[i] = input;
	}
	_8_Quene(3, point);
	for(int i = 0;i<point.size();i++)
		cout << point[i] << " ";
	cout << endl;
	return 0;
}

bool _8_Quene(int count, vector<int>& arr)
{
	int test = count;
	int arrcount = arr.size();
	vector<int> num;
	for(int i = 1;i<=arr.size();i++)
	{
		if(*find(arr.begin(),arr.end(),i))
			continue;
		num.push_back(i);
	}
	bool flag = false;
	if(promising(count,arr))
	{
		if(count == arr.size()-1)
			return true;
		else
		{
			for(int j = 0;j<num.size();j++)
			{
				arr[count+1] = num[j];
				flag = _8_Quene(count+1,arr);
				if(flag)
					return true;
				arr[count+1] = 0;
			}
		}
	}
	return false;
}

bool promising(int count, vector<int> arr)
{
	bool flag = true;
	for(int i = 0;i<count && flag;i++)
	{
		if(abs(arr[count]-arr[i]) == count - i)
			return false;
	}
	return true;
}