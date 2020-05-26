#include "CommonFunctions.h"
#pragma warning(disable : 4996)
float SquareVectorLength(int _x1, int _y1, int _x2, int _y2) {
	return (_x2 - _x1) * (_x2 - _x1) + (_y2 - _y1) * (_y2 - _y1);
}

float VectorLength(int _x1, int _y1, int _x2, int _y2) {
	return sqrt(SquareVectorLength(_x1, _y1, _x2, _y2));
}

bool StringCompare(const char* _a,const char* _b) {
	int i;
	for (i = 0;_a[i] != '\0' && _b[i] != '\0'; i++) {
		if (_a[i] != _b[i])
			return false;
	}
	if (_a[i] == _b[i] && _a[i] == '\0')
		return true;
	else
		return false;
}

int StrLen(const char* str) { //подсчет длинны строки
	if (str == nullptr) return 0;
	int i = 0;
	while (str[i] != '\0') i++;
	return i+1;
}

char* CopyString(const char* _from) { //копирование строки 
	int len = StrLen(_from);
	if (_from == nullptr) return nullptr;
	char* ret = new char[len];
	for (int i = 0; i < len; i++)
		ret[i] = _from[i];
	return ret;
	
}

char* StringToChar(string* str) {
	char * cstr = new char[str->length()];
	strcpy(cstr, str->c_str());
	return cstr;
}