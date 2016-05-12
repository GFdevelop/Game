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

Giocatore::~Giocatore(){
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
        cout << "Eliminato giocatore "<<g->nomgioc<<endl;
        delete g;
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
            cout << "Eliminato giocatore "<<g->next->nomgioc<<endl;
			delete g->next;
			g->next=q;
		}
	}
}

//trova il numero massimo dei giocatori presenti in una stanza di una determinata colonna x
int Giocatore::cercaNumGioc(Giocatore* head, int x) {
	int lunghezza, l = 0;
	int i, j, a, b; //i=x j=y a=x b=x

	Giocatore* g = head;
	Giocatore* n = NULL;
    
    //scorre la lista dei nodi da confrontare
	while (g != NULL){
        n=g;
		lunghezza = -1;//lunghezza compresa la virgola, per il primo giocatore non serve contare la virgola
        
		i = g->coordinata->getCoordinatex();
		if (i == x){
			j = g->coordinata->getCoordinatey();
            
            //confronto i nodi per cercare giocatori nella stessa stanza
			while (n != NULL){
				a = n->coordinata->getCoordinatex();
				b = n->coordinata->getCoordinatey();
				if ((a == i) && (b == j)){
					lunghezza = lunghezza + (strlen(n->nomgioc) + 1); //numero di caratteri da stampare più la virgola
				}
				n = n->next;
			}
		}
		if (l < lunghezza) l = lunghezza;
		g = g->next;
	}
	return (l);
}
