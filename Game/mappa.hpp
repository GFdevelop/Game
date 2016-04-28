#ifndef MAPPA_HPP
#define MAPPA_HPP

#include "coordinate.hpp"
#include "Giocatore.hpp"
#include "string.h"

class mappa{
private:
	int x; //coordinata stanza più a SX
	int y; //coordinata stanza più bassa
	int X; //coordinata stanza più a DX
	int Y; //coordinata stanza più alta
public:
	mappa();
	~mappa();
	void add(coordinate * gioc);
	void print(coordinate * testa, Giocatore * head);
	void forName(Giocatore * head, int x, int y, int l);
};

#endif
