#pragma once

#include <iostream>
#include <algorithm>

void bubbleSort(int* arr, int len)
{
	for(int i = len - 1; i >= 0; --i)
	{
		int flag = 1;
		for(int j = 0; j < i; ++j)
		{
			if(arr[j] > arr[j + 1])
			{
				flag = 0;
				std::swap(arr[j], arr[j + 1]);
			}
		}
		if(flag) break;
	}
}
