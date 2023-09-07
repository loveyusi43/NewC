#ifndef _Queue_h
#define _Queue_h

#include "List.h"

typedef List Queue;

Queue Queue_(size_t step);

void _Queue(Queue Q);

bool EmptyOfQueue(Queue Q);

size_t SizeOfQueue(Queue Q);

void* FrontOfQueue(Queue Q);

void* BackOfQueue(Queue Q);

void PushOfQueue(Queue Q, void* val);

void PopOfQueue(Queue Q);

#endif // !_Queue_h
