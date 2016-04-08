#pragma once
#include "Stanza.hpp"
#include "coordinate.hpp"


class Giocatore
{
private:
	coordinate* coordinata;
	Giocatore* next;
	char nomgioc[20];
	int cibo;
	int turno;
public:
	/* Default constructor */
	Giocatore();
	/* Default destructor */
	~Giocatore();

	Giocatore * AddGioc(Giocatore* link, coordinate *d);
	coordinate* getStanza();
	int getCibo();
	void setStanza(coordinate *d);
	void setCibo(int cib);
	char*  getNomGioc();
	Giocatore* nextGioc(Giocatore* g);
	//lo metto perchè nel main non mi fa accedere a next e coordinata
	void gioco(coordinate* headCoordinate, Stanza* headStanza, Giocatore* headGiocatore, int numgioc);
    Giocatore* getNext();
    void eliminaGiocatore(Giocatore*& head);
	//Giocatore* createHead(coordinate* headCoordinate);
	/*
	Node *getLink( ) const;
	void setLink(Node *next);
	*/
};

