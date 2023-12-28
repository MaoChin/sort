#pragma once
#include <algorithm>
#include <stack>

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

int getMiddleIndex(int* arr, int left, int right)
{
	int middle = left + (right - left) / 2;
	if(arr[left] < arr[middle])
	{
		if(arr[middle] < arr[right]) return middle;
		else if(arr[right] < arr[left]) return left;
		else return right;
	}
	else
	{
		if(arr[left] < arr[right]) return left;
		else if(arr[right] < arr[middle]) return middle;
		else return right;
	}
}

// v3.0 前后指针法
int onceSort3(int* arr, int left, int right)
{
	// 三数取中法优化
	int middle = getMiddleIndex(arr, left, right);
	std::swap(arr[middle], arr[left]);

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

	// 小区间优化
	// if(end - begin + 1 < 10)
	// {
	// 	// 使用其他排序
	// }
	// else
	// {
	  int middle = onceSort3(arr, begin, end);
	  quickSort(arr, begin, middle - 1);
	  quickSort(arr, middle + 1, end);
	// }
}

// 借助栈进行非递归编写
void quickSort2(int* arr, int begin, int end)
{
	std::stack<int> st;
	st.push(begin);
	st.push(end);
	while(!st.empty())
	{
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();

		int mid = onceSort3(arr, left, right);
		// 把左右区间入栈
		if(left < mid - 1)
		{
			st.push(left);
			st.push(mid - 1);
		}
		if(mid + 1 < right)
		{
			st.push(mid + 1);
			st.push(right);
		}
	}
}


















