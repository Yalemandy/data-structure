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

// С�� 
// ���ϵ���
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

// С��
// ���µ���
void AdjustDown(HPDataType* a, int n,int child_father)
{
	// ��������С
	int maxchild = child_father * 2 + 1;
	while (child_father < n)
	{
		// �ж��Ƿ�������С
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

// ���� �����
// ���� ��С��
void HeapSort(int* a, int n)
{
	for (int i=0;i<n;i++)
	{
		// С��
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
	// ������
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

	// ��ȡ�ļ���ǰk����
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &arr[i]);
	}

	// ����k�����ݵ�С��
	for (int i = (k - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(arr, i, 0);
	}

	// ��ȡʣ�µ�N-K����
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > arr[0])
		{
			arr[0] = x;
			AdjustDown(arr, k, 0);
		}
	}

	// ��ӡ
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