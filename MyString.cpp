#include <iostream>
#include "MyString.h"

unsigned int strLen(const char* str)
{
    int counter = 0;
    for (counter; str[counter] != '\0'; counter++);
    return counter;
}

void strCpy(char* dest, const char* source)
{
    int len = strLen(source);
    for (int i = 0; i <= len; i++)
    {
        dest[i] = source[i];
    }
}

void strCat(char* dest, const char* source)
{
    int len1 = strLen(dest);
    int len2 = strLen(source);
    for (int i = 0, j = len1; i <= len2; i++, j++)
    {
        dest[j] = source[i];
    }
}

void strReverse(char* str)
{
    int len = strLen(str);
    for (int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

const int diff = 32;

void strToUpper(char* str)
{
    int len = strLen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= diff;
    }
}

void strToLower(char* str)
{
    int len = strLen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += diff;
    }
}

int strStr(const char* str, const char* substr)
{
    bool found = false;
    int len = strLen(str);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        while (str[i] == substr[j])
        {
            if (substr[j + 1] == '\0')
            {
                found = true;
                return i - j;
            }
            if (str[i + 1] != substr[j + 1])
            {
                i -= j;
                i++;
                j = 0;
                break;
            }
            i++, j++;
        }
    }
    if (found == false) return -1;
}

int strCmp(const char* str1, const char* str2)
{
    int len1 = strLen(str1);
    int len2 = strLen(str2);
    if (len1 > len2)
        return 1;
    else if (len2 > len1)
        return -1;

    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] > str2[i])
                return 1;
            else if (str2[i] > str1[i])
                return -1;
        }
    }
    return 0;
}

char* strCpyDin(const char* source)
{
    int len = strLen(source);
    char* newstr = new char[len];
    for (int i = 0; i <= len; i++)
    {
        newstr[i] = source[i];
    }
    return newstr;
}

char* strCatDin(const char* str1, const char* str2)
{
    int len1 = strLen(str1);
    int len2 = strLen(str2);
    char* newstr = new char[len1 + len2];
    for (int i = 0; i < len1; i++)
    {
        newstr[i] = str1[i];
    }
    for (int i = len1, j = 0; i <= len1 + len2; i++, j++)
    {
        newstr[i] = str2[j];
    }
    return newstr;
}



int main()
{
    char str1[20] = "hello";
    char str2[20] = ", world";
    std::cout << strCatDin(str1, str2);
}

