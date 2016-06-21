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
    // Postcondition: Salva gli estremi se maggiori/minori
    
	void print(coordinate * testa, Giocatore * head);
    // Postcondition: Stampa le parentesi e gli spazi
    
	void forName(Giocatore * head, int x, int y, int l);
    // Postcondition: Stampa i nomi dei giocatori ed eventuali spazi
};

#endif
