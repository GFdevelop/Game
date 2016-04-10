#pragma once
#include "coordinate.hpp"
#include "Giocatore.hpp"
#include "string.h"

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
	void print(coordinate * testa, Giocatore * head);
	void forName(Giocatore * head, int inX, int x, int y, int l);
};
