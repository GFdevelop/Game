#include <iostream>
#include "Stanza.hpp"
#include "Giocatore.hpp"
#include "coordinate.hpp"
#include "mappa.hpp"
using namespace std;

void rimuovi(Giocatore *headGiocatore);

int main(){
	Giocatore *head;
	coordinate *d = NULL;
	coordinate *c = new coordinate;
	Giocatore *tmp;
	Giocatore *tmp2;
	mappa * m = new mappa;
	
	int valcibo;
	int turno = 1;
	int mossa;
	int ciboStanza;
	int giro=1;
	int numgioc=0, i;
	int tmpGioc;

	head = NULL;
	//input numero giocatori
    do{
		cout << "\nInserisci il numero di giocatori (Min 2-Giocatori) \n";
		cin >> numgioc;
	} while (numgioc < 2);
	tmpGioc = numgioc;
	//inserisco i giocatori in una lista
	for (i = 1; i <= numgioc; i++){
		head = head->AddGioc(head, d);
	}
	//inizializzo la stanza
	d = c->add(c, NULL, 0);
	m->add(d);	//per stampa mappa
    tmp = head;
    while (tmp->getNext()!=NULL) {
        tmp->setStanza(d);
        tmp=tmp->getNext();
    }
    tmp->setStanza(d);//questo setta il l'ultimo elemento
	tmp = head;
	//inizia il gioco
	m->print(c, head);
	while ((head!=NULL) && ((head->getNext())!=NULL)) {
		cout << "\nTurno " << turno;
		//tmp = tmp->getNext();
		while (giro != (numgioc + 1)){// non metto ((head->getNext())!=NULL) perchè c'è se muoiono tutti nello stesso turno vince l'ultimo che gioca
			tmp2 = tmp->getNext();
			if (((head->getNext())!=NULL) && (turno == 1)) {
				tmp->getStanza()->getRoom()->azzeraCibo();
			}
			cout << "\nTocca a giocatore " << tmp->getNomGioc() << "\nCibo a disposizione: " << tmp->getCibo() << "\nCoordinate giocatore: x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
			do {
				cout << "\nDove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
				cin >> mossa;
			} while ((mossa != 8) && (mossa != 6) && (mossa != 2) && (mossa != 4));
			valcibo = (tmp->getCibo()) - 1;
			tmp->setCibo(valcibo);
			d = c->search(c, tmp->getStanza(), mossa);
			m->add(d);	//per stampa mappa
			tmp->setStanza(d);
			ciboStanza = tmp->getStanza()->getRoom()->getCibo();
			if (ciboStanza != 0) {
				cout << "Hai trovato " << ciboStanza << " unita' di cibo!\n";
                valcibo = (tmp->getCibo()) + ciboStanza;
                tmp->setCibo(valcibo);
			}
			tmp->getStanza()->getRoom()->azzeraCibo();
            //se il giocatore ha 0 di cibo allora viene eliminato
            if ((tmp->getCibo())==0) {
                tmp->eliminaGiocatore(head);
				tmpGioc = tmpGioc - 1;
            }
			tmp = tmp2;
			giro++;
			//stampa mappa
			m->print(c, head);
		}
		//ricomincia il giro
		giro = 1;
		turno = turno + 1;
        tmp = head;
		numgioc = tmpGioc;

	}
    
    if (head==NULL) {
        cout<<"\nSono morti tutti i giocatori";
    } else {
        cout << "\nHa vinto giocatore " << tmp->getNomGioc() << "\nCon con ancora " << tmp->getCibo() << " di cibo \na coordinate x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
        
    }
	//distruggo
    cout<<"\nPulisco memoria\n";
	rimuovi(head);
	return 0;
}

void rimuovi(Giocatore *headGiocatore)
{
	if (headGiocatore != NULL)
		rimuovi(headGiocatore->getNext());
	delete headGiocatore;
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
}ù*/
