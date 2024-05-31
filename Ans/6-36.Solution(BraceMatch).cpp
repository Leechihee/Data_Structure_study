//중괄호 매칭 프로그램
#include "Custom_stack.h"

using namespace std;

int main()
{
	Stack<char> temp(10);
	
	char input;
	int success = 0;
	while(cin.get(input) && input != '\n')
	{
		if(input == '{')
			temp.Push(input);
		else if(input == '}')
		{
			if(!temp.isEmpty())
				temp.Pop();
			else
			{
				success++;
				break;
			}
		}
	}
	if(success > 0 || !temp.isEmpty())
	{
		cout << "중괄호 매칭오류!\n";
		exit(-1);
	}
	cout << "중괄호 매칭!\n";
	
	return 0;
}
