#pragma once //Здесь расположены невоторые функции, не требующие отдельного класса
#ifndef _COMMON_FUNCTIONS_
#define _COMMON_FUNCTIONS_

#include "Include.h"

float SquareVectorLength(int _x1, int _y1, int _x2, int _y2);

float VectorLength(int _x1, int _y1, int _x2, int _y2);

bool StringCompare(const char* _a, const char* _b);

int StrLen(char* str);

char* CopyString(const char* _from);

char* StringToChar(string* str);

#endif // !_COMMON_FUNCTIONS_
