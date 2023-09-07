#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "String.h"
#include "Utility.h"


String String_(const char* str) {
	String S = (String)malloc(sizeof(struct CharString));
	assert(S);

	S->size_ = strlen(str);
	S->capacity_ = S->size_;
	S->base_ = (char*)malloc(sizeof(char) * S->size_ + 1);
	assert(S->base_);
	strcpy(S->base_, str);

	return S;
}

String CopyOfString(String str) {
	String copy = String_(str->base_);
	return copy;
}

void _String(String S) {
	free(S->base_);
	free(S);
}

char* AtOfString(String str, size_t pos) {
	return str->base_ + pos;
}

size_t Size(const String str) {
	return str->size_;
}

void SwapOfString(String a, String b) {
	Swap(&a->base_, &b->base_);
	Swap(&a->size_, &b->size_);
	Swap(&a->capacity_, &b->capacity_);
}

char* BeginOfString(String S) {
	return S->base_;
}

char* EndOfString(String S) {
	return S->base_ + S->size_;
}

void ReserveOfString(String str, size_t n) {
	char* temp = realloc(str->base_, n + 1);
	assert(temp);
	str->base_ = temp;
	str->capacity_ = n;

	if (n < str->size_) {
		str->size_ = n;
	}
}

void PushBackOfString(String str, char c) {
	if (str->size_ == str->capacity_) {
		size_t length = str->size_ == 0 ? 1 : 2 * str->capacity_;
		ReserveOfString(str, length);
	}
	str->base_[str->size_++] = c;
	str->base_[str->size_] = '\0';
}

void ShowOfString(String str) {
	printf("%s\n", str->base_);
}

void InsertOfString(String S, size_t pos, const char* str) {
	size_t len = strlen(str);
	if (S->size_ + len > S->capacity_) {
		ReserveOfString(S, S->size_ + len);
	}
	size_t des = S->size_ + len;
	while (des >= pos+len) {
		S->base_[des] = S->base_[des - len];
		--des;
	}
	//strcpy(S->base_ + pos, str);
	strncpy(S->base_ + pos, str, len);
	S->size_ += len;
}

void AppendOfString(String S, const char* str) {
	InsertOfString(S, S->size_, str);
}

void EraseOfString(String S, size_t pos, size_t len) {
	if (len == NPOS || pos + len >= S->size_) {
		S->size_ = pos;
		S->base_[S->size_] = '\0';
	}
	else {
		strcpy(S->base_ + pos, S->base_ + pos + len);
		S->size_ -= len;
	}
}

size_t FindOfString(String S, const char* str, size_t pos) {
	char* p = strstr(S->base_ + pos, str);
	if (p) {
		return p - S->base_;
	}
	else {
		return NPOS;
	}
}

bool GreaterOfString(String S1, String S2) {
	return strcmp(S1->base_, S2->base_) > 0;
}

bool GreaterAndEqualOfString(String S1, String S2) {
	return !LessOfString(S1, S2);
}

bool LessOfString(String S1, String S2) {
	return strcmp(S1->base_, S2->base_) < 0;
}

bool LessAndEqualOfString(String S1, String S2) {
	return !GreaterOfString(S1, S2);
}

bool EqualOfString(String S1, String S2) {
	return strcmp(S1->base_, S2->base_) == 0;
}

bool NotEqualOfString(String S1, String S2) {
	return !EqualOfString(S1, S2);
}

void ClearOfString(String S) {
	S->size_ = 0;
	S->base_[S->size_] = '\0';
}

void SubstrOfString(String source, size_t pos, size_t len, String destination) {
	size_t real_len = len;
	if (len == NPOS || pos + len > source->size_) {
		real_len = source->size_ - pos;
	}

	for (size_t i = 0; i < real_len; ++i) {
		PushBackOfString(destination, source->base_[pos + i]);
	}
}

void ResizeOfString(String S, size_t n, char c) {
	if (n > S->size_) {
		ReserveOfString(S, n);
		for (size_t i = S->size_; i < n; ++i) {
			S->base_[i] = c;
		}
		S->size_ = n;
		S->base_[S->size_] = '\0';
	}
	else {
		S->size_ = n;
		S->base_[S->size_] = '\0';
	}
}