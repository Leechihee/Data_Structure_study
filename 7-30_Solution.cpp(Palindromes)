//회문 판단 프로그렘
#include <iostream>
#include <string>
#include "Custom_queue.h"
#include "Custom_stack.h"

int main()
{
	using namespace std;
	Queue<char> word_1(10);
	Stack<char> word_2(10);
	
	string input;
	cout << "회문인지 확인할 단어를 입력하시오. : ";
	getline(cin,input);
	for(int i = 0;i<input.size();i++)
	{
		word_1.Add(input[i]);
		word_2.Push(input[i]);
	}
	
	while(!word_1.isEmpty() && !word_2.isEmpty())
	{
		if(word_1.Remove() != word_2.Pop())
		{
			cout << "회문이 아닙니다.\n";
			return -1;
		}
	}
	cout << "회문입니다.\n";
	return 0;
}
