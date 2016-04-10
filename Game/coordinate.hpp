#pragma once
#include "Stanza.hpp"

class coordinate
{
protected:
	int a;
	int b;
    Stanza * room;
	coordinate * pros;
public:
	coordinate();
	~coordinate();
	coordinate * add(coordinate *& testa, coordinate * precedenti, int direzione);
	coordinate * search(coordinate *& testa, coordinate * precedenti, int direzione);
	bool findMap(coordinate * testa, int i, int j);
	void move(int &a, int &b, int direzione);
	void printList(coordinate * testa);
	void printNode(coordinate * precedente);
	void rem(coordinate *& c);
	int getCoordinatex();
	int getCoordinatey();
	Stanza* getRoom();
};
