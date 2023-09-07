#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void SwapOfInt(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapOfFloat(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void SwapOfDouble(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

void SwapOfChar(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void SwapOfSize_t(size_t* a, size_t* b) {
	size_t temp = *a;
	*a = *b;
	*b = temp;
}

void SwapOfChar_(char** a, char** b) {
	char* temp = *a;
	*a = *b;
	*b = temp;
}

size_t MinOfSize_t(size_t x, size_t y) {
	if (x < y) {
		return x;
	}
	return y;
}

void PercolateUp(Vector V, size_t child, Compare cmp) {
	size_t parents = (child - 1) / 2;
	while (child > 0) {
		void* child_ptr = AtOfVector(V, child);
		void* parents_ptr = AtOfVector(V, parents);

		if (cmp(child_ptr, parents_ptr)) {
			SwapMem(child_ptr, parents_ptr, V->step_);

			child = parents;
			parents = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(void* base, size_t len, size_t size, Compare cmp) {
	size_t parents = 0;
	size_t child = 0 * 2 + 1;
	while (child < len) {
		void* child_ptr = Advance(base, (int)child, size);
		void* parents_ptr = Advance(base, (int)parents, size);

		if (child + 1 < len && cmp(Advance(child_ptr, 1, size), child_ptr)) {
			child_ptr = Advance(child_ptr, 1, size);
		}

		if (cmp(child_ptr, parents_ptr)) {
			SwapMem(child_ptr, parents_ptr, size);
			parents = child;
			child = parents * 2 + 1;
		}
		else {
			break;
		}
	}
}

void PercolateDown(Vector V, size_t parents, Compare cmp) {
	size_t child = parents * 2 + 1;
	size_t size = SizeOfVector(V);

	while (child < size) {
		void* child_ptr = AtOfVector(V, child);
		void* parents_ptr = AtOfVector(V, parents);

		if (child + 1 < size && cmp((char*)child_ptr + V->step_, child_ptr)) {
			child_ptr = (char*)child_ptr + V->step_;
		}

		if (cmp(child_ptr, parents_ptr)) {
			SwapMem(child_ptr, parents_ptr, V->step_);
			parents = child;
			child = parents * 2 + 1;
		}
		else {
			break;
		}
	}
}

void SwapMem(void* ptra, void* ptrb, size_t step) {
	void* copy_mem = malloc(step);
	assert(copy_mem);

	memcpy(copy_mem, ptra, step);
	memcpy(ptra, ptrb, step);
	memcpy(ptrb, copy_mem, step);

	free(copy_mem);
}

void* Advance(void* base, int num, size_t size) {
	return (char*)base + num * size;
}

void Reverse(void* left, void* right, size_t size) {
	right = Advance(right, -1, size);
	while (left < right) {
		SwapMem(left, right, size);
		left = Advance(left, 1, size);
		right = Advance(right, -1, size);
	}
}