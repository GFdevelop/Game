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

Giocatore::~Giocatore()
{
	cout << "Eliminato giocatore "<<nomgioc<<endl;
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
		g=head;
    }
	else{
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
		}
	}
}


int Giocatore::cercaNumGioc(Giocatore* head, int x)
{
	int cont=0;

	Giocatore* g = head;
	while (g != NULL)
	{
		if (g->getStanza()->getCoordinatex() == x)
		{
			cont++;
		}
		g = g->next;
	}
	cout << "\n\n \tsss" << cont;

	return (cont);
}