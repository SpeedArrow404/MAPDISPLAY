#ifndef _CON_
#include "Controller.h"
#include "NodeController.h"
#include "Governer.h"
#endif

Controller::Controller() { //не проверено 
	 //Запись пути в массив и передача 
	this->path = new char[11] {"C:\\DOT.txt"};	//обратоно в контроллер
	//cout << this->path;
}

void Controller::GetParse() { //не проверено 
	this->document = NodeController(this->path);
}

void Controller::FillDots() { //не проверено
	

	int tmpId;
	int x, y, z;
	bool tmpBool; //временная переменная для типа
	int size = (*(this->document))["DOTS"].Size(); //количество точек

	Coords* tmpCoords =nullptr;
	Dot* tmpDot = nullptr;



	for (int i = 0; i < size; i++){ //занесение данных в точки (без соседей)

		tmpId = (*(this->document))["DOTS"][i]["id"].GetInt(); //чтение ID
		
		x = (*(this->document))["DOTS"][i]["coords"][0].GetInt(); //чтение координат
		y = (*(this->document))["DOTS"][i]["coords"][1].GetInt();
		z = (*(this->document))["DOTS"][i]["coords"][2].GetInt();
		
		tmpBool = (*(this->document))["DOTS"][i]["type"].GetBool(); //чтение типа



		tmpCoords = new Coords(x, y, z);
		tmpDot = new Dot(tmpCoords, tmpBool, tmpId);
		this->gov.AddDot(tmpDot);	//Добавление точки в вектор в говерноре
	}

	vector<int> neighbours; //временный вектор соседей
	neighbours.clear();

	for (int i = 0; i < size; i++) { //перебор точек в json
		for (int j = 0; j < (*(this->document))["DOTS"][i]["neighbours"].Size(); j++) //перебор соседей в json точке
			neighbours.push_back((*(this->document))["DOTS"][i]["neighbours"][j].GetInt());	//запись найденных соседей во временный вектор
		this->gov.AddNeighbours((*(this->document))["DOTS"][i]["id"].GetInt(), neighbours); //передача вектора для построения связей в говернор
		neighbours.clear();	//очистка вектора
	}
}

vector<Dot*> Controller::GetWay(int _from, int _to) { //Вызов поиска маршрута в говерноре
	return this->gov.SeekWay(_from, _to);
}

