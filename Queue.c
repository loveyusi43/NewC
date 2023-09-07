#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

Queue Queue_(size_t step) {
	List L = List_(step);
	return L;
}

void _Queue(Queue Q) {
	_List(Q);
}

bool EmptyOfQueue(Queue Q) {
	return EmptyOfList(Q);
}

size_t SizeOfQueue(Queue Q) {
	return SizeOfList(Q);
}

void* FrontOfQueue(Queue Q) {
	return FrontOfList(Q);
}

void* BackOfQueue(Queue Q) {
	return BackOfList(Q);
}

void PushOfQueue(Queue Q, void* val) {
	PushBackOfList(Q, val);
}

void PopOfQueue(Queue Q) {
	PopFrontOfList(Q);
}