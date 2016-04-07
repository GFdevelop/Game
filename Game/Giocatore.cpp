#include "Giocatore.hpp"
#include <iostream>
#include "string.h"

using namespace std;

Giocatore::Giocatore()
{
	head = NULL;
}

Giocatore::~Giocatore()
{
	while (head != NULL) {
			Giocatore * n = head->next;
			delete head;
			head = n;
	}
}

void Giocatore::print(Giocatore*p)
{
	while (p != NULL) {
		cout << p->nomgioc << "\n";
		p = p->next;
	}
}


Giocatore* Giocatore::add(coordinate *d){
	
	if (head == NULL)
	{
		head = new Giocatore;
		cout << "\nInserisci il nome del giocatore ";
		cin >> head->nomgioc;
		head->stanza = d;
		head->next = NULL;
	}
	else{
		Giocatore * p = new Giocatore;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Giocatore;
		p = p->next;
		cout << "\nInserisci il nome del giocatore ";
		cin >> p->nomgioc;
		p->stanza = d;
		p->next = NULL;
	}
	return(head);
}



Giocatore* Giocatore::getTesta()
{
	return(head);
}

Giocatore* Giocatore::getNext()
{
	Giocatore *p = new Giocatore;
	p = p->next;
	return(p);
}


coordinate* Giocatore::getStanza()
{
	return(stanza);
}


void Giocatore::setStanza(Giocatore *p, coordinate *d)
{
	p->stanza = d;
}

void Giocatore::getNomGioc(char n[])
{
	strcpy_s(n, 20, head->nomgioc);
}

/*
void Giocatore::ScorrimentoGiocatori(Giocatore* p)
{
	int turno = 0;
	int mossa;
	turno = 0;//inizia turno
	cout << "\n Gioca il " << p->nomgioc;
	do {
		cout << "\n Dove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
		cin >> mossa;
	} while (mossa != 8 || mossa != 6 || mossa != 2 || mossa != 4);
	if (numero_gioca <numgioc) {
	//p->link = gioc;
	//p->link = nuovaStanza(i, gioc, prova);
	}
	else {
	//p->link = nuovaStanza(i, p->link, prova);
	}
	head = add(p->stanza,mossa,stanza);

	//numero_gioca = numero_gioca + 1;
	p = p->next;//tocca al prossimo giocatore
	if (p == NULL)	p = head;//ricomincia il giro
	turno = 1;//finisce turno
}*/





/*
Node* Giocatore::searc(int x, int y)
{
	Node * n = head;
	bool found = 0;
	while ((n != NULL) && (!found)) {
		if ((n->a == x) && (n->b == y)) {
			found = 1;
			cout << n->a << "," << n->b << endl;
		}
		n = n->next;
	}
	if (found == 0) {
		Node* testa;
		testa.add(x, y);
	}
}*/
