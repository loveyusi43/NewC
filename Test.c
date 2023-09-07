#define _CRT_SECURE_NO_WARNINGS 1

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <graphics.h>
#include "Utility.h"
#include "String.h"
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Sort.h"

void TestString();

void TestVector();

void ShowIntVector(Vector V);

void ShowIntList(List L);

void TestList();

void TestStack();

void ShowIntStack(Stack S);

void TestQueue();

void ShowIntQueue(Queue Q);

void TestPriorityQueue(void);

bool GreaterIntPtr(const void* x, const void* y) {
	return *(int*)x > *(int*)y;
}

bool LessIntPtr(const void* x, const void* y) {
	return *(int*)x < *(int*)y;
}

void TestSort(void);

Vector GetRandomVector(size_t size, int begin, int end);

int main(void) {
	srand((unsigned int)time(0));
	//TestStack();
	//TestList();
	//TestQueue();
	//TestPriorityQueue();
	//TestVector();
	//Vector V = GetRandomVector(10, 0, 100);
	//ShowIntVector(V);
	//InsertionSort(V, LessIntPtr);
	//ShellSort(V, GreaterIntPtr);
	//ShellSort(V, GreaterIntPtr);
	//printf("V->start_=%p  V->finish_=%p", V->start_, V->finish_);
	//Reverse(V->start_, V->finish_, V->step_);
	//HeapSort(V, GreaterIntPtr);
	//BubbleSort(V, LessIntPtr);
	//ShowIntVector(V);
	//_Vector(V);
	TestSort();
	return 0;
}

void TestSort(void) {
	Vector V = Vector_(sizeof(int));
	PushBackOfVector(V, (void*)3);
	PushBackOfVector(V, (void*)0);
	PushBackOfVector(V, (void*)6);
	PushBackOfVector(V, (void*)1);
	PushBackOfVector(V, (void*)2);
	PushBackOfVector(V, (void*)9);
	PushBackOfVector(V, (void*)4);
	PushBackOfVector(V, (void*)5);
	PushBackOfVector(V, (void*)7);
	PushBackOfVector(V, (void*)8);
	PushBackOfVector(V, (void*)10);
	PushBackOfVector(V, (void*)8);
	PushBackOfVector(V, (void*)99);
	
	ShowIntVector(V);
	//QuickSort(V, GreaterIntPtr);
	//MergeSort(V, GreaterIntPtr);
	CountSort(V->start_, SizeOfVector(V), LessIntPtr);
	ShowIntVector(V);

	_Vector(V);
}

Vector GetRandomVector(size_t size, int begin, int end) {
	Vector V = Vector_(sizeof(int));

	for (size_t i = 0; i < size; ++i) {
		//int val = rand() % end + begin;
		size_t val = i;
		PushBackOfVector(V, (void*)val);
	}

	return V;
}

void TestPriorityQueue(void) {
	//PriorityQueue PQ = PriorityQueue_(sizeof(int), GreaterIntPtr);
	PriorityQueue PQ = PriorityQueue_(sizeof(int), LessIntPtr);

	PushOfPriority(PQ, (void*)3);
	PushOfPriority(PQ, (void*)1);
	PushOfPriority(PQ, (void*)2);
	PushOfPriority(PQ, (void*)5);
	PushOfPriority(PQ, (void*)0);
	PushOfPriority(PQ, (void*)8);

	while (!EmptyOfPriority(PQ)) {
		printf("%d ", *(int*)TopOfPriority(PQ));
		PopOfPriority(PQ);
	}

	_PriorityQueue(PQ);
}

void ShowIntQueue(Queue Q) {
	printf("size=%zu\n", SizeOfQueue(Q));

	while (!EmptyOfQueue(Q)) {
		printf("%d ", *(int*)FrontOfList(Q));
		PopOfQueue(Q);
	}

	printf("\nsize=%zu\n", SizeOfQueue(Q));
}

void TestQueue() {
	Queue Q = Queue_(sizeof(int));

	PushOfQueue(Q, (void*)1);
	PushOfQueue(Q, (void*)2);
	PushOfQueue(Q, (void*)3);
	PushOfQueue(Q, (void*)4);
	PushOfQueue(Q, (void*)5);

	ShowIntQueue(Q);

	_Queue(Q);
}

void ShowIntStack(Stack S) {
	while (!EmptyOfStack(S)) {
		printf("%d ", *(int*)TopOfStack(S));
		PopOfStack(S);
	}
	printf("\n");
}

void TestStack() {
	Stack s1 = Stack_(sizeof(int));
	PushOfStack(s1, (void*)1);
	PushOfStack(s1, (void*)2);
	PushOfStack(s1, (void*)3);
	PushOfStack(s1, (void*)4);
	PushOfStack(s1, (void*)5);
	ShowIntStack(s1);
	Stack s2 = CopyOfStack(s1);
	ShowIntStack(s2);

	_Stack(s2);
	_Stack(s1);
}

void TestList() {
	List L = List_(sizeof(int));

	PushBackOfList(L, (void*)1);
	PushBackOfList(L, (void*)2);
	PushBackOfList(L, (void*)3);
	PushBackOfList(L, (void*)4);
	PushBackOfList(L, (void*)5);

	*(int*)FrontOfList(L) = (void*)8;
	printf("%d\n", *(int*)FrontOfList(L));
	PopBackOfList(L);
	printf("size=%zu\n", SizeOfList(L));

	_List(L);
}

void ShowIntList(List L) {
	PositionOfList first = L->header_->next_;
	while (first != L->header_) {
		printf("%d->", (int)first->element_);
		first = first->next_;
	}
	printf("header\n");

	PositionOfList tail = L->header_->prev_;
	while (tail != L->header_) {
		printf("%d->", (int)tail->element_);
		tail = tail->prev_;
	}
	printf("header\n");
}

void TestVector() {
	Vector V = Vector_(sizeof(int));

	int a = 0;
	PushBackOfVector(V, (void*)a);
	ShowIntVector(V);

	_Vector(V);
}

void TestString() {
	String s1 = String_("hello world");
	String s2 = CopyOfString(s1);
	_String(s1);
	ShowOfString(s2);
	_String(s2);
}

void ShowIntVector(Vector V) {
	void* it = BeginOfVector(V);
	while (it != EndOfVector(V)) {
		printf("%d ", *(int*)it);
		++(int*)it;
	}
	printf("\n");
}