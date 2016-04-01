#include "coordinate.hpp"
#include "Stanza.hpp"
#include <iostream>


coordinate :: coordinate(){
	a = 0;
	b = 0;
	room = NULL;
	pros = NULL;
	testa = NULL;
}

coordinate::~coordinate(){
	while (testa != NULL) {
			coordinate * n = testa->pros;
			delete testa;
			testa = n;
	}
}

coordinate* coordinate::getTesta()
{
	return(testa);
}

coordinate* coordinate :: add(coordinate * vecchie, int direzione){
	Stanza s;
	if (testa == NULL){
		room = s.getTesta();
	}
	else {
		coordinate * p = new coordinate;
		
		if (direzione == 8){
			p->a = vecchie->a;
			p->b = vecchie->b + 1;
		}
		else if (direzione == 6){
			p->a = vecchie->a + 1;
			p->b = vecchie->b;
		}
		else if (direzione == 4){
			p->a = vecchie->a - 1;
			p->b = vecchie->b;
		}
		else if (direzione == 2){
			p->a = vecchie->a;
			p->a = vecchie->a - 1;
		}
		
		p->pros = testa;
		p->room = s.Aggiungi_Stanza(vecchie->room, NULL, direzione);
		testa = p;
	}
	return (testa);
}

coordinate* coordinate :: search(coordinate * vecchie, int direzione){
	bool found = 0;
	coordinate * p = testa;
	while ((p != NULL) && (found == 0)){
		if (vecchie->room == p->room){
			found = 1;
		}
		else {
			p = p->pros;
		}
	}
	if (found == 0){
		p = add(vecchie, direzione);
	}
	return (p);
}