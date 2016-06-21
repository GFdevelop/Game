#ifndef COORDINATE_HPP
#define COORDINATE_HPP
#include "Stanza.hpp"

class coordinate{
private:
	int a;
	int b;
    Stanza * room;
	coordinate * next;
public:
	coordinate();
	~coordinate();
	coordinate * add(coordinate *& testa, coordinate * precedenti, int direzione);
    // Postcondition: ritorna il puntatore alla stanza in cui si trova il giocatore
    
    coordinate * search(coordinate *& testa, coordinate * precedenti, int direzione);
    // Postcondition: ritorna il puntatore alla stanza in cui si trova il giocatore
    
	bool findMap(coordinate * testa, int x, int y);
    // Postcondition: cerca se esiste la stanza in base alle coordinate
    
	void move(int &a, int &b, int direzione);
    // Precondition: direzione uguale a 2 o 4 o 6 o 8
    // Postcondition: fa avanzare le coordinate nella direzione indicata
    
	void rem(coordinate *& c);
    // Postcondition: elimina tutti gli oggetti
    
    Stanza* getRoom();
    // Postcondition: ritorna la stanza
    
    int getCoordinatex();
    // Postcondition: ritorna la coordinata x
    
    int getCoordinatey();
    // Postcondition: ritorna la coordinata y
};

#endif
