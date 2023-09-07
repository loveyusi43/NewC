#ifndef _Utility_h
#define _Utility_h

#include <stdlib.h>
#include "Vector.h"
#include "String.h"
#include "List.h"

void SwapOfInt(int* a, int* b);
void SwapOfDouble(double* a, double* b);
void SwapOfFloat(float* a, float* b);
void SwapOfChar(char* a, char* b);
void SwapOfSize_t(size_t* a, size_t* b);
void SwapOfChar_(char** a, char** b);

#define Swap(x,y) _Generic(x,\
	int*:SwapOfInt((int*)x,(int*)y),\
	double*:SwapOfDouble((double*)x,(double*)y),\
	float*:SwapOfFloat((float*)x,(float*)y),\
	char*:SwapOfChar((char*)x, (char*)y),\
	size_t*:SwapOfSize_t((size_t*)x, (size_t*)y),\
	char**:SwapOfChar_((char**)x, (char**)x),\
	default:perror("Not Swap"))

size_t MinOfSize_t(size_t x, size_t y);
#define Min(x,y) _Generic(x,\
	size_t:MinOfSize_t((size_t)x, (size_t)y),\
	default:perror("Not Min"))

typedef bool (*Compare)(const void*, const void*);

void PercolateUp(Vector V, size_t child, Compare cmp);

void AdjustDown(void* base, size_t len, size_t size, Compare cmp);

void PercolateDown(Vector V, size_t parents, Compare cmp);

void SwapMem(void* ptra, void* ptrb, size_t step);

void* Advance(void* base, int num, size_t size);

void Reverse(void* left, void* right, size_t size);

#endif // !_Utility_H
