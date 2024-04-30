#ifndef SORT_ALGORITHM_H_
#define SORT_ALGORITHM_H_
#include <string>

template<typename A>
void Select_Sort(A & cont);

template<typename A>
void Double_Select_Sort(A & cont);

template<typename A>
void Bubble_Sort(A & cont);

template<typename A>
void Insert_Sort(A & cont);

template<typename A>
void Merge_Sort(A & cont);

template<typename A>
void Quick_Sort(A & cont);

void Bucket_Sort(int* arr,int size);

void Count_Sort(int* arr,int size);

void LSD_Radix_Sort(string* arr, int size);

void MSD_Radix_Sort(string * arr, int start, int end);

#include "Sort_Algorithm.hpp"
#endif
