#ifndef _CON_
#include "Controller.h"
#include "NodeController.h"
#include "Governer.h"
#endif

Controller::Controller() { //�� ��������� 
	 //������ ���� � ������ � �������� 
	this->path = new char[11] {"C:\\DOT.txt"};	//�������� � ����������
	//cout << this->path;
}

void Controller::GetParse() { //�� ��������� 
	this->document = NodeController(this->path);
}

void Controller::FillDots() { //�� ���������
	

	int tmpId;
	int x, y, z;
	bool tmpBool; //��������� ���������� ��� ����
	int size = (*(this->document))["DOTS"].Size(); //���������� �����

	Coords* tmpCoords =nullptr;
	Dot* tmpDot = nullptr;



	for (int i = 0; i < size; i++){ //��������� ������ � ����� (��� �������)

		tmpId = (*(this->document))["DOTS"][i]["id"].GetInt(); //������ ID
		
		x = (*(this->document))["DOTS"][i]["coords"][0].GetInt(); //������ ���������
		y = (*(this->document))["DOTS"][i]["coords"][1].GetInt();
		z = (*(this->document))["DOTS"][i]["coords"][2].GetInt();
		
		tmpBool = (*(this->document))["DOTS"][i]["type"].GetBool(); //������ ����



		tmpCoords = new Coords(x, y, z);
		tmpDot = new Dot(tmpCoords, tmpBool, tmpId);
		this->gov.AddDot(tmpDot);	//���������� ����� � ������ � ���������
	}

	vector<int> neighbours; //��������� ������ �������
	neighbours.clear();

	for (int i = 0; i < size; i++) { //������� ����� � json
		for (int j = 0; j < (*(this->document))["DOTS"][i]["neighbours"].Size(); j++) //������� ������� � json �����
			neighbours.push_back((*(this->document))["DOTS"][i]["neighbours"][j].GetInt());	//������ ��������� ������� �� ��������� ������
		this->gov.AddNeighbours((*(this->document))["DOTS"][i]["id"].GetInt(), neighbours); //�������� ������� ��� ���������� ������ � ��������
		neighbours.clear();	//������� �������
	}
}

vector<Dot*> Controller::GetWay(int _from, int _to) { //����� ������ �������� � ���������
	return this->gov.SeekWay(_from, _to);
}

