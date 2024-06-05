#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

void Swap(int* x, int* y);