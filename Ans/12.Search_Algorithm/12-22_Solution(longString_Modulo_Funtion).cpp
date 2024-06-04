#include <iostream>
#include <string>

using namespace std;

int Modulo_119(string arr);

int main()
{
	string input[] = {"floccinaucinihilipilification", "Antidisestablishmentarianism", "pneumonoultramicroscopicsilicovolcanoconiosis", "honorificabilitudinitatibus"};
	
	string hesh_table[119] = {""};
	for(int i = 0;i<sizeof(input)/sizeof(string);i++)
		hesh_table[Modulo_119(input[i])] = input[i];
	for(int i = 0;i<119;i++)
	{
		if(hesh_table[i].size() != 0)
			cout << i << " : " << hesh_table[i] << endl;
	}
	return 0;
}

int Modulo_119(string str)
{
	int ret = (str[0]%119)*10 + str[1];
	for(int i = 2;i<str.size();i++)
		ret = (ret%119)*100 + str[i];
	return ret%119;
}