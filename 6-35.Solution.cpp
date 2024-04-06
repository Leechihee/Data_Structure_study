#include "Custom_stack.h"
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int toNumber(string str);
int sq(int target,int count);
string toString(int num);

int main()
{
	Stack<string> num(10);
	
	cout << "연산자와 피연산자 개수의 합을 입력하시오. : ";
	int count;
	int target1, target2, sum = 0;
	(cin>>count).ignore(2,'\n');
	string input;
	cout << "계산할 수식을 후위표기로 입력하시오 : ";
	for(int i = 0;i<count;i++)
	{
		cin >> input;
		if(input[0] < '*' || input[0] > '/')
		{
			num.Push(input);
		}
		else
		{
			target2 = toNumber(num.Pop());
			target1 = toNumber(num.Pop());
			switch(input[0])
			{
				case '+':
					sum = target1 + target2;
					num.Push(toString(sum));
					break;
				case '-':
					sum = target1 - target2;
					num.Push(toString(sum));
					break;
				case '*':
					sum = target1 * target2;
					num.Push(toString(sum));
					break;
				case '/':
					if(target1 < target2)
						sum += 0;
					else
						sum = target1 / target2;
					num.Push(toString(sum));
					break;
				default:
					cout << "연산자오류!\n";
					exit(-1);
			}
		}
	}
	cout << num.Pop() << endl;
	return 0;
}

int toNumber(string str)
{
	int result = 0;
	for(int i = str.size();i>0;i--)
		result += int(str[str.size()-i]-'0') * sq(10,i-1);
	return result;
}

string toString(int num)
{
	string result = "";
	if(num == 0)
		result = "0";
	else
	{
		while(num != 0)
		{
			result += char(num % 10) + '0';
			num /= 10;
		}
		reverse(result.begin(),result.end());
	}
	return result;
}

int sq(int target, int count)
{
	double result = 1;
	for(int i = 0;i<count;i++)
		result *= target;
	return result;
}
