#ifndef _String_h
#define _String_h

#include <stdbool.h>

struct CharString;

typedef struct CharString* String;

static const size_t NPOS = -1;

struct CharString {
	char* base_;
	size_t size_;
	size_t capacity_;
};

String String_(const char* str);

String CopyOfString(String str);

void _String(String S);

char* AtOfString(String str, size_t pos);

size_t Size(const String str);

void SwapOfString(String a, String b);

void ResizeOfString(String S, size_t n, char c);

void ReserveOfString(String str, size_t n);

char* BeginOfString(String S);

char* EndOfString(String S);

void PushBackOfString(String str, char c);

void AppendOfString(String S, const char* str);

void InsertOfString(String S, size_t pos, const char* str);

void EraseOfString(String S, size_t pos, size_t len);

void ShowOfString(String str);

size_t FindOfString(String S, const char* str, size_t pos);

void ClearOfString(String S);

void SubstrOfString(String source, size_t pos, size_t len, String destination);

bool GreaterOfString(String S1, String S2);
bool GreaterAndEqualOfString(String S1, String S2);
bool LessOfString(String S1, String S2);
bool LessAndEqualOfString(String S1, String S2);
bool EqualOfString(String S1, String S2);
bool NotEqualOfString(String S1, String S2);

#endif // !_String_h
