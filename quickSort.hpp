#pragma once
#include <algorithm>

// v1.0单趟
int onceSort1(int* arr, int left, int right)
{
	int keyIndex = left;
	while(left < right)
	{
		// 右边找小
		while(left < right && arr[right] >= arr[keyIndex]) --right;
		// 左边找大
		while(left < right && arr[left] <= arr[keyIndex]) ++left;
		std::swap(arr[left], arr[right]);
	}
	std::swap(arr[left], arr[keyIndex]);
	return left;
}

// v2.0 挖坑法
int onceSort2(int* arr, int left, int right)
{
	int tmp = arr[left];
	int holeIndex = left;
	while(left < right)
	{
		while(left < right && arr[right] >= tmp) --right;
		if(left < right)
		{
			arr[holeIndex] = arr[right];
			holeIndex = right;
		}
		while(left < right && arr[left] <= tmp) ++left;
		if(left < right)
		{
			arr[holeIndex] = arr[left];
			holeIndex = left;
		}
	}
	arr[holeIndex] = tmp;
	return holeIndex;
}

// v3.0 前后指针法
int onceSort3(int* arr, int left, int right)
{
	// cur指针和prev指针
	int keyi = left;
	int prev = left;
	int cur = left + 1;

	while(cur <= right)
	{
		if(arr[cur] < arr[left])
		{
			++prev;
			std::swap(arr[prev], arr[cur]);
		}
		++cur;
	}
	std::swap(arr[keyi], arr[prev]);
	return prev;
}

void quickSort(int* arr, int begin, int end)
{
	if(begin >= end)
		return;
	int middle = onceSort3(arr, begin, end);
	quickSort(arr, begin, middle - 1);
	quickSort(arr, middle + 1, end);
}
