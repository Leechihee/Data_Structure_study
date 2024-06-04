#include <iostream>

int hesh(char* string, int size);

using namespace std;
int main()
{
	char input[] = "DATASTRUCTURES";
	cout << hesh(input,10) << endl;
	return 0;
}

int hesh(char* string, int size)
{
	int i = 0, temp = 0;
	while(string[i] != '\0')
		temp = (temp*100 +string[i++]<<3)%size;
	return temp;
}