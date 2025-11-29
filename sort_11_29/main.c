#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SortPrint(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
 
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void InsertSort(int* arr, int n)
{
	for (int i = 0; i <= n - 2; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j <= n - 1 - gap; j += gap)
			{
				int end = j;
				int tmp = arr[end + gap];
				while (end >= 0)
				{
					if (arr[end] > tmp)
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
						break;
				}
				arr[end + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int max = begin, min = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[max] < arr[i])
			{
				max = i;
			}
			if (arr[min] > arr[i])
			{
				min = i;
			}
		}
		swap(&arr[min], &arr[begin]);
		if (begin == max)
		{
			max = min;
		}
		swap(&arr[max], &arr[end]);
		if (end == min)
		{
			min = max;
		}
		begin++;
		end--;
	}
}

int main()
{
	int arr1[] = { 1,5,3,3,43,534,34,3,42,4,234,23 };
	int arr2[] = { 9,1,2,5,7,4,6,3 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int n3 = sizeof(arr1) / sizeof(arr1[0]);
	
	//InsertSort(arr, n);
	//SortPrint(arr, n);
	//BubbleSort(arr, n);
	//ShellSort(arr, n);
	SelectSort(arr2, n2);
	SelectSort(arr1, n1);
	SortPrint(arr2, n2);
	SortPrint(arr1, n1);
	return 0;
}