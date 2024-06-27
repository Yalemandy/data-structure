#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void TextInsertSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	InsertSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextBubbleSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextShellSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1,10,9,8,7,6,5,4,3,2,1,10,9,8,7,6,5,4,3,2,1,10,9,8,7,6,5,4,3,2,1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextSelectSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextPartSort()
{
	int a[] = { 5,2,3,7,9,10,1,4,8,6 };
	PartSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextPartSort2()
{
	int a[] = { 5,2,3,7,9,10,1,4,8,6 };
	PartSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextPartSort3()
{
	int a[] = { 5,2,3,7,9,10,1,4,8,6 };
	PartSort3(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextMergeSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextMergeSortNonR()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TextCountSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		//a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//PartSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//PartSort2(a6, 0, N - 1);
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//PartSort3(a7, 0, N - 1);
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin8 = clock();
	CountSort(a7, N);
	int end8 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);

	printf("HeapSort:%d\n", end4 - begin4);
	printf("PartSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("CountSort:%d\n", end8 - begin8);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

int main()
{
	//TextInsertSort();
	//TextBubbleSort();
	//TextShellSort();
	//TextSelectSort();
	//TextPartSort();
	//TextPartSort2();
	//TextPartSort3();
	//TextMergeSort();
	//TextMergeSortNonR();
	//TextCountSort();

	TestOP();

	return 0;
}