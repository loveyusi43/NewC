#ifndef _Vector_h
#define _Vector_h

#include <stdbool.h>

struct VectorArray;
typedef struct VectorArray* Vector;

struct VectorArray {
	size_t step_;

	void* start_;
	void* finish_;
	void* end_of_storage_;
};

Vector Vector_(size_t step);

Vector CopyOfVector(Vector V);

void _Vector(Vector V);

void* BeginOfVector(Vector V);

void* EndOfVector(Vector V);

bool EmptyOfVector(Vector V);

size_t SizeOfVector(Vector V);

size_t CapacityOfVector(Vector V);

void ReserveOfVector(Vector V, size_t n);

void ResizeOfVector(Vector V, size_t n, const void* val);

void* AtOfVector(Vector V, size_t pos);

void PushBackOfVector(Vector V, void* x);

void PopBackOfVector(Vector V);

void* InsertOfVector(Vector V, void* pos, void* x);

void* EraseOfVector(Vector V, void* pos);

void* FrontOfVector(Vector V);

void* BackOfVector(Vector V);

#endif // !_Vector_h
