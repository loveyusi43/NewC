#ifndef _PriorityQueue_h
#define _PriorityQueue_h

#include "Vector.h"
#include "Utility.h"

typedef struct {
	Compare cmp_;
	Vector V_;
}*PriorityQueue;

PriorityQueue PriorityQueue_(size_t step, Compare cmp);

void _PriorityQueue(PriorityQueue PQ);

void PushOfPriority(PriorityQueue PQ, const void* val);

void PopOfPriority(PriorityQueue PQ);

const void* TopOfPriority(PriorityQueue PQ);

bool EmptyOfPriority(PriorityQueue PQ);

size_t SizeOfPriority(PriorityQueue PQ);

#endif // !_PriorityQueue_h
