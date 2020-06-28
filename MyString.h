#pragma once
unsigned int strLen(const char* str);
void strCpy(char* dest, const char* source);
void strCat(char* dest, const char* source);
void strReverse(char* str);
void strToUpper(char* str);
void strToLower(char* str);
int strStr(const char* str, const char* substr);
int strCmp(const char* str1, const char* str2);
char* strCpyDin(const char* source);
char* strCatDin(const char* str1, const char* str2);