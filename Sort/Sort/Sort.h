#pragma once


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int* a, int n);


// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);	

// ѡ������
void SelectSort(int* a, int n);


// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
void PartSort(int* a, int left, int right);
// ���������ڿӷ�
void PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
void PartSort3(int* a, int left, int right);

//void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
//void QuickSortNonR(int* a, int left, int right);


// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);