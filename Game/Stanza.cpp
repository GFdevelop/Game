#include "Stanza.hpp"
using namespace std;


Stanza::Stanza() {
    nextUP = NULL;
    nextRIGHT = NULL;
    nextDOWN = NULL;
    nextLEFT = NULL;
    cibo=0;//viene impostato in Aggiungi_Stanza con setCibo
}

Stanza::~Stanza() {
}

Stanza* Stanza::Aggiungi_Stanza(Stanza * Stanza_Vecchia, Stanza * Stanza_Nuova, int direzione) {
    //Aggiungi_Stanza crea una nuova stanza se le viene passata come nulla e la collega con la staza precedente,altrimenti collega solo le due stanze
    //2=giù 4=sx 6=dx 8=sù
    if (Stanza_Nuova == NULL) {
        Stanza_Nuova = new Stanza;
        Stanza_Nuova->setCibo();
    }
    if ((direzione == 8)&&(Stanza_Nuova->nextDOWN==NULL)&&(Stanza_Vecchia->nextUP==NULL)) {
            Stanza_Vecchia->nextUP = Stanza_Nuova;
            Stanza_Nuova->nextDOWN = Stanza_Vecchia;
    }
    else if ((direzione == 6)&&(Stanza_Nuova->nextLEFT==NULL)&&(Stanza_Vecchia->nextRIGHT==NULL)) {
            Stanza_Vecchia->nextRIGHT = Stanza_Nuova;
            Stanza_Nuova->nextLEFT = Stanza_Vecchia;
    }
    else if ((direzione == 2)&&(Stanza_Nuova->nextUP==NULL)&&(Stanza_Vecchia->nextDOWN==NULL)){
            Stanza_Vecchia->nextDOWN = Stanza_Nuova;
            Stanza_Nuova->nextUP = Stanza_Vecchia;
    }
    else if ((direzione == 4)&&(Stanza_Nuova->nextRIGHT==NULL)&&(Stanza_Vecchia->nextLEFT==NULL)) {
            Stanza_Vecchia->nextLEFT = Stanza_Nuova;
            Stanza_Nuova->nextRIGHT = Stanza_Vecchia;
    }
    return (Stanza_Nuova);
}

void Stanza::azzeraCibo() {
    cibo = 0;
}

void Stanza::setCibo() {
    /*
     viene generato un numero random (seguendo l'esempio del dado) e in base a quel numero
     si assegna un tot di cibo in base a questa percentuale:
     2% = 10 cibo (50)
     4% = 5 cibo (48 e 49)
     8% = 2 cibo (da 44 a 47)
     86% = 0 cibo (da 0 a 43)
    */
    srand(time(0));
    int valoreRandom=0;
    valoreRandom=(rand() % 50) + 1;
    if (valoreRandom==50) {
        cibo = 10;
    }
    else if ((valoreRandom >= 48) && (valoreRandom <= 49)) {
        cibo = 5;
    }
    else if ((valoreRandom >= 44) && (valoreRandom <= 47)) {
        cibo = 2;
    }
    else {
        cibo = 0;
    }
}

int Stanza::getCibo() {
    return (cibo);
}
