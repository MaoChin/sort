#include "insert.hpp"
#include "bubbleSort.hpp"
#include "quickSort.hpp"

using namespace std;

void Print(int* arr, int len)
{
	for(int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[10] = {1,19, 22,7,-1,100,22,1,-33,0};
	// insertSort(arr, 10);
	// bubbleSort(arr, 10);
	// shellSort(arr, 10);
	// Print(arr, 10);
	// int arr1[5] = {5,4,3,2,1};
	// shellSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
	// Print(arr1, 5);
	quickSort(arr, 0, 9);
	Print(arr, 10);


	return 0;
}
