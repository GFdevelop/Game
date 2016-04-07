#pragma once
#include "Stanza.hpp"
#include "coordinate.hpp"


class Giocatore
{
	private:
    coordinate* stanza;
    Giocatore* next;
    Giocatore* head;
    char nomgioc[20];
    int cibo;
    int turno;
	public:
		/* Default constructor */
		Giocatore();
		/* Default destructor */
		~Giocatore();
		Giocatore* add(coordinate *d);
		void print(Giocatore*p);
		Giocatore* getTesta();
};

