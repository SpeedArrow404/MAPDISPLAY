#ifndef _GOV_
#include "Governer.h"
#endif

Coords::Coords(int _x,int _y,int _z){
	this->x=_x;
	this->y=_y;
	this->z=_z;
}

void Coords::set(int _x,int _y,int _z){
	this->x=_x;
	this->y=_y;
	this->z=_z;
}

 Dot::Dot(Coords* _coords, bool _type,int _id){
	this->coords=_coords;
	this->type=_type;
	this->id=_id;
}

bool Dot::AddNeighbour(Dot* _newNeighbour){
	this->neighbours.push_back(_newNeighbour);
	return true;
}

Dot* Dot::SeekById(int _id){
	for(int i=0;i<this->neighbours.size();i++){
		if (this->neighbours[i]->id == _id){
			return this->neighbours[i];
		}
	}
	return nullptr;
}

vector<Dot*> Dot::RecursiveSeekWay(Dot* _B){
	float max;
	float min;
	int maxI; //maxI � minI �������� �� ������� � �������� neighbour
	int minI=-1;
	int x1;	// �1 �1 - ���������� ������� �����
	int y1;
	int x2; // �2 �2 - ���������� �������� �����
	int y2;
	bool unvisitedNeighbours = true; //True - ������������, ��� ������� ������ ��� ����
	
	this->visited = true;

	vector <Dot*> ret;
	if( this->id == _B->id){	// �������� � �������� �� �� �����
		ret.push_back(this);
		return ret;
	}
	
	x1 = this->neighbours[0]->coords->x;	//��������� ��������� "������� ������"
	y1 = this->neighbours[0]->coords->y;
	x2 = _B->coords->x;	//��������� ��������� �������� �����
	y2 = _B->coords->y;

	min =SquareVectorLength(x1,y1,x2,y2); //������ �������� (�.� ���������� ������� ��� ������� �����, � �� ��� ������ ��������)
	max = min;											// ���������� �� "������� ������" �� ����
	
	while (unvisitedNeighbours) {
		unvisitedNeighbours = false;
		min = max;
		for (int i = 0; i < this->neighbours.size(); i++) { //������� ������� (���� ����� �� ������� � ���������� ������ �������� ��������)
			if (this->neighbours[i]->visited == false) unvisitedNeighbours = true; //��������, �������� �� ��� �� ����������� ������
			
			x1 = this->neighbours[i]->coords->x;
			y1 = this->neighbours[i]->coords->y;
			if ((this->neighbours[i]->visited == false) && (SquareVectorLength(x1, y1, x2, y2) <= min)) {
				minI = i;
				min = i;
				this->neighbours[i]->visited = true;
			}
		}

		if (unvisitedNeighbours == false) break;
		if (minI == -1) {
			minI = minI;
		}
		if (minI != -1) {

			ret = this->neighbours[minI]->RecursiveSeekWay(_B);
			if (ret.size() > 0) {
				ret.push_back(this);
				return ret;
			}
		}
	}
	return vector<Dot*>();
}

bool Governer::AddDot(Dot* _arg){
	if (_arg == nullptr) { //�������� �� ������� ���������
		return false; //���� �� �������! �� ������� � ��� �� ���������? ))) � ��� �������� >:|
	}
	this->dots.push_back(_arg);
	return true;
}

vector<Dot*> Governer::SeekWay(int _from,int _to){
	Dot* dotA = nullptr;
	Dot* dotB = nullptr; 
	for (int i = 0; i < this->dots.size(); i++) {
		
		if (this->dots[i]->id == _from) {
			dotA = this->dots[i];
		}

		if (this->dots[i]->id == _to) {
			dotB = this->dots[i];
		}
		if (dotA != nullptr && dotB != nullptr) break;
	}


	if (dotA == nullptr || dotB == nullptr) return vector<Dot*>(); //���� dotB(A) == nullptr ���������� ������ ������, �� ����� B(A) �� ���� �������
	
	for (int i = 0; i < this->dots.size(); i++) //TODO - ��������� visited
		this->dots[i]->visited = false;

	return dotA->RecursiveSeekWay(dotB);
}

bool Governer::AddNeighbours(int _id, vector<int> Neighbours) {
	int dot=0;
	for (int i = 0; i < this->dots.size();i++) {
		if (this->dots[i]->id == _id) {
			dot = i;
			break;
		}
	}

	for (int i = 0; i < Neighbours.size(); i++) {
		int j = 0;
		for (j = 0; j < this->dots.size() && this->dots[j]->id != Neighbours[i]; j++);
		if(j!=dots.size())
		dots[dot]->AddNeighbour(this->dots[j]);
	}

	return true;
}