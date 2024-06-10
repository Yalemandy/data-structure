#define _CRT_SECURE_NO_WANINGS 1

#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int  i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
}

// ²åÈëÅÅÐò
void InsertSort(int* a, int n)
{
	int end = 1;
	while (end < n)
	{
		while (end > 0)
		{
			int tmp = end - 1;
			if (a[tmp] < a[end])
			{

			}
		}
	}
}