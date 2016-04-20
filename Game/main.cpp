#include <iostream>
#include "Stanza.hpp"
#include "Giocatore.hpp"
#include "coordinate.hpp"
#include "mappa.hpp"
#include <cstdlib>

#ifdef _WIN32
    #define CLEARSCR "cls"
#else
    #define CLEARSCR "clear"
#endif

using namespace std;

void rimuovi(Giocatore *headGiocatore);

int main(){
	Giocatore *head;
	coordinate *d = NULL;
	coordinate *headCoordinate = new coordinate;
	Giocatore *tmp;
	Giocatore *tmp2;
	mappa * m = new mappa;
	
	int turno = 1;
	int mossa = 0;
	int ciboStanza;
	int giro=1;
	int numgioc=0, i;
	int tmpGioc;
    char nomgioc[20]="";
	head = NULL;
    
	//input numero giocatori
    do{
		cout << "Inserisci il numero di giocatori (Min 2-Giocatori) :";
		cin >> numgioc;
	} while (numgioc < 2);
	tmpGioc = numgioc;
	//inserisco i giocatori in una lista
	for (i = 1; i <= numgioc; i++){
		head = head->AddGioc(head, d);
	}
	//inizializzo la stanza
	d = headCoordinate->add(headCoordinate, NULL, 0);
	m->add(d);	//per stampa mappa
    tmp = head;
    
	//inizializza tutti i giocatori alla stanza iniziale con coordinate 0,0
	while (tmp!=NULL) {
        tmp->setStanza(d);
        tmp=tmp->getNext();
    }
    
    system(CLEARSCR);
	tmp = head;
    
	//inizia il gioco
	m->print(headCoordinate, head);
    
	while ((head!=NULL) && ((head->getNext())!=NULL)) {
		cout << "\nTurno " << turno;
		while (giro != (numgioc + 1)) {
			tmp2 = tmp->getNext();
            
            tmp->getNomGioc(nomgioc);
			cout << "\nTocca a giocatore " << nomgioc << "\nCibo a disposizione: " << tmp->getCibo() << "\nCoordinate giocatore: x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
            do {
				cout << "\nDove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
				cin >> mossa;
			} while ((mossa != 8) && (mossa != 6) && (mossa != 2) && (mossa != 4));
            
			tmp->setCibo((tmp->getCibo()) - 1);//toglie 1 di cibo al giocatore
            
			d = headCoordinate->search(headCoordinate, tmp->getStanza(), mossa);
            
			m->add(d);	//per stampa mappa
            
			tmp->setStanza(d);
			ciboStanza = tmp->getStanza()->getRoom()->getCibo();
			if (ciboStanza != 0) {
				cout << "Hai trovato " << ciboStanza << " unita' di cibo!\n";
                tmp->setCibo((tmp->getCibo()) + ciboStanza);
			}
			tmp->getStanza()->getRoom()->azzeraCibo();
            
            if ((tmp->getCibo())==0) {//se il giocatore ha 0 di cibo allora viene eliminato
                tmp->eliminaGiocatore(head);
				tmpGioc = tmpGioc - 1;
            }
            
			tmp = tmp2;
			giro++;
			system(CLEARSCR);
            
			//stampa mappa
			m->print(headCoordinate, head);
		}
        
		//ricomincia il giro
		giro = 1;
		turno = turno + 1;
        tmp = head;
		numgioc = tmpGioc;
	}
    
	//fine gioco
    if (head==NULL) {
        cout<<"\nSono morti tutti i giocatori";
    } else {
        tmp->getNomGioc(nomgioc);
		cout << "\nHa vinto giocatore " <<nomgioc<< "\nCon ancora " << tmp->getCibo() << " unità di cibo \na coordinate x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
    }
	
	//elimino tutti i giocatori,coordinate e le stanze
    cout<<"\nPulisco memoria\n";
	rimuovi(head);
	headCoordinate->rem(headCoordinate);
	cout<<"Fine pulizia\n";
	return 0;
}

void rimuovi(Giocatore *headGiocatore){
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
}*/
