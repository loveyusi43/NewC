#ifndef _List_h
#define _List_h

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "Utility.h"

struct ListNode;
typedef struct ListNode* PositionOfList;
typedef struct {
	size_t step_;
	size_t size_;
	PositionOfList header_;
}*List;

struct ListNode {
	void* element_;
	PositionOfList next_;
	PositionOfList prev_;
};

List List_(size_t step);

List CopyOfList(List L);

void _List(List L);

bool EmptyOfList(List L);

void PushBackOfList(List L, void* x);

void PushFrontOfList(List L, void* x);

PositionOfList InsertOfList(List L, PositionOfList pos, void* x);

void ClearOfList(List L);

PositionOfList EraseOfList(List L, PositionOfList pos);

void PopFrontOfList(List L);

void PopBackOfList(List L);

PositionOfList FindOfList(List L, void* val);

void SwapOfList(List a, List b);

void* FrontOfList(List L);

void* BackOfList(List L);

size_t SizeOfList(List L);

#endif // !_List_h
