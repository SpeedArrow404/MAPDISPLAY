#include "FileWorker.h"
char* StringManager(char* _oldArray, int _oldLength, int _newLenght) {
	
	if (_oldArray == nullptr) return new char[_newLenght]; //����� ������� ���������
	
	char* newPtr = new char[_newLenght];
	int lenght; //������ ����������� �������

	if (_oldLength > _newLenght) lenght = _newLenght; //�������� ������ heap fault
	else lenght = _oldLength;

	for (int i = 0; i < lenght; i++) //����������� ������ �� ������� ������� � �����
		newPtr[i] = _oldArray[i];

	delete[] _oldArray;

	return newPtr;
}

char* TxtReader(char* _path) {
	if (_path == nullptr) return nullptr; //����� ������� ���������
	ifstream fin(_path);

	if (!fin.is_open()) {
		cout << "File is not open (fileworker.cpp  TxtReader(char* _path) ) ";
		return nullptr; // �������� �� ���������� ����
	}

	char tmp; //������������� ���������� ������
	int arrayLength = _DEFAULT_BUFF_SIZE_; //������ ���������� �������
	char* arrayPtr = new char[arrayLength]; //��������� �� ��������� ������
	int i = 0; //���������� ��������� ��������
	arrayPtr[0] = '\0';

	while ((tmp = fin.get()) != EOF) { //������ �� ����� �����

		if (i < arrayLength - 1) {
			arrayPtr[i] = tmp;
			arrayPtr[i + 1] = '\0';
		}
		else {
			arrayPtr = StringManager(arrayPtr, arrayLength, arrayLength + _DEFAULT_BUFF_SIZE_); //���������� ������� �� _D_B_S_
			arrayLength += _DEFAULT_BUFF_SIZE_;
		}
	}

	arrayPtr = StringManager(arrayPtr, arrayLength, i + 2); //�������� ���������� ������������ 

	return arrayPtr;
}