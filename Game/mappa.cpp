#include "mappa.hpp"
#include "coordinate.hpp"
#include <iostream>
using namespace std;

mappa::mappa() {
	x = 0;
	y = 0;
	X = 0;
	Y = 0;
}

mappa::~mappa(){
	
}

void mappa :: add(coordinate * gioc){
	if (gioc->getCoordinatex() < x) x = gioc->getCoordinatex();
	else if (gioc->getCoordinatex() > X) X = gioc->getCoordinatex();
	if (gioc->getCoordinatey() < y) y = gioc->getCoordinatey();
	else if (gioc->getCoordinatey() > Y) Y = gioc->getCoordinatey();
}

void mappa :: print(coordinate * testa, Giocatore * head){
	int i = x;
	int j = Y;
	int inX, k;
	int l;
	cout << "Mappa:" << endl;
	while ((j >= y) && (j <= Y)){
		while ((i >= x) && (i <= X)){
			k = 0;
			l = 0;
			inX = head->cercaNumGioc(head, i, l);
			if (testa->findMap(testa, i, j) == 1){
				cout << "[";
				if (k < inX){
					forName(head, inX, i, j, l);
				}
				cout << "]";
			}
			else {
				cout << " ";
				if (inX > 0){
					while (k < l){
						cout << " ";
						k = k+1;
					}
				}
				cout << " ";
			}
			i = i+1;
		}
		cout << endl;
		i = x;
		j = j-1;
	}
}

void mappa::forName(Giocatore * head, int inX, int x, int y, int l){
	int i = 0;
	int lung = -1;
	int a, b;
	char nome[20] = "";
	Giocatore * n = head;
	while (n != NULL){
		a = n->getStanza()->getCoordinatex();
		b = n->getStanza()->getCoordinatey();
		if ((a == x) && (b == y)) {
            n->getNomGioc(nome);
			lung = lung + (strlen(nome) + 1);
			if (i == 0) cout << nome;
			else cout << "," << nome;
			i = i+1;
		}
		n = n->getNext();
	}
	if (lung == -1) lung = 0;
	while (lung < l){
		cout << " ";
		lung = lung+1;
	}
}
