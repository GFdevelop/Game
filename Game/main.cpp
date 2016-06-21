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

void eliminaLista(Giocatore *headGiocatore);
// Postcondition: elimina tutta la lista dei giocatori

void aggiungi_cibo(Giocatore* tmp);
// Precondition: tmp diverso da NULL
// Postcondition: trasferisce il cibo dalla stanza al giocatore

Giocatore* eliminaGiocatore(Giocatore* head);
// Precondition: head != NULL
// Postcondition: elimina dalla lista giocatori il giocatore con 0 di cibo

int main(){
	Giocatore *headGiocatore = NULL;
    Giocatore *tmp;
	coordinate *d = NULL;
	coordinate *headCoordinate = new coordinate;
	mappa *m = new mappa;
	
	int turno = 1;
	int direzione = 0;
	int giro = 1;
	int numgioc = 0;
	int tmpGioc, tmpCibo;
    char nomgioc[20] = "";
    
	//prende in input numero giocatori
    do{
		cout << "Inserisci il numero di giocatori (Min 2-Giocatori) :";
		cin >> numgioc;
	} while (numgioc < 2);
	tmpGioc = numgioc;
    
	//inserisce i giocatori in una lista
	for (int i = 1; i <= numgioc; i++){
		headGiocatore = headGiocatore->AddGioc(headGiocatore, d);
	}
    
	d = headCoordinate->add(headCoordinate, NULL, 0); //inizializza la stanza
	m->add(d);	//per definire i confini inziali della mappa (0,0)
    
    //inizializza tutti i giocatori alla stanza iniziale con coordinate 0,0
    tmp = headGiocatore;
	while (tmp!=NULL) {
        tmp->setStanza(d);
        tmp=tmp->getNext();
    }
    tmp = headGiocatore;
    
    //pulisce la schermata
    system(CLEARSCR);
    

    while ((headGiocatore!=NULL) && ((headGiocatore->getNext())!=NULL)) {
		while (giro != (numgioc + 1)) {//ciclo che gestisce a quale giocatore tocca
            
            cout<<"Turno "<<turno<<endl;
            m->print(headCoordinate, headGiocatore);
            
            //viene assegnato il nome del giocatore a nomgioc
            tmp->getNomGioc(nomgioc);
            
			cout << "\nTocca a giocatore " << nomgioc << "\nCibo a disposizione: " << tmp->getCibo() << "\nCoordinate giocatore: x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
            do {
				cout << "\nDove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
				cin >> direzione;
			} while ((direzione != 8) && (direzione != 6) && (direzione != 2) && (direzione != 4));
            
            //toglie una unità di cibo al giocatore
			tmp->setCibo((tmp->getCibo()) - 1);
            
			d = headCoordinate->search(headCoordinate, tmp->getStanza(), direzione);
            
            //per aggiornare gli estremi della mappa
			m->add(d);
            
			tmp->setStanza(d);
            aggiungi_cibo(tmp);
            
            tmpCibo=tmp->getCibo();
            tmp=tmp->getNext();
            
            //se il giocatore ha 0 di cibo allora viene eliminato
            if (tmpCibo==0) {
                headGiocatore = eliminaGiocatore(headGiocatore);
                tmpGioc = tmpGioc - 1;
            }
            
			giro++;
			system(CLEARSCR);
		}
        
		//ricomincia il giro
		giro = 1;
		turno = turno + 1;
        tmp = headGiocatore;
		numgioc = tmpGioc;
	}
    
	//fine gioco
    if (headGiocatore==NULL) {
        cout<<"\nSono morti tutti i giocatori\n\n";
    } else {
        tmp->getNomGioc(nomgioc);
		cout << "\nHa vinto giocatore " <<nomgioc<< "\nCon ancora " << tmp->getCibo() << " unità di cibo \na coordinate x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey()<<endl<<endl;
    }
	
	//elimino tutti i giocatori, le coordinate e le stanze
	eliminaLista(headGiocatore);
	headCoordinate->rem(headCoordinate);
    delete m;
    
	return 0;
}

void aggiungi_cibo(Giocatore* tmp){
    int ciboStanza = tmp->getStanza()->getRoom()->getCibo();
    if (ciboStanza != 0) {
        cout << "Hai trovato " << ciboStanza << " unita' di cibo!\n";
        tmp->setCibo((tmp->getCibo()) + ciboStanza);
    }
    tmp->getStanza()->getRoom()->azzeraCibo();
}

void eliminaLista(Giocatore *headGiocatore){
    if (headGiocatore != NULL)
        eliminaLista(headGiocatore->getNext());
    delete headGiocatore;
}

Giocatore* eliminaGiocatore(Giocatore* head) {
    Giocatore* g=head;
    char nomgioc[20];
    
    if (g->getCibo()==0) {//caso in qui la testa deve essere eliminata
        head=head->getNext();
        g->getNomGioc(nomgioc);
        cout << "Eliminato giocatore "<<nomgioc<<endl;
        delete g;
    } else{
        bool found=0;
        while ((g != NULL) && ((g->getNext())!=NULL) && (found == 0)) {
            if ((g->getNext()->getCibo())==0) {
                found = 1;
            } else {
                g = g->getNext();
            }
        }
        if (found == 1) {
            Giocatore* q=g->getNext()->getNext();
            g->getNext()->getNomGioc(nomgioc);
            cout << "Eliminato giocatore "<<nomgioc<<endl;
            delete g->getNext();
            g->setNext(q);
        }
    }
    return(head);
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