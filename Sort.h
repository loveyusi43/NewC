#ifndef _Sort_h
#define _Sort_h

#include "Utility.h"
#include "Vector.h"
#include "Stack.h"

void InsertionSort(Vector V, Compare cmp);

void ShellSort(Vector V, Compare cmp);

void SelectSort(Vector V, Compare cmp);

void HeapSort(Vector V, Compare cmp);

void BubbleSort(Vector V, Compare cmp);

void QuickSort(Vector V, Compare cmp);

void MergeSort(Vector V, Compare cmp);

void CountSort(int* array, size_t num, Compare cmp);

#endif // !_Sort_h	