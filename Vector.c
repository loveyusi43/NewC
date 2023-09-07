#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "Vector.h"
#include "Utility.h"

Vector Vector_(size_t step) {
	Vector temp = malloc(sizeof(struct VectorArray));
	assert(temp);

	temp->step_ = step;
	temp->start_ = NULL;
	temp->finish_ = NULL;
	temp->end_of_storage_ = NULL;

	return temp;
}

void _Vector(Vector V) {
	free(V->start_);
	free(V);
}

bool EmptyOfVector(Vector V) {
	return SizeOfVector(V) == 0;
}

size_t SizeOfVector(Vector V) {
	size_t bit_len = (char*)V->finish_ - (char*)V->start_;
	return bit_len / V->step_;
}

size_t CapacityOfVector(Vector V) {
	size_t bit_len = (char*)V->end_of_storage_ - (char*)V->start_;
	return bit_len / V->step_;
}

void ReserveOfVector(Vector V, size_t n) {
	size_t size = SizeOfVector(V);
	if (n < size) {
		size = n;
	}

	void* temp = realloc(V->start_, n * V->step_);
	assert(temp);

	V->start_ = temp;
	V->finish_ = (char*)V->start_ + size * V->step_;
	V->end_of_storage_ = (char*)V->start_ + n * V->step_;
}

void ResizeOfVector(Vector V, size_t n, const void* val) {
	// 1. 空间不够扩容
	if (n > CapacityOfVector(V)) {
		ReserveOfVector(V, n);
	}

	if (n > SizeOfVector(V)) {
		//Advance(V->start_, n, V->step_);
		while (V->finish_ < Advance(V->start_, (int)n, V->step_)) {
			memcpy(V->finish_, &val, V->step_);
			(char*)V->finish_ += V->step_;
		}
	}
	else {
		V->finish_ = (char*)V->start_ + n * V->step_;
	}
}

void PushBackOfVector(Vector V, void* x) {
	if (V->finish_ == V->end_of_storage_) {
		size_t length = CapacityOfVector(V) == 0 ? 1 : 2 * CapacityOfVector(V);
		ReserveOfVector(V, length);
	}

	memmove(V->finish_, &x, V->step_);
	(char*)V->finish_ += V->step_;
}

//void PushBackOfVector(Vector V, void* x) {
//	InsertOfVector(V, V->finish_, &x);
//}

void* AtOfVector(Vector V, size_t pos) {
	return (char*)V->start_ + pos * V->step_;
}

void* BeginOfVector(Vector V) {
	return V->start_;
}

void* EndOfVector(Vector V) {
	return V->finish_;
}

void PopBackOfVector(Vector V) {
	(char*)V->finish_ -= V->step_;
}

void* InsertOfVector(Vector V, void* pos, void* x) {
	// 1.扩容; 若发生扩容还要处理pos失效的问题！！！！
	if (V->finish_ == V->end_of_storage_) {
		size_t space = (char*)pos - (char*)V->start_;

		size_t length = CapacityOfVector(V) == 0 ? 1 : 2 * CapacityOfVector(V);
		ReserveOfVector(V, length);

		pos = (char*)V->start_ + space;
	}

	// 2.移动数据
	size_t size = (char*)V->finish_ - (char*)pos;
	memmove((char*)pos + V->step_, pos, size);

	//IteratorOfVector end = (char*)V->finish_ - V->step_;
	//while (end >= pos) {
	//	//memmove((char*)end + V->step_, end, V->step_);
	//	memcpy((char*)end + V->step_, end, V->step_);
	//	(char*)end -= V->step_;
	//}

	// 3.插入数据
	memmove(pos, &x, V->step_);
	(char*)V->finish_ += V->step_;

	return pos;
}

// erase返回删除位置下一个元素的迭代器
void* EraseOfVector(Vector V, void* pos) {
	void* src = (char*)pos + V->step_;
	size_t size = (char*)V->finish_ - (char*)src;
	memmove(pos, src, size);
	(char*)V->finish_ -= V->step_;

	return pos;
}

Vector CopyOfVector(Vector V) {
	// 1. 创建拷贝对象
	Vector copy = malloc(sizeof(struct VectorArray));
	assert(copy);

	// 2. 获取源对象信息
	size_t size = SizeOfVector(V);
	size_t capacity = CapacityOfVector(V);

	// 3. 设置三个控制指针
	copy->step_ = V->step_;
	copy->start_ = malloc(capacity * V->step_);
	copy->finish_ = (char*)copy->start_ + size * V->step_;
	copy->end_of_storage_ = (char*)copy->start_ + capacity * V->step_;

	// 4.拷贝数据
	assert(copy->start_);
	memcpy(copy->start_, V->start_, size * copy->step_);

	return copy;
}

void* FrontOfVector(Vector V) {
	return V->start_;
}

void* BackOfVector(Vector V) {
	return (char*)V->finish_ - V->step_;
}