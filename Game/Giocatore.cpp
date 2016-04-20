#include "Giocatore.hpp"
#include <iostream>
#include "string.h"

using namespace std;

Giocatore::Giocatore()
{
	next = NULL;
	coordinata = NULL;
	cibo = 5;
    nomgioc[0]='\0';
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

int Giocatore::getCibo() {
	return(cibo);
}

void Giocatore::setCibo(int cib) {
	cibo = cib;
}

coordinate* Giocatore::getStanza() {
	return(coordinata);
}

Giocatore* Giocatore::getNext() {
    return (next);
}

void Giocatore::setStanza(coordinate *d) {
    coordinata=d;
}

void Giocatore::getNomGioc(char a[]) {
    strcpy(a,nomgioc);
}

void Giocatore::eliminaGiocatore(Giocatore*& head) {
    Giocatore* g=head;
    
    if (g->cibo==0) {

        head=head->next;
        delete g;;
    }
	else{
        bool found=0;
		while ((g != NULL) && ((g->next)!=NULL) && (found == 0)) {
			if ((g->next->cibo)==0) {
				found = 1;
			}
			else {
				g = g->next;
			}
		}
		if (found == 1) {
			Giocatore* q=g->next->next;
			delete g->next;
			g->next=q;
		}
	}
}

int Giocatore::cercaNumGioc(Giocatore* head, int x, int &l) {
	int lung;
	int c=0;
	int cont;
	int i, j, a, b;

	Giocatore* g = head;
	Giocatore* n = head;
	while (g != NULL)
	{
		lung = -1;
		i = g->coordinata->getCoordinatex();
		if (i == x)
		{
			cont = 0;
			j = g->coordinata->getCoordinatey();
			while (n != NULL){
				a = n->coordinata->getCoordinatex();
				b = n->coordinata->getCoordinatey();
				if ((a == i) && (b == j)){
					lung = lung + (strlen(n->nomgioc) + 1);
					cont++;
				}
				n = n->next;
			}
		}
		if (l < lung) l = lung;
		if (c < cont) c = cont;
		g = g->next;
		n = head;
	}
	return (c);
}
