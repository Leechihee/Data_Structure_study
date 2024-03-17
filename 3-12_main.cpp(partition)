#include <iostream>
#include <iomanip>
using namespace std;

void Solution(int input[],int first,int last,int index);

int main()
{
    int arr_size = 12;
	int index = 6;
    int input[arr_size] = {7,10,2,8,16,1,3,4,22,14,12,13}; // 1 2 3 4 7 8 10 12 13 14 16 22
    Solution(input,0,arr_size,index);
	cout << input[index-1] << endl;
    return 0;
}

void Solution(int input[],int first,int last,int index)
{
    if(first == 1 || last == 1 || first >= last)
        return;
    int pivot = input[last-1];
    int up = first, down = last-2;
    int temp;
    while(up < down)
    {
        for(;input[up] <= pivot;up++)
		{
			if(up>down)
				break;
			else
				continue;
		}
        for(;input[down] >= pivot;down--)
		{
			if(up>down)
				break;
			else
				continue;
		} 
        temp = input[up];
        if(up > down)
        {
            input[last-1] = input[up];
            input[up] = pivot;
        }
        else
        {
            input[up] = input[down];
            input[down] = temp;
        }
    }
    for(int k = first;k<last;k++)
        cout << setw(2) << left << input[k] << " ";
	
    cout << endl;
	if(up > index)
		Solution(input,first,up,index);
	else
		Solution(input,up+1,last,index-down);
}
