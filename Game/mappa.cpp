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

void mappa :: print(coordinate * testa){
	int i = x;
	int j = Y;
	cout << "Mappa:" << endl;
	while ((j >= y) && (j <= Y)){
		while ((i >= x) && (i <= X)){
			if (testa->findMap(testa, i, j) == 1){
				cout << "[]";
			}
			else {
				cout << "  ";
			}
			i = i+1;
		}
		cout << endl;
		i = x;
		j = j-1;
	}
}
