#include"Sort.h"

int main()
{
	int arr[] = { 2,5,3465,6,352,4,4,25,4324,52,44,56,456,6,13 };
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}