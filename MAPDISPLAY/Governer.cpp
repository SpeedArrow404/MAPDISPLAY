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
	int maxI; //maxI и minI отвечают за позицию в вескторе neighbour
	int minI=-1;
	int x1;	// х1 у1 - Координаты текущей точки
	int y1;
	int x2; // х2 у2 - Координаты конечной точки
	int y2;
	bool unvisitedNeighbours = true; //True - предполагаем, что непосещ соседи еще есть
	
	this->visited = true;

	vector <Dot*> ret;
	if( this->id == _B->id){	// Проверка в конечной ли мы точке
		ret.push_back(this);
		return ret;
	}
	
	x1 = this->neighbours[0]->coords->x;	//получение координат "первОГО СОСеда"
	y1 = this->neighbours[0]->coords->y;
	x2 = _B->coords->x;	//получение координат конечной точки
	y2 = _B->coords->y;

	min =SquareVectorLength(x1,y1,x2,y2); //расчет КВАДРАТА (т.к интересует большее или меньшее расст, а не его точное значение)
	max = min;											// расстояния от "ПЕРВОГО СОСЕДА" до цели
	
	while (unvisitedNeighbours) {
		unvisitedNeighbours = false;
		min = max;
		for (int i = 0; i < this->neighbours.size(); i++) { //перебор соседей (если сосед не почещен и расстояние меньше текущего минимума)
			if (this->neighbours[i]->visited == false) unvisitedNeighbours = true; //Проверка, остились ли еще не проверенные соседи
			
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
	if (_arg == nullptr) { //проверка на нулевой указатель
		return false; //меня не наебешь! Вы думаете я вас не переиграю? ))) Я вас уничтожу >:|
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


	if (dotA == nullptr || dotB == nullptr) return vector<Dot*>(); //если dotB(A) == nullptr возвращаем пустой массив, тк точка B(A) не была найдена
	
	for (int i = 0; i < this->dots.size(); i++) //TODO - Обнуление visited
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