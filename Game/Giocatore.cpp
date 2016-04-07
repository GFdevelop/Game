#include "Giocatore.hpp"
#include <iostream>
#include "string.h"

using namespace std;

Giocatore::Giocatore()
{
	next = NULL;
	coordinata = NULL;
	cibo = 5;
}
/*
Giocatore::Giocatore(Giocatore *next) {
	return(link->next);
}
*/
Giocatore::~Giocatore()
{
	cout << " \n\n DIo cane";
}


Giocatore* Giocatore::AddGioc(Giocatore* link, coordinate *d) {
	if (link == NULL) {
		link = new Giocatore;
		cout << "\nInserisci il nome del giocatore ";
		cin >> link->nomgioc;
		link->coordinata = d;
		link->next = NULL;
	}
	else {
		Giocatore * p;
		p = link;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new Giocatore;
		p = p->next;
		cout << "\nInserisci il nome del giocatore ";
		cin >> p->nomgioc;
		p->coordinata = d;
		p->next = NULL;
	}
	return(link);
}


Giocatore* Giocatore::getTesta()
{
	return(next);
}

int Giocatore::getCibo()
{
	return(cibo);
}

void Giocatore::setCibo(int cib)
{
	cibo = cib;
}

coordinate* Giocatore::getStanza() {
	return(coordinata);
}

Giocatore* Giocatore::getNext(){
    return (next);
}

void Giocatore::setStanza(coordinate *d) {
    coordinata=d;
}

char* Giocatore::getNomGioc() {
	return this->nomgioc;
}

void Giocatore::eliminaGiocatore(Giocatore*& head){
    Giocatore* g=head;
    Giocatore* q;
    bool found=0;
    if (g->cibo==0) {
        q=head;
        head=head->next;
        delete q;
    }
    while ((g != NULL) && ((g->next)!=NULL) && (found == 0)) {
        if ((g->next->cibo)==0) {
            found = 1;
        }
        else {
            g = g->next;
        }
    }
    if (found == 1) {
        q=g->next->next;
        delete g->next;
        g->next=q;
        delete q;
    }
}
/*
Giocatore* Giocatore::nextGioc(Giocatore* g) {
	g = g->next;
	return (g);
}
*/
/*
void Giocatore::gioco(coordinate* headCoordinate, Stanza* headStanza, Giocatore* headGiocatore, int numgioc) {
	int direzione = 0;
	int turno = 1;
	int giro = 1;
	int ciboStanza;
	Giocatore* g;
	g = headGiocatore;
	while ((headGiocatore != NULL) && (g->cibo == 0)){
		cout << "\nTurno " << turno;
		g = g->next;//salta la testa
		while ((giro != (numgioc + 1))) {
			if (turno == 1) {
				g->coordinata->getStanza()->azzeraRandom_eCibo();
			}
			cout << "\nTocca a giocatore " << g->getNomGioc() << "\nCibo a disposizione: " << g->cibo << "\nCoordinate giocatore: x:" << g->coordinata->getCoordinatex() << " y:" << g->coordinata->getCoordinatey();
			do {
				cout << "\n Dove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
				cin >> direzione;
			} while ((direzione != 8) && (direzione != 6) && (direzione != 2) && (direzione != 4));
			g->cibo = (g->cibo) - 1;
			g->coordinata = g->coordinata->SearchAndAdd(g->coordinata, headCoordinate, direzione);
			ciboStanza = g->coordinata->getStanza()->getCibo();
			if (ciboStanza != 0) {
				cout << "Hai trovato " << ciboStanza << " unità di cibo!\n";
			}
			g->cibo = (g->cibo) + ciboStanza;
			
			g->coordinata->getStanza()->azzeraRandom_eCibo();
			g = g->nextGioc(g);
			giro = giro + 1;
		}
		giro = 1;
		turno = turno + 1;
		g = headGiocatore;
	}
}*/


