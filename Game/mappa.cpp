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
    //aggiorna gli estremi della mappa
	if (gioc->getCoordinatex() < x) x = gioc->getCoordinatex();
	else if (gioc->getCoordinatex() > X) X = gioc->getCoordinatex();
    
	if (gioc->getCoordinatey() < y) y = gioc->getCoordinatey();
	else if (gioc->getCoordinatey() > Y) Y = gioc->getCoordinatey();
}

void mappa :: print(coordinate * testa, Giocatore * head){
	int i = x;
	int j = Y;
    int contatore;
	int l; //numero massimo dei caratteri da stampare in una determinata colonna x
	cout << "Mappa:" << endl;
    
    //scorro da sinistra verso destra per ogni coordinata x
    //scorre dall'alto verso il basso
    //fino a quando sono negli estremi
	while ((j >= y) && (j <= Y)){
		while ((i >= x) && (i <= X)){
			contatore = 0;
			l = head->cercaNumGioc(head, i);//controllo se ci sono giocatori nella colonna
            
			if (testa->findMap(testa, i, j) == 1){ //cerco se è stata aperta la stanza
				cout << "[";
				if (l > 0){
					forName(head, i, j, l);//stampo i nomi ed eventualmente gli spazi
				}
				cout << "]";
			} else {
				cout << " ";
				if (l > 0){
					while (contatore < l){//stampo solo spazi se non ci sono giocatori in questa stanza
						cout << " ";
						contatore = contatore+1;
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

void mappa::forName(Giocatore * head, int x, int y, int l){
	int i = 0; //contatore
	int lung = -1;
	int a, b;
	char nome[20] = "";
	Giocatore * n = head;
    
    //stampa i nomi dei giocatori
	while (n != NULL){
		a = n->getStanza()->getCoordinatex();
		b = n->getStanza()->getCoordinatey();
		if ((a == x) && (b == y)) {             //stampo solo i giocatori in questa stanza
            n->getNomGioc(nome);
			lung = lung + (strlen(nome) + 1);//conteggio per conoscere il numero di spazi da stampare alla fine
            
			if (i == 0) cout << nome;
			else cout << "," << nome;
            
			i = i+1;
		}
		n = n->getNext();
	}
	if (lung == -1) lung = 0; //caso in qui non ci sono giocatori nella colonna tolgo il conteggio della virgola 
    
    //stampo un numero di spazi uguale alla differenza tra il numero di caratteri massimo e i caratteri gia stampati (nomi giocatori+virgola)
	while (lung < l){
		cout << " ";
		lung = lung+1;
	}
}
