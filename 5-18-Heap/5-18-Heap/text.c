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

// 对数组进行堆排序
void HeapSort(int* arr, int n)
{
	// 降序 建小堆
	// 升序 建大堆
	for (int i=1;i<n;i++)
	{
		// 当前是小堆 降序
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