#ifndef GIOCATORE_HPP
#define GIOCATORE_HPP
#include "Stanza.hpp"
#include "coordinate.hpp"


class Giocatore{
private:
	coordinate* coordinata;
	Giocatore* next;
	char nomgioc[20];
	int cibo;
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
	void  getNomGioc(char a[]);
	int cercaNumGioc(Giocatore* head, int x);
    Giocatore* getNext();
    void eliminaGiocatore(Giocatore*& head);
};

#endif
