#pragma once
#ifndef _GOVERNER_H_
#define _GOVERNER_H_
#include "Include.h"
#include "CommonFunctions.h"

class Coords{
	public: 
		int x;
		int y;
		int z;
		
	Coords(int _x,int _y,int _z);
	
	void set(int _x,int _y,int _z);
};

class Dot{
	public:
		int id;
		Coords* coords;
		vector<Dot*> neighbours;
		bool type;
		bool visited;
		
	Dot(Coords* _coords,bool _type,int _id);
	
	bool AddNeighbour(Dot* _newNeighbour);
	Dot* SeekById(int _id);
	vector<Dot*> RecursiveSeekWay(Dot* _B);	
};

class Governer{
	public:
		vector<Dot*> dots;
		
		bool AddDot(Dot* _arg);
		vector<Dot*> SeekWay(int _from,int _to);
		bool AddNeighbours(int _id, vector<int> Neighbours);
};

float VectorLength(int _x1,int _y1,int _x2, int _y2);


#endif