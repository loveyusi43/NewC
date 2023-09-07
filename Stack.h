#ifndef _Stack_h
#define _Stack_h

#include "Vector.h"

typedef Vector Stack;

Stack Stack_(size_t step);

Stack CopyOfStack(Stack S);

void _Stack(Stack S);

void PushOfStack(Stack S, void* val);

void PopOfStack(Stack S);

void* TopOfStack(Stack S);

bool EmptyOfStack(Stack S);

size_t SizeOfStack(Stack S);

#endif // !_Stack_h
