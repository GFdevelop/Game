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
	Giocatore();
    /* Default constructor */
    
	~Giocatore();
    /* Default destructor */
    
	Giocatore * AddGioc(Giocatore* link, coordinate *d);
    // Precondition: d deve essere la cooordinata 0,0
    // Postcondition: ritorna la testa
    
    int getCibo();
    // Postcondition: ritorna il cibo del giocatore
    
    void setCibo(int cib);
    // Precondition: cib deve essere >0
    // Postcondition: assegna il cibo al gioc
    
	coordinate* getStanza();
    // Postcondition: ritorna la coordinata della stanza puntata
    
	void setStanza(coordinate *d);
    // Precondition: d non nullo
    // Postcondition: ritorna la testa
    
	
    void  getNomGioc(char a[]);
    // Postcondition: copia in a il nome del giocatore
    
	int cercaNumGioc(Giocatore* head, int x);
    // Precondition: testa non nulla
    // Postcondition: ritorna il numero massimo dei giocatori presenti in una stanza di una determinata colonna x
    
    Giocatore* getNext();
    // Postcondition: ritorna il prossimo giocatore
    
    void setNext(Giocatore* g);
    // Precondition: g non nullo
    // Postcondition: sovrascrive il vecchio next con g
};

#endif
