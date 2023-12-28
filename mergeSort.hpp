#pragma once

#include <cstring>

void _mergeSort(int* arr, int left, int right, int* tmpArr)
{
	if(left >= right) return;

	int mid = left + (right - left) / 2;

	// 先递归
	_mergeSort(arr, left, mid, tmpArr);
	_mergeSort(arr, mid + 1, right, tmpArr);

	// 开始归并
	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	int index = left;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(arr[begin1] > arr[begin2]) tmpArr[index++] = arr[begin2++];
		else tmpArr[index++] = arr[begin1++];
	}
	while(begin1 <= end1) tmpArr[index++] = arr[begin1++];
	while(begin2 <= end2) tmpArr[index++] = arr[begin2++];

	// 再把tmpArr中的数据拷贝回arr
  memcpy(arr + left, tmpArr + left, (right - left + 1) * sizeof(int));
}

void mergeSort(int* arr, int len)
{
	// 辅助数组
	int* tmpArr = new int[len];

	_mergeSort(arr, 0, len - 1, tmpArr);

	delete[] tmpArr;
}
