#pragma once
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Include.h"
#include "Governer.h"
//#include "FileWorker.h"

class Controller{
	public:
		char* path;
		Controller(); //присвоение пути через конструктор
		Document* document;
		Governer gov;

		void GetParse();

		void FillDots();

		vector<Dot*> GetWay(int _from, int _to);
		//FileWorker fw;
		//Visualiser vsr;


};


#endif