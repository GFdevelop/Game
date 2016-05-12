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
void aggiungi_cibo(Giocatore* tmp);

typedef Giocatore* g;
int main(){
	Giocatore *head;
	coordinate *d = NULL;
	coordinate *headCoordinate = new coordinate;
	Giocatore *tmp;
	mappa * m = new mappa;
	
	int turno = 1;
	int mossa = 0;
	int giro=1;
	int numgioc=0, i;
	int tmpGioc;
    int tmpcibo;
    char nomgioc[20]="";
	head = NULL;
    
	//prende in input numero giocatori
    do{
		cout << "Inserisci il numero di giocatori (Min 2-Giocatori) :";
		cin >> numgioc;
	} while (numgioc < 2);
	tmpGioc = numgioc;
    
	//inserisce i giocatori in una lista
	for (i = 1; i <= numgioc; i++){
		head = head->AddGioc(head, d);
	}
	//inizializza la stanza
	d = headCoordinate->add(headCoordinate, NULL, 0);
	m->add(d);	//per definire i confini inziali della mappa (0,0)
    
    //inizializza tutti i giocatori alla stanza iniziale con coordinate 0,0
    tmp = head;
	while (tmp!=NULL) {
        tmp->setStanza(d);
        tmp=tmp->getNext();
    }
    tmp = head;
    
    //pulisce la schermata
    system(CLEARSCR);
    

    while ((head!=NULL) && ((head->getNext())!=NULL)) {
		while (giro != (numgioc + 1)) {//ciclo che gestisce a quale giocatore tocca
            
            cout<<"Turno "<<turno<<endl;
            m->print(headCoordinate, head);
            
            //viene assegnato il nome del giocatore a nomgioc
            tmp->getNomGioc(nomgioc);
            
			cout << "\nTocca a giocatore " << nomgioc << "\nCibo a disposizione: " << tmp->getCibo() << "\nCoordinate giocatore: x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey();
            do {
				cout << "\nDove si sposta? 8-su 6-destra 2-giu 4-sinistra: ";
				cin >> mossa;
			} while ((mossa != 8) && (mossa != 6) && (mossa != 2) && (mossa != 4));
            
            //toglie una unità di cibo al giocatore
			tmp->setCibo((tmp->getCibo()) - 1);
            
			d = headCoordinate->search(headCoordinate, tmp->getStanza(), mossa);
            
            //per aggiornare gli estremi della mappa
			m->add(d);
            
			tmp->setStanza(d);
            aggiungi_cibo(tmp);
            
            tmpcibo=tmp->getCibo();
            tmp=tmp->getNext();
            
            //se il giocatore ha 0 di cibo allora viene eliminato
            if (tmpcibo==0) {
                tmp->eliminaGiocatore(head);
                tmpGioc = tmpGioc - 1;
            }
            
			giro++;
			system(CLEARSCR);
		}
        
		//ricomincia il giro
		giro = 1;
		turno = turno + 1;
        tmp = head;
		numgioc = tmpGioc;
	}
    
	//fine gioco
    if (head==NULL) {
        cout<<"\nSono morti tutti i giocatori\n\n";
    } else {
        tmp->getNomGioc(nomgioc);
		cout << "\nHa vinto giocatore " <<nomgioc<< "\nCon ancora " << tmp->getCibo() << " unità di cibo \na coordinate x:" << tmp->getStanza()->getCoordinatex() << " y:" << tmp->getStanza()->getCoordinatey()<<endl<<endl;
    }
	
	//elimino tutti i giocatori, le coordinate e le stanze
	rimuovi(head);
	headCoordinate->rem(headCoordinate);
    delete m;
    
	return 0;
}

void rimuovi(Giocatore *headGiocatore){
	if (headGiocatore != NULL)
		rimuovi(headGiocatore->getNext());
	delete headGiocatore;
}

void aggiungi_cibo(Giocatore* tmp){
    int ciboStanza=0;
    ciboStanza = tmp->getStanza()->getRoom()->getCibo();
    if (ciboStanza != 0) {
        cout << "Hai trovato " << ciboStanza << " unita' di cibo!\n";
        tmp->setCibo((tmp->getCibo()) + ciboStanza);
    }
    tmp->getStanza()->getRoom()->azzeraCibo();
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
