#include <iostream>
#include "Stanza.hpp"
#include "Giocatore.hpp"
#include "coordinate.hpp"
using namespace std;

int main()
{
	Giocatore g;
	Stanza s;
	coordinate c;
	coordinate * d;
	int numgioc;
	int i;

	do{
		cout << "\nInserisci il numero di giocatori (Min 2-Giocatori) \n";
		cin >> numgioc;
	}while(numgioc < 2);
	
	d = c.add(NULL, 0, s);
	//cout << d << endl;
	for(i=1; i<=numgioc; i++)
	{
		g.add();
		//c.print();
	}
	cout << "\nGioco Terminato \n";
	g.print(g.getTesta());
	return 0;
}



//Inserisco i giocatori nel gioco
/*
ptr_gioc tail_insert(ptr_gioc head, int i){
	ptr_gioc p ;
	char app[10];
	char app2[10];
	strcpy(app,"Player");
	if (head == NULL) {
				head = new Nodo;
				strcpy(head->nomgioc,"Player1");
				head->next = NULL ;
	} else { 	p = head ;
				while (p->next != NULL)
						p = p->next ;
				p->next = new Nodo ;
				p = p->next ;
				itoa (i,app2,10);
				strcat(app,app2);
				strcpy(p->nomgioc,app);
				p->next = NULL ;
	}
	return(head) ;
}*/
