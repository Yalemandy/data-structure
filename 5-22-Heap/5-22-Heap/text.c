#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef int HPDataType;

struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};

void Swap(HPDataType* q1, HPDataType* q2)
{
	HPDataType tmp = *q1;
	*q1 = *q2;
	*q2 = tmp;
}

// 小堆 
// 向上调整
void AdjustUp(HPDataType* a,int child)
{
	int child_father = (child - 1) / 2;
	while(child > 0 )
	{
		if (a[child] < a[child_father])
		{
			Swap(&a[child], &a[child_father]);
			child = child_father;
			child_father = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 小堆
// 向下调整
void AdjustDown(HPDataType* a, int n,int child_father)
{
	// 假设左孩子小
	int maxchild = child_father * 2 + 1;
	while (child_father < n)
	{
		// 判断是否是左孩子小
		if (a[maxchild] > a[maxchild + 1] && (maxchild + 1) < n)
		{
			maxchild++;
		}

		if (a[maxchild] < a[child_father])
		{
			Swap(&a[maxchild], &a[child_father]);
			child_father = maxchild;
			maxchild = child_father * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 升序 建大堆
// 降序 建小堆
void HeapSort(int* a, int n)
{
	for (int i=0;i<n;i++)
	{
		// 小堆
		AdjustUp(a,i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void CreateNDate()
{
	// 造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 100000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK()
{
	int k = 0;
	scanf("%d",&k);
	int* arr = (int*)malloc(sizeof(int) * k);
	if (arr == NULL)
	{
		perror("malloc fail!");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// 读取文件中前k个数
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &arr[i]);
	}

	// 创建k个数据的小堆
	for (int i = (k - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(arr, i, 0);
	}

	// 读取剩下的N-K个数
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > arr[0])
		{
			arr[0] = x;
			AdjustDown(arr, k, 0);
		}
	}

	// 打印
	for (size_t i = 0; i < k; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	/*int arr[] = { 313,23131,5345,6456546,442 };
	HeapSort(arr,5);*/
	// CreateNDate();
	PrintTopK();
	return 0;
}