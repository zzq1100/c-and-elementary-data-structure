#include"sort.h"

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int key = left;
//	int begin = left, end = right;
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= arr[key])
//		{
//			end--;
//		}
//		while (begin < end && arr[begin] <= arr[key])
//		{
//			begin++;
//		}
//		
//		swap(&arr[begin], &arr[end]);
//	}
//	swap(&arr[key], &arr[begin]);
//	key = begin;
//	QuickSort(arr, left, key - 1);
//	QuickSort(arr, key + 1, right);
//}

//void InsertSort(int* arr, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (arr[end] > tmp)
//			{
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else
//				break;
//		}
//		arr[end + 1] = tmp;
//	}
//}
//
//void ShellSort(int* arr, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < gap; i++)
//		{
//			for (int j = i; j <= n - 1 - gap; j += gap)
//			{
//				int end = j;
//				int tmp = arr[end + gap];
//				while (end >= 0)
//				{
//					if (arr[end] > arr[end + gap])
//					{
//						arr[end + gap] = arr[end];
//						end -= gap;
//					}
//					else
//						break;
//				}
//				arr[end + gap] = tmp;
//			}
//		}
//	}
//}
//
//void SelectSort(int* arr, int n)
//{
//	int begin = 0, end = n - 1;
//	while (begin < end)
//	{
//		int max = begin, min = begin;
//		for (int i = begin + 1; i <= end; i++)
//		{
//			if (arr[i] > arr[max])
//				max = i;
//			if (arr[i] < arr[min])
//				min = i;
//		}
//		swap(&arr[begin], &arr[min]);
//		if (begin == max)
//			max = min;
//		swap(&arr[end], &arr[max]);
//		begin++;
//		end--;
//	}
//}
//
////void AdjustDown(int* a, int n, int parent)
////{
////	int child = parent * 2 + 1;
////
////	while (child < n)  
////	{
////		if (child + 1 < n && a[child + 1] > a[child])
////		{
////			++child;
////		}
////
////		if (a[child] > a[parent])
////		{
////			Swap(&a[child], &a[parent]);
////			parent = child;
////			child = parent * 2 + 1;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
////
////void HeapSort(int* a, int n)
////{
////	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
////	{
////		AdjustDown(a, n, i);
////	}
////	int end = n - 1;
////	while (end > 0)
////	{
////		Swap(&a[0], &a[end]);
////		AdjustDown(a, end, 0);
////		--end;
////	}
////}
//
//int QuickSort2(int* arr, int left, int right)
//{
//	int key = left;
//	int prev = left, cur = prev + 1;
//	while (cur <= right)
//	{
//		if (arr[cur] < arr[key] && ++prev != cur)
//			swap(&arr[cur], &arr[prev]);
//		++cur;
//	}
//	swap(&arr[prev], &arr[key]);
//	return prev;
//}
//
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int key = QuickSort2(arr, left, right);
//	QuickSort(arr, left, key - 1);
//	QuickSort(arr, key + 1, right);
//}

void SelectSort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int max = begin, min = begin;
		for (int i = begin; i < end; i++)
		{
			if (arr[max] < arr[i])
				max = i;
			if (arr[min] > arr[i])
				min = i;
		}
		swap(&arr[begin], &arr[min]);
		if (begin == max)
			max = min;
		swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}