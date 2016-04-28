#ifndef COORDINATE_HPP
#define COORDINATE_HPP
#include "Stanza.hpp"

class coordinate{
protected:
	int a;
	int b;
    Stanza * room;
	coordinate * next;
public:
	coordinate();
	~coordinate();
	coordinate * add(coordinate *& testa, coordinate * precedenti, int direzione);
	coordinate * search(coordinate *& testa, coordinate * precedenti, int direzione);
	bool findMap(coordinate * testa, int x, int y);
	void move(int &a, int &b, int direzione);
	//void printList(coordinate * testa);
	//void printNode(coordinate * precedente);
	void rem(coordinate *& c);
	int getCoordinatex();
	int getCoordinatey();
	Stanza* getRoom();
};

#endif
