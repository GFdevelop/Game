#include "Stanza.hpp"
#include <iostream>
using namespace std;

Stanza::Stanza() {
    head = new Stanza;
    head->nextUP=NULL;
    head->nextRIGHT=NULL;
    head->nextDOWN=NULL;
    head->nextLEFT=NULL;
}

Stanza::~Stanza() {
	/*while (testa != NULL) {
		Camera * n = testa->next;
		delete testa;
		testa = n;
	}*/
}

Stanza* Stanza::getTesta()
{
    return(head);
}

Stanza* Stanza::Aggiungi_Stanza(Stanza* Stanza_Vecchia, Stanza* Stanza_Nuova, int direzione){
    //1=su 2=dx 3=giù 4=sx
    if (Stanza_Nuova==NULL){
        Stanza_Nuova= new Stanza;
        Stanza_Nuova->nextUP=NULL;
        Stanza_Nuova->nextRIGHT=NULL;
        Stanza_Nuova->nextDOWN=NULL;
        Stanza_Nuova->nextLEFT=NULL;
    }
    if (direzione==1){
        if (Stanza_Vecchia->nextUP==NULL) {
            Stanza_Vecchia->nextUP=Stanza_Nuova;
            Stanza_Nuova->nextDOWN=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextUP==Stanza_Nuova) {
            cout<<"La porta NORD è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a NORD";
        }
    } else if (direzione==2){
        if (Stanza_Vecchia->nextRIGHT==NULL) {
            Stanza_Vecchia->nextRIGHT=Stanza_Nuova;
            Stanza_Nuova->nextLEFT=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta EST è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a EST";
        }
    } else if (direzione==3){
        if (Stanza_Vecchia->nextDOWN==NULL) {
            Stanza_Vecchia->nextDOWN=Stanza_Nuova;
            Stanza_Nuova->nextUP=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta SUD è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a SUD";
        }
    } else if (direzione==4){
        if (Stanza_Vecchia->nextLEFT==NULL) {
            Stanza_Vecchia->nextLEFT=Stanza_Nuova;
            Stanza_Nuova->nextRIGHT=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta OVEST è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a OVEST";
        }
    } else {
        cout<<"ERRORE, direzione sbagliata";
    }
    return (Stanza_Nuova);
}