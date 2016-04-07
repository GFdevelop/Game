#include "Stanza.hpp"
#include <iostream>
using namespace std;

Stanza::Stanza() {
    nextUP=NULL;
    nextRIGHT=NULL;
    nextDOWN=NULL;
    nextLEFT=NULL;
}

Stanza::~Stanza() {
	/*while (testa != NULL) {
		Camera * n = testa->next;
		delete testa;
		testa = n;
	}*/
}

Stanza* Stanza::creaTesta(){
    Stanza* testa;
    testa=new Stanza;
    testa->head=testa;
    return testa;
}

Stanza* Stanza::getTesta(){
    return(head);
}


void Stanza::Stampa(Stanza* p){
    if (p->nextUP!=NULL) {
        cout<<"Collegmento a NORD \n";
    }
    if (p->nextLEFT!=NULL) {
        cout<<"Collegmento a EST \n";
    }
    if (p->nextDOWN!=NULL) {
        cout<<"Collegmento a SUD \n";
    }
    if (p->nextRIGHT!=NULL) {
        cout<<"Collegmento a OVEST \n";
    }
}

Stanza* Stanza::Aggiungi_Stanza(Stanza* Stanza_Vecchia, Stanza* Stanza_Nuova, int direzione){
    //1=su 2=dx 3=giù 4=sx
    //la prima volta che viene mandato Stanxa_vecchia deve essere inizializata con creaTesta;
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
            cout<<"ERRORE, stai sovrascrivendo una stanza a NORD"<<endl;
            return (Stanza_Vecchia);
        }
    } else if (direzione==2){
        if (Stanza_Vecchia->nextRIGHT==NULL) {
            Stanza_Vecchia->nextRIGHT=Stanza_Nuova;
            Stanza_Nuova->nextLEFT=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta EST è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a EST"<<endl;
            return (Stanza_Vecchia);
        }
    } else if (direzione==3){
        if (Stanza_Vecchia->nextDOWN==NULL) {
            Stanza_Vecchia->nextDOWN=Stanza_Nuova;
            Stanza_Nuova->nextUP=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta SUD è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a SUD"<<endl;
            return (Stanza_Vecchia);
        }
    } else if (direzione==4){
        if (Stanza_Vecchia->nextLEFT==NULL) {
            Stanza_Vecchia->nextLEFT=Stanza_Nuova;
            Stanza_Nuova->nextRIGHT=Stanza_Vecchia;
        } else if (Stanza_Vecchia->nextRIGHT==Stanza_Nuova) {
            cout<<"La porta OVEST è già stata aperta";
        } else {
            cout<<"ERRORE, stai sovrascrivendo una stanza a OVEST"<<endl;
            return (Stanza_Vecchia);
        }
    } else {
        cout<<"ERRORE, inserita direzione sbagliata"<<endl;
        return (Stanza_Vecchia);
    }
    Stanza_Nuova->head=(Stanza_Vecchia->getTesta());
    return (Stanza_Nuova);
}