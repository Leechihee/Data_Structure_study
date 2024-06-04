//트리 순회프로그렘
#include <iostream>
#include "Custom_tree.h"

void output(int num)
{
	std::cout << num << " ";
}

int main()
{
	using namespace std;
	int count, temp;
	cout << "입력할 데이터의 개수를 입력하시오. : ";
	(cin>>count).ignore(2,'\n');
	cout << "데이터를 입력하시오 : ";
	BStree<int> data;
	for(int i = 0;i<count;i++)
	{
		cin >> temp;
		data.Insert(temp);
	}
	
	cout << "Preorder Traversal Sequence is : "; data.Preorder(output);
	cout << "\nInorder Traversal Sequence is : "; data.Inorder(output);
	cout << "\nPostorder Traversal Sequence is : "; data.Postorder(output);
	cout << endl;
	
	return 0;
}
