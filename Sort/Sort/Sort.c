#define _CRT_SECURE_NO_WANINGS 1

#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 向下排序
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child < n)
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆排序
void HeapSort(int* a, int n)
{
	// 升序，建大堆
	// 降序，建小堆
	for (int i = 0; i < n; i++)
	{
		// 当前建的是小堆
		AdjustDwon(a, i, 0);
	}

	int end = n - 1;

	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		int cmp = 0,flag = 0;
		while (cmp < i)
		{
			if (a[cmp] > a[cmp + 1])
			{
				Swap(&a[cmp], &a[cmp + 1]);
				flag = 1;
			}
			cmp++;
		}
		if (flag == 0)
		{
			break;
		}
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;	
		}
		/*printf("gap:->%2d  ", gap);
		PrintArray(a, n);*/
	}
}


// 选择排序
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int min = left;
		int max = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[min] > a[i])
			{
				min = i;
			}

			if (a[max] < a[i])
			{
				max = i;
			}
		}
		Swap(&a[min], &a[left]);

		if (left == max)
			max = min;

		Swap(&a[max], &a[right]);
		left++;
		right--;
	}
}

int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[midi] < a[right])
		{
			return right;
		}
		else if(a[midi] > a[left])
		{
			return left;
		}
		else
		{
			return midi;
		}
	}
	else // r < l
	{
		if (a[midi] < a[left])
		{
			return left;
		}
		else if (a[midi] < a[left])
		{
			return midi;
		}
		else
		{
			return right;
		}
	}
}

// 快速排序hoare版本
void PartSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if ((left + right) < 10)
	{
		InsertSort(a+left, (right - left + 1));
	}
	else
	{
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);

		int key = left;
		int begin = left;
		int end = right;
		while (begin < end)
		{
			while (begin < end && a[end] >= a[key])
			{
				end--;
			}

			while (begin < end && a[begin] <= a[key])
			{
				begin++;
			}

			Swap(&a[begin], &a[end]);
		}

		Swap(&a[key], &a[begin]);
		key = begin;
		PartSort(a, left, key - 1);
		PartSort(a, key + 1, right);
	}
}

// 快速排序挖坑法
void PartSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	if ((left + right) < 10)
	{
		InsertSort(a + left, (right - left + 1));
	}
	else
	{
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);

		int key = left; // 坑位
		int keyi = a[left];
		int begin = left, end = right;
		while (begin < end)
		{
			while (a[end] >= keyi && begin < end)
			{
				end--;
			}
			if (a[end] < keyi)
			{
				a[key] = a[end];
				key = end;
			}
			while (a[begin] <= keyi && begin < end)
			{
				begin++;
			}
			if (a[begin] > keyi)
			{
				a[key] = a[begin];
				key = begin;
			}
		}
		a[key] = keyi;
		// [left,key-1] key [key+1,right]
		PartSort2(a, left, key - 1);
		PartSort2(a, key + 1, right);
	}
}

// 快速排序前后指针法
void PartSort3(int* a, int left, int right)
{
	if (left >= right)
		return;


	if ((left + right) < 10)
	{
		InsertSort(a + left, (right - left + 1));
	}
	else
	{
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);

		int key = left;
		int prev = left;
		int cur = left + 1;
		while (cur <= right)
		{
			if (a[cur] < a[key])
			{
				prev++;
				Swap(&a[prev], &a[cur]);
			}
			cur++;
		}
		Swap(&a[prev], &a[key]);
		key = prev;
		// [left,key-1] key [key+1,right]
		PartSort3(a, left, key - 1);
		PartSort3(a, key + 1, right);
	}
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	// [begin,mid] [mid+1,end]
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int jk = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{

		if (a[begin1] < a[begin2])
		{
			tmp[jk++] = a[begin1++];
		}
		else
		{
			tmp[jk++] = a[begin2++];
		}

	}

	while (begin1 <= end1)
	{
		tmp[jk++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[jk++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int jk = i;

			if (begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{

				if (a[begin1] < a[begin2])
				{
					tmp[jk++] = a[begin1++];
				}
				else
				{
					tmp[jk++] = a[begin2++];
				}

			}

			while (begin1 <= end1)
			{
				tmp[jk++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[jk++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int dif = max - min + 1;

	int* tmp = (int*)calloc(dif, sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}

	int jk = 0;
	for (int i = 0; i < dif; i++)
	{
		while (tmp[i]--)
		{
			a[jk++] = min + i;
		}
	}

	free(tmp);
	tmp = NULL;
}