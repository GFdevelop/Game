#pragma once
#include "Stanza.hpp"

class coordinate
{
protected:
	int a;
	int b;
	Stanza * room;
	coordinate * pros;
private:
	coordinate * testa;
public:
	coordinate();
	~coordinate();
	coordinate* getTesta();
	coordinate* add(coordinate * vecchie, int direzione);
	coordinate* search(coordinate * vecchie, int direzione);
};