#define _CRT_SECURE_NO_WARNINGS 1

#include "PriorityQueue.h"

PriorityQueue PriorityQueue_(size_t step, Compare cmp) {
	PriorityQueue PQ = malloc(sizeof(*PQ));
	assert(PQ);

	PQ->cmp_ = cmp;
	PQ->V_ = Vector_(step);

	return PQ;
}

void _PriorityQueue(PriorityQueue PQ) {
	_Vector(PQ->V_);
	free(PQ);
}

void PushOfPriority(PriorityQueue PQ, void* val) {
	PushBackOfVector(PQ->V_, val);

	size_t index = SizeOfVector(PQ->V_) - 1;
	PercolateUp(PQ->V_, index, PQ->cmp_);
}

void PopOfPriority(PriorityQueue PQ) {
	void* top_ptr = AtOfVector(PQ->V_, 0);
	size_t index = SizeOfVector(PQ->V_) - 1;
	void* tail_ptr = AtOfVector(PQ->V_, index);
	SwapMem(top_ptr, tail_ptr, PQ->V_->step_);

	PopBackOfVector(PQ->V_);

	PercolateDown(PQ->V_, 0, PQ->cmp_);
}

const void* TopOfPriority(PriorityQueue PQ) {
	return AtOfVector(PQ->V_, 0);
}

bool EmptyOfPriority(PriorityQueue PQ) {
	return EmptyOfVector(PQ->V_);
}

size_t SizeOfPriority(PriorityQueue PQ) {
	return SizeOfVector(PQ->V_);
}