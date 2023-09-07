#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

List List_(size_t step) {
	List L = malloc(sizeof(*L));
	assert(L);
	L->step_ = step;
	L->size_ = 0;

	L->header_ = malloc(sizeof(struct ListNode));
	assert(L->header_);
	L->header_->next_ = L->header_;
	L->header_->prev_ = L->header_;

	return L;
}

void PushBackOfList(List L, void* x) {
	/*PositionOfList header = L->header_;
	PositionOfList tail = header->prev_;
	PositionOfList cur = malloc(sizeof(*cur));
	assert(cur);
	memmove(&cur->element_, &x, L->step_);
	tail->next_ = cur;
	cur->next_ = header;
	header->prev_ = cur;
	cur->prev_ = tail;*/

	InsertOfList(L, L->header_, x);
}

PositionOfList InsertOfList(List L, PositionOfList pos, void* x) {
	PositionOfList prev = pos->prev_;
	PositionOfList cur = malloc(sizeof(*cur));
	assert(cur);

	memmove(&cur->element_, &x, L->step_);

	prev->next_ = cur;
	cur->next_ = pos;
	pos->prev_ = cur;
	cur->prev_ = prev;

	++L->size_;
	return cur;
}

void PushFrontOfList(List L, void* x) {
	InsertOfList(L, L->header_->next_, x);
}

PositionOfList EraseOfList(List L, PositionOfList pos) {
	assert(pos != L->header_);

	PositionOfList prev = pos->prev_;
	PositionOfList next = pos->next_;
	free(pos);

	prev->next_ = next;
	next->prev_ = prev;

	--L->size_;
	return next;
}

void PopFrontOfList(List L) {
	EraseOfList(L, L->header_->next_);
}

void PopBackOfList(List L) {
	EraseOfList(L, L->header_->prev_);
}

PositionOfList FindOfList(List L, void* val) {
	PositionOfList next = L->header_->next_;
	PositionOfList prev = L->header_->prev_;
	PositionOfList header = L->header_;

	while (next != header && prev != header) {
		//printf("%d %d\n", (int)next->element_, (int)prev->element_);
		if ((int)val == (int)next->element_) {
			return next;
		}
		if ((int)val == (int)prev->element_) {
			return prev;
		}

		next = next->next_;
		prev = prev->prev_;
	}

	return NULL;
}

List CopyOfList(List L) {
	List copy = List_(L->step_);

	PositionOfList header = L->header_;
	PositionOfList cur = header->next_;
	while (cur != header) {
		PushBackOfList(copy, cur->element_);
		cur = cur->next_;
	}

	return copy;
}

void _List(List L) {
	ClearOfList(L);
	free(L->header_);
	free(L);
}

bool EmptyOfList(List L) {
	PositionOfList header = L->header_;
	return header->next_ == header && header->prev_ == header;
}

void ClearOfList(List L) {
	while (!EmptyOfList(L)) {
		PopBackOfList(L);
	}
}

void SwapOfList(List a, List b) {
	Swap(&a->step_, &b->step_);

	PositionOfList temp = a->header_;
	a->header_ = b->header_;
	b->header_ = temp;
}

void* FrontOfList(List L) {
	return &L->header_->next_->element_;
}

void* BackOfList(List L) {
	return &L->header_->prev_->element_;
}

size_t SizeOfList(List L) {
	return L->size_;
}