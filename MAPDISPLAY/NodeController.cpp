#include "NodeController.h"

Document* NodeController(char* _path) {
	
	int size;

	ifstream fin(_path, ios::in);
	if (fin.is_open() == false) {
		fin.close();
		return nullptr;
	}
	fin.seekg(0, ios::end);
	size = fin.tellg();
	fin.seekg(0, 0);
	fin.close();


	FILE* fp = fopen(_path,"rb"); 
	char* readBuffer = new char [size+1];
	readBuffer[size] = '\0';
	FileReadStream is(fp, readBuffer, size);

	Document* d = new Document();
	d->ParseStream(is);

	fclose(fp);
	return d;
}