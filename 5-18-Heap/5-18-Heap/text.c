#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Heaptext01()
{
	HPDataType a[] = { 7,232,2,4,5 ,323,342342,5345345,6126,765 ,87};
	Heap hp;
	HeapInit(&hp);
	for (int i=0;i<sizeof(a)/sizeof(HPDataType);i++)
	{
		HeapPush(&hp,a[i]);
	}

	//int k = 0;
	//scanf("%d",&k);
	//for (int i=0;i<k;i++)
	//{
	//	// printf("%d ",HeapTop(&hp));
	//	a[i++] = HeapTop(&hp);
	//	HeapPop(&hp);
	//}
	//printf("\n");
	HeapSort(a,sizeof(a)/sizeof(HPDataType));
	HeapDestory(&hp);
}

// ��������ж�����
void HeapSort(int* arr, int n)
{
	// ���� ��С��
	// ���� �����
	for (int i=1;i<n;i++)
	{
		// ��ǰ��С�� ����
		AdjustUp(arr, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&arr[0] , &arr[end]);
		AdjustDown(arr, end,0);
		end--;	
	}
}

int main()
{
	Heaptext01();
	return 0;
}