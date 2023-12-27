#pragma once

#include <iostream>

// 插入排序
void insertSort(int* arr, int len)
{
	for(int i = 0; i < len - 1; ++i)
	{
		int end = i;
		int tmp = arr[end + 1];
		while(end >= 0)
		{
			if(arr[end] > tmp)
				arr[end + 1] = arr[end];
			else
			{
				arr[end + 1] = tmp;
				break;
			}
			--end;
		}
		if(end < 0) arr[0] = tmp;
	}
}

// 希尔排序
void shellSort(int* arr, int len)
{
	int gap = len;
	while(gap > 1)
	{
		gap = gap / 3 + 1;
		for(int i = 0; i < len - gap; ++i)
		{
			int end = i;
			int tmp = arr[i + gap];
			while(end >= 0)
			{
				if(arr[end] > tmp)
					arr[end + gap] = arr[end];
				else
					break;
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}














