#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Record{
public:
	string key;
	int hesh;
	int DoubleHesh;
	Record() {}
	Record(const string Key, const int Hesh1, const int Hesh2) : key(Key), hesh(Hesh1), DoubleHesh(Hesh2) {}
	~Record() {}
};

int main()
{
	vector<string> input = {"Kim", "Park", "Choi", "Yoo", "Youn", "Lee", "Chung"};
	vector<int> hesh1 = {1,10,9,4,4,10,10};
	vector<int> hesh2 = {3,2,10,2,4,5,1};
	
	Record record[7];
	for(int i = 0;i<input.size();i++)
		record[i] = Record(input[i],hesh1[i],hesh2[i]);
	
	vector<string> hesh_table(11, "None");
	
	int index;
	for(int i = 0;i<input.size();i++)
	{
		index = record[i].hesh;
		while(1)
		{
			if(hesh_table[index] == "None")
			{
				hesh_table[index] = record[i].key;
				break;
			}
			else
				index = (index + record[i].DoubleHesh) % hesh_table.size();
		}
	}
	
	int vec_index = 0;
	for(auto i = hesh_table.begin();i != hesh_table.end();i++,vec_index++)
		cout << vec_index << " " << *i << " / ";
	cout << endl;
	return 0;
}