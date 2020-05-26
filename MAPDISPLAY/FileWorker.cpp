#include "FileWorker.h"
char* StringManager(char* _oldArray, int _oldLength, int _newLenght) {
	
	if (_oldArray == nullptr) return new char[_newLenght]; //Отлов пустого указателя
	
	char* newPtr = new char[_newLenght];
	int lenght; //Длинна копируемого массива

	if (_oldLength > _newLenght) lenght = _newLenght; //Избегаем ошибки heap fault
	else lenght = _oldLength;

	for (int i = 0; i < lenght; i++) //Копирование данных из старого массива в новый
		newPtr[i] = _oldArray[i];

	delete[] _oldArray;

	return newPtr;
}

char* TxtReader(char* _path) {
	if (_path == nullptr) return nullptr; //Отлов пустого указателя
	ifstream fin(_path);

	if (!fin.is_open()) {
		cout << "File is not open (fileworker.cpp  TxtReader(char* _path) ) ";
		return nullptr; // Проверка на правильный путь
	}

	char tmp; //промежуточная переменная чтения
	int arrayLength = _DEFAULT_BUFF_SIZE_; //длинна считанного массива
	char* arrayPtr = new char[arrayLength]; //Указатель на считанный массив
	int i = 0; //Количество считанных символов
	arrayPtr[0] = '\0';

	while ((tmp = fin.get()) != EOF) { //Чтение до конца файла

		if (i < arrayLength - 1) {
			arrayPtr[i] = tmp;
			arrayPtr[i + 1] = '\0';
		}
		else {
			arrayPtr = StringManager(arrayPtr, arrayLength, arrayLength + _DEFAULT_BUFF_SIZE_); //Расширение массива на _D_B_S_
			arrayLength += _DEFAULT_BUFF_SIZE_;
		}
	}

	arrayPtr = StringManager(arrayPtr, arrayLength, i + 2); //Удаление незанятого пространства 

	return arrayPtr;
}