#include "Giocatore.hpp"
#include <iostream>

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


Giocatore* Giocatore::add(){
	
	if (head == NULL)
	{
		head = new Giocatore;
		cout << "\nInserisci il nome del giocatore ";
		cin >> head->nomgioc;
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
		p->next = NULL;
	}
	return(head);
}



Giocatore* Giocatore::getTesta()
{
	return(head);
}

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
