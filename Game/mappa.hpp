#pragma once
#include "coordinate.hpp"

class mappa{
private:
	int x;
	int y;
	int X;
	int Y;
public:
	mappa();
	~mappa();
	void add(coordinate * gioc);
	void print(coordinate * testa);
};
