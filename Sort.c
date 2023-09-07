#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void InsertionSort(Vector V, Compare cmp) {
	size_t size = SizeOfVector(V);
	for (size_t i = 1; i < size; ++i) {
		void* temp_ptr = NULL;
		memcpy(&temp_ptr, AtOfVector(V, i), V->step_);
		size_t j = 0;
		for (j = i; j >= 1 && cmp(&temp_ptr, AtOfVector(V, j - 1)); --j) {
			memcpy(AtOfVector(V, j), AtOfVector(V, j - 1), V->step_);
		}
		memcpy(AtOfVector(V, j), &temp_ptr, V->step_);
	}
}

void ShellSort(Vector V, Compare cmp) {
	size_t size = SizeOfVector(V);
	for (size_t increment = size / 2; increment > 0; increment /= 2) {
		for (size_t i = increment; i < size; ++i) {
			void* temp = NULL;
			memcpy(&temp, AtOfVector(V, i), V->step_);
			size_t j = 0;
			for (j = i; j >= increment; j -= increment) {
				if (cmp(&temp, AtOfVector(V, j - increment))) {
					memcpy(AtOfVector(V, j), AtOfVector(V, j - increment), V->step_);
				}
				else {
					break;
				}
			}
			memcpy(AtOfVector(V, j), &temp, V->step_);
		}
	}
}

void SelectSort(Vector V, Compare cmp) {
	size_t num = SizeOfVector(V);
	int left = 0;
	size_t right = num - 1;

	while (left < right) {
		int min_index = left;
		int max_index = left;
		for (int i = left + 1; i <= right; ++i) {
			if (cmp(AtOfVector(V, i), AtOfVector(V, max_index))) {
				max_index = i;
			}
			if (cmp(AtOfVector(V, i), AtOfVector(V, min_index))) {
				min_index = i;
			}
		}
		SwapMem(AtOfVector(V, left), AtOfVector(V, min_index), V->step_);
		if (max_index == left) {
			max_index = min_index;
		}
		SwapMem(AtOfVector(V, right), AtOfVector(V, max_index), V->step_);
		++left; --right;
	}
}

void HeapSort(Vector V, Compare cmp) {
	int num = (int)SizeOfVector(V);
	for (int i = (num - 2) / 2; i >= 0; --i) {
		PercolateDown(V, i, cmp);
	}
	int right = num - 1;
	while (right > 0) {
		SwapMem(AtOfVector(V, 0), AtOfVector(V, right), V->step_);
		AdjustDown(V->start_, right--, V->step_, cmp);
	}

	Reverse(V->start_, V->finish_, V->step_);
}

void BubbleSort(Vector V, Compare cmp) {
	size_t num = SizeOfVector(V);
	for (size_t i = 0; i < num - 1; ++i) {
		bool exchange = false;
		for (size_t j = 1; j < num - i; ++j) {
			if (cmp(AtOfVector(V, j), AtOfVector(V, j - 1))) {
				SwapMem(AtOfVector(V, j - 1), AtOfVector(V, j), V->step_);
				exchange = true;
			}
		}
		if (!exchange) {
			break;
		}
	}
}

void Median3(Vector V, size_t left, size_t right, Compare cmp) {
	size_t mid = left + ((right - left) >> 1);
	size_t pivot = mid;

	if (cmp(AtOfVector(V, left), AtOfVector(V, right))) {
		if (cmp(AtOfVector(V, mid), AtOfVector(V, left))) {
			pivot = left;
		}
		else if (cmp(AtOfVector(V, right), AtOfVector(V, mid))) {
			pivot = right;
		}
		else {
			pivot = mid;
		}
	}
	else {
		if (!cmp(AtOfVector(V, mid), AtOfVector(V, left))) {
			pivot = left;
		}
		else if (!cmp(AtOfVector(V, right), AtOfVector(V, mid))) {
			pivot = right;
		}
		else {
			pivot = mid;
		}
	}

	if (left != pivot)
		SwapMem(AtOfVector(V, left), AtOfVector(V, pivot), V->step_);
}

int PartHoare(Vector V, int left, int right, Compare cmp) {
	Median3(V, left, right, cmp);

	int pivot = left;

	while (left < right) {
		while (left < right && (!memcmp(AtOfVector(V, pivot), AtOfVector(V, right), V->step_) || cmp(AtOfVector(V, pivot), AtOfVector(V, right)))) {
			--right;
		}
		while (left < right && (!memcmp(AtOfVector(V, left), AtOfVector(V, pivot), V->step_) || cmp(AtOfVector(V, left), AtOfVector(V, pivot)))) {
			++left;
		}
		SwapMem(AtOfVector(V, left), AtOfVector(V, right), V->step_);
	}
	SwapMem(AtOfVector(V, left), AtOfVector(V, pivot), V->step_);
	return left;
}

int PartPit(Vector V, int left, int right, Compare cmp) {
	Median3(V, left, right, cmp);

	int pit = left;
	void* pivot = NULL;
	memcpy(&pivot, AtOfVector(V, left), V->step_);

	while (left < right) {
		while (left < right && (!memcmp(&pivot, AtOfVector(V, right), V->step_) || cmp(&pivot, AtOfVector(V, right)))) {
			--right;
		}
		memcpy(AtOfVector(V, pit), AtOfVector(V, right), V->step_);
		pit = right;

		while (left < right && (!memcmp(&pivot, AtOfVector(V, right), V->step_) || cmp(AtOfVector(V, left), &pivot))) {
			++left;
		}
		memcpy(AtOfVector(V, pit), AtOfVector(V, left), V->step_);
		pit = left;
	}
	memcpy(AtOfVector(V, pit), &pivot, V->step_);
	return pit;
}

int PartPtr(Vector V, int left, int right, Compare cmp) {
	Median3(V, left, right, cmp);

	int pre = left;
	int cur = left + 1;
	int pivot = left;

	while (cur <= right) {
		if (cmp(AtOfVector(V, cur), AtOfVector(V, pivot)) && ++pre != cur) {
			SwapMem(AtOfVector(V, pre), AtOfVector(V, cur), V->step_);
		}
		++cur;
	}
	SwapMem(AtOfVector(V, pivot), AtOfVector(V, pre), V->step_);
	return pre;
}

void _InsertionSort(void* array, int n, Compare cmp, size_t size) {
	for (int i = 1; i < n; ++i) {
		void* temp = NULL;
		memcpy(&temp, Advance(array, i, size), size);
		int j = 0; // 最终要插入的位置
		for (j = i; j >= 1 && cmp(&temp, Advance(array, j-1, size)); j--) {
			memcpy(Advance(array, j, size), Advance(array, j - 1, size), size); // 把元素向后挪
		}
		memcpy(Advance(array, j, size), &temp, size);
	}
}

void QuickSortRecursion(Vector V, int begin, int end, Compare cmp) {
	if (begin >= end) {
		return;
	}

	if (end - begin < 10) {
		_InsertionSort(Advance(V->start_, begin, V->step_), end - begin + 1, cmp, V->step_);
	}
	else {
		//int key = PartHoare(V, begin, end, cmp);
		//int key = PartPit(V, begin, end, cmp);
		int key = PartPtr(V, begin, end, cmp);
		QuickSortRecursion(V, begin, key - 1, cmp);
		QuickSortRecursion(V, key + 1, end, cmp);
	}
}

void QuickSortNotRecursion(Vector V, int begin, int end, Compare cmp) {
	Stack range = Stack_(sizeof(int));

	PushOfStack(range, (void*)end);
	PushOfStack(range, (void*)begin);

	while (!EmptyOfStack(range)) {
		int left = *(int*)TopOfStack(range);
		PopOfStack(range);
		int right = *(int*)TopOfStack(range);
		PopOfStack(range);

		int key = PartHoare(V, left, right, cmp);

		if (left < key - 1) {
			PushOfStack(range, (void*)(key - 1));
			PushOfStack(range, (void*)left);
		}
		if (key + 1 < right) {
			PushOfStack(range, (void*)right);
			PushOfStack(range, (void*)(key + 1));
		}
	}

	_Stack(range);
}

void QuickSort(Vector V, Compare cmp) {
	//QuickSortRecursion(V, 0, (int)SizeOfVector(V) - 1, cmp);
	QuickSortNotRecursion(V, 0, (int)SizeOfVector(V) - 1, cmp);
}

void MergeSortRecursion(Vector V, int begin, int end, Vector temp, Compare cmp) {
	if (begin >= end) {
		return;
	}
	int mid = begin + ((end - begin) >> 1);

	MergeSortRecursion(V, begin, mid, temp, cmp);
	MergeSortRecursion(V, mid+1, end, temp, cmp);

	int begin1, end1, begin2, end2;
	begin1 = begin, end1 = mid;
	begin2 = mid+1, end2 = end;

	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2) {
		if (cmp(AtOfVector(V, begin1), AtOfVector(V, begin2))) {
			memcpy(AtOfVector(temp, i++), AtOfVector(V, begin1++), V->step_);
		}
		else {
			memcpy(AtOfVector(temp, i++), AtOfVector(V, begin2++), V->step_);
		}
	}
	while (begin1 <= end1) {
		memcpy(AtOfVector(temp, i++), AtOfVector(V, begin1++), V->step_);
	}
	while (begin2 <= end2) {
		memcpy(AtOfVector(temp, i++), AtOfVector(V, begin2++), V->step_);
	}

	memcpy(AtOfVector(V, begin), AtOfVector(temp, begin), (end - begin + 1) * sizeof(int));
}

void MergeSortNotRecursion(Vector V, Vector temp, Compare cmp) {
	int num = (int)SizeOfVector(V);
	int gap = 1;
	while (gap < num) {
		for (int i = 0; i < num; i += 2 * gap) {
			int begin1, end1, begin2, end2;
			begin1 = i, end1 = i + gap - 1;
			begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= num) {
				end1 = num - 1;
				begin2 = num;
				end2 = num - 1;
			}
			else if (begin2 >= num) {
				begin2 = num;
				end2 = num - 1;
			}
			else if (end2 >= num){
				end2 = num - 1;
			}

			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2) {
				if (cmp(AtOfVector(V, begin1), AtOfVector(V, begin2))) {
					memcpy(AtOfVector(temp, j++), AtOfVector(V, begin1++), V->step_);
				}
				else {
					memcpy(AtOfVector(temp, j++), AtOfVector(V, begin2++), V->step_);
				}
			}
			while (begin1 <= end1) {
				memcpy(AtOfVector(temp, j++), AtOfVector(V, begin1++), V->step_);
			}
			while (begin2 <= end2) {
				memcpy(AtOfVector(temp, j++), AtOfVector(V, begin2++), V->step_);
			}
		}
		memcpy(V->start_, temp->start_, sizeof(int) * num);
		gap *= 2;
	}
}

void MergeSort(Vector V, Compare cmp) {
	Vector temp = Vector_(V->step_);
	//ResizeOfVector(temp, SizeOfVector(V), 0);
	ReserveOfVector(temp, SizeOfVector(V));

	//MergeSortRecursion(V, 0, (int)SizeOfVector(V) - 1, temp, cmp);
	MergeSortNotRecursion(V, temp, cmp);

	_Vector(temp);
}

void CountSort(int* array, size_t num, Compare cmp) {
	int max = array[0], min = array[0];
	for (size_t i = 0; i < num; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	int range = max - min + 1;
	int* count = malloc(sizeof(int) * range);
	assert(count);
	memset(count, 0, sizeof(int) * range);

	for (int i = 0; i < num; ++i) {
		++count[array[i] - min];
	}

	int index = 0;
	int a = 0;
	int b = 1;
	if (cmp(&a, &b)) {
		for (int i = 0; i < range; ++i) {
			while (count[i]--) {
				array[index++] = i + min;
			}
		}
	}
	else {
		for (int i = range - 1; i >= 0; --i) {
			while (count[i]--) {
				array[index++] = i + min;
			}
		}
	}

	free(count);
}