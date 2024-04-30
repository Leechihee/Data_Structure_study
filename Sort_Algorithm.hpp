#ifndef SORT_ALGORITHM_HPP_
#define SORT_ALGORITHM_HPP_

#include <string>

template<typename A>
void Copy(A* arr1, A* arr2,int size)
{
	for(int i = 0;i<size;i++)
		arr2[i] = arr1[i];
}

namespace {using namespace std;}

template<typename A>
void Select_Sort(A & cont)
{
	for(int i = cont.Size();i>=1;i--)
	{
		int maxIndex = i;
		for(int j = i-1;j>=1;j--)
		{
			if(cont.ReturnData(maxIndex) < cont.ReturnData(j))
				maxIndex = j;
		}
		cont.Swap(maxIndex,i);
	}
}

template<typename A>
void Double_Select_Sort(A & cont)
{
	for(int i = cont.Size();i>=1;i--)
	{
		int maxIndex = i;
		int minIndex = i-i+1;
		for(int j = i-1;j>=1;j--)
		{
			if(cont.ReturnData(maxIndex) < cont.ReturnData(j))
				maxIndex = j;
			else if(cont.ReturnData(minIndex) > cont.ReturnData(j))
				minIndex = j;
		}
		cont.Swap(maxIndex,i);
		cont.Swap(minIndex,1);
	}
}

template<typename A>
void Bubble_Sort(A & cont)
{
	for(int i = cont.Begin();i<=cont.Size();i++)
	{
		for(int j = cont.Begin();j<=cont.Size()-i;j++)
		{
			if(cont.ReturnData(j) > cont.ReturnData(j+1))
				cont.NodeSwap(j);
			else
				continue;
		}
	}
}

template<typename A>
void Insert_Sort(A & cont)
{
	for(int i = cont.Begin()+1;i<=cont.End();i++)
	{
		int index = i,j;
		for(j = i-1;j>=cont.Begin() && cont.ReturnData(j) > cont.ReturnData(i);j--)
			index = j;
		cont.Insert(index,cont.ReturnData(i));
		cont.Delete(i+1);
	}
}

template<typename A>
void Merge_Sort(A & cont)
{
	Merge_Sort_sub(cont,cont.Begin(),cont.End());
}

template<typename A>
void Merge_Sort_sub(A & cont,int first,int end)
{
	if(first >= end)
		return;
	int middle = (first+end)/2,start = first, last = end;
	Merge_Sort_sub(cont,first,middle);
	Merge_Sort_sub(cont,middle+1,end);
	int cont1_first = first, cont1_last = middle;
	int cont2_first = middle+1, cont2_last = end;
	int index = 1;
	A temp;
	while((cont1_first <= cont1_last) && (cont2_first <= cont2_last))
	{
		if(cont.ReturnData(cont1_first) > cont.ReturnData(cont2_first))
		{
			temp.Insert(index,cont.ReturnData(cont2_first));
			cont2_first++;
		}
		else
		{
			temp.Insert(index,cont.ReturnData(cont1_first));
			cont1_first++;
		}
		index++;
	}
	for(;cont1_first <= cont1_last;cont1_first++, index++)
		temp.Insert(index,cont.ReturnData(cont1_first));
	for(;cont2_first <= cont2_last;cont2_first++, index++)
		temp.Insert(index,cont.ReturnData(cont2_first));
	if(first == 1 || first == cont.Size()/2+1)
		cont.nChenge(first,temp);
	else
		cont.nChenge(middle,temp);
}

template<typename A>
void Quick_Sort(A & cont)
{
	Quick_Sort_sub(cont,cont.Begin(), cont.End());
}

template<typename A>
void Quick_Sort_sub(A & cont,int start, int end)
{
	if(start < end)
	{
		int pivot = partition(cont, start, end);
		Quick_Sort_sub(cont, start, pivot-1);
		Quick_Sort_sub(cont, pivot+1, end);
	}
}

template<typename A>
int partition(A & cont, int start, int end)
{
	int up = start, down = end-1, pivot = end;
	while(up <= down)
	{
		while(cont.ReturnData(up) < cont.ReturnData(pivot)) up++;
		while(cont.ReturnData(down) > cont.ReturnData(pivot)) down--;
		if(up <= down)
		{
			cont.Swap(up, down);
		}
	}
	cont.Swap(up,pivot);
	return pivot;
}

void Bucket_Sort(int* arr,int size)
{
	int max = 0;
	for(int i = 0;i<size;i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	int bucket[max+1] = {0};
	for(int i = 0;i<size;i++)
		bucket[arr[i]] = arr[i];
	int count = 0;
	for(int i = 0;i<=max;i++)
	{
		if(bucket[i] > 0)
		{
			arr[count] = bucket[i];
			count++;
		}
	}
}

void Count_Sort(int* arr,int size)
{
	int max = 0;
	for(int i = 0;i<size;i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	int count[max+1] = {0};
	for(int i = 0;i<size;i++)
		count[arr[i]]++;
	for(int i = size-1;i>=0;)
	{
		if(count[max] == 0)
		{
			max--;
			continue;
		}
		else
		{
			arr[i--] = max;
			count[max]--;
		}
	}
}

void LSD_Radix_Sort(string* arr, int size)
{
	string temp[size];
	for(int i = arr[0].size()-1;i>=0;i--)
	{
		int max = 0;
		for(int j = 0;j<size;j++)
		{
			if(max < arr[j][i]-'a')
				max = arr[j][i]-'a';
		}
		int count[max+1] = {0};
		for(int j = 0;j<size;j++)
			count[arr[j][i]-'a']++;
		int index1 = count[0];
		for(int j = 1;j<max+1;j++)
		{
			if(count[j] == 0)
				continue;
			count[j] += index1;
			index1 = count[j];
		}
		for(int j = size-1;j>=0;j--)
		{
			temp[count[arr[j][i]-'a']-1] = arr[j];
			count[arr[j][i]-'a']--;
		}
		Copy(temp,arr,size);
	}
}

void MSD_Radix_Sort_sub(string * arr,int start, int end, int index)
{
	string temp[end+1-start];
	int max = 0;
	for(int j = start;j<end+1;j++)
	{
		if(max < arr[j][index]-'a')
			max = arr[j][index]-'a';
	}
	int count[max+1] = {0},count2[max+1];
	for(int i = start;i<end+1;i++)
		count[arr[i][index]-'a']++;
	Copy(count,count2,max+1);
	int index_temp = count[0];
	for(int i = 1;i<max+1;i++)
	{
		if(count[i] == 0)
			continue;
		count[i] += index_temp;
		index_temp = count[i];
	}
	for(int j = end;j>=start;j--)
	{
		temp[count[arr[j][index]-'a']-1] = arr[j];
		count[arr[j][index]-'a']--;
	}
	index_temp = 0;
	for(int i = 0;i<max+1;i++)
	{
		if(count2[i] > 1)
			MSD_Radix_Sort_sub(temp,count[i],count2[i]+index_temp-1,index+1); // 2 3 1 1 0 1
		index_temp += count2[i];
	}
	for(int i = start;i<end+1;i++)
		arr[i] = temp[i-start];
}

void MSD_Radix_Sort(string * arr,int size)
{
	MSD_Radix_Sort_sub(arr,0,size-1,0);
}
#endif
