#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

Stack Stack_(size_t step) {
	Vector V = Vector_(step);
	return V;
}

void _Stack(Stack S) {
	_Vector(S);
}

void PushOfStack(Stack S, void* val) {
	PushBackOfVector(S, val);
}

void PopOfStack(Stack S) {
	PopBackOfVector(S);
}

void* TopOfStack(Stack S) {
	return BackOfVector(S);
}

bool EmptyOfStack(Stack S) {
	return EmptyOfVector(S);
}

size_t SizeOfStack(Stack S) {
	return SizeOfVector(S);
}

Stack CopyOfStack(Stack S) {
	Vector V = CopyOfVector(S);
	return V;
}