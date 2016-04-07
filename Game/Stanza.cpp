#include "Stanza.hpp"
using namespace std;
//mi vedi?

Stanza::Stanza() {
	nextUP = NULL;
	nextRIGHT = NULL;
	nextDOWN = NULL;
	nextLEFT = NULL;
	valoreRandom = 0;
	srand(time(0));
	valoreRandom = (rand() % 11) + 1;
	impCibo();
}

Stanza::~Stanza() {
}

void Stanza::Stampa() {
	if (nextUP != NULL) {
		cout << "Collegmento a NORD \n";
	}
	if (nextLEFT != NULL) {
		cout << "Collegmento a OVEST \n";
	}
	if (nextDOWN != NULL) {
		cout << "Collegmento a SUD \n";
	}
	if (nextRIGHT != NULL) {
		cout << "Collegmento a EST \n";
	}
	if ((nextUP != NULL) && (nextLEFT != NULL) && (nextDOWN != NULL) && (nextRIGHT != NULL)) {
		cout << "Nessun collegmento \n";
	}
	cout << "Valore random: " << valoreRandom << "\n";
	cout << "Numero cibo: " << cibo << "\n\n";
}

Stanza* Stanza::Aggiungi_Stanza(Stanza * Stanza_Vecchia, Stanza * Stanza_Nuova, int direzione) {
	//2=giù 4=sx 6=dx 8=sù
	if (Stanza_Nuova == NULL) {
		Stanza_Nuova = new Stanza;
	}
	if (direzione == 8) {
		if ((Stanza_Nuova->nextDOWN != NULL) && (Stanza_Nuova->nextDOWN != Stanza_Vecchia)) {
			cout << "ERRORE, la stanza nuova ha già un coolegmento a SUD diverso dalla stanza vecchia, ritorno stanza vecchia" << endl;
			return (Stanza_Vecchia);
		}
		else {
			if (Stanza_Vecchia->nextUP == NULL) {
				Stanza_Vecchia->nextUP = Stanza_Nuova;
				Stanza_Nuova->nextDOWN = Stanza_Vecchia;
			}
			else if (Stanza_Vecchia->nextUP == Stanza_Nuova) {
				cout << "La porta NORD è già stata aperta \n";
			}
			else if ((Stanza_Vecchia->nextUP != Stanza_Nuova)) {
				cout << "ERRORE, stai sovrascrivendo la stanza a NORD, ritorno stanza vecchia \n" << endl;
				return (Stanza_Vecchia);
			}
		}
	}
	else if (direzione == 6) {
		if ((Stanza_Nuova->nextLEFT != NULL) && (Stanza_Nuova->nextLEFT != Stanza_Vecchia)) {
			cout << "ERRORE, la stanza nuova ha già un coolegmento a OVEST diverso dalla stanza vecchia, ritorno stanza vecchia" << endl;
			return (Stanza_Vecchia);
		}
		else {
			if (Stanza_Vecchia->nextRIGHT == NULL) {
				Stanza_Vecchia->nextRIGHT = Stanza_Nuova;
				Stanza_Nuova->nextLEFT = Stanza_Vecchia;
			}
			else if (Stanza_Vecchia->nextRIGHT == Stanza_Nuova) {
				cout << "La porta EST è già stata aperta";
			}
			else {
				cout << "ERRORE, stai sovrascrivendo la stanza a EST" << endl;
				return (Stanza_Vecchia);
			}
		}
	}
	else if (direzione == 2) {
		if ((Stanza_Nuova->nextUP != NULL) && (Stanza_Nuova->nextUP != Stanza_Vecchia)) {
			cout << "ERRORE, la stanza nuova ha già un coolegmento a NORD diverso dalla stanza vecchia, ritorno stanza vecchia" << endl;
			return (Stanza_Vecchia);
		}
		else {
			if (Stanza_Vecchia->nextDOWN == NULL) {
				Stanza_Vecchia->nextDOWN = Stanza_Nuova;
				Stanza_Nuova->nextUP = Stanza_Vecchia;
			}
			else if (Stanza_Vecchia->nextDOWN == Stanza_Nuova) {
				cout << "La porta SUD è già stata aperta";
			}
			else {
				cout << "ERRORE, stai sovrascrivendo la stanza a SUD" << endl;
				return (Stanza_Vecchia);
			}
		}
	}
	else if (direzione == 4) {
		if ((Stanza_Nuova->nextRIGHT != NULL) && (Stanza_Nuova->nextRIGHT != Stanza_Vecchia)) {
			cout << "ERRORE, la stanza nuova ha già un coolegmento a EST diverso dalla stanza vecchia, ritorno stanza vecchia" << endl;
			return (Stanza_Vecchia);
		}
		else {
			if (Stanza_Vecchia->nextLEFT == NULL) {
				Stanza_Vecchia->nextLEFT = Stanza_Nuova;
				Stanza_Nuova->nextRIGHT = Stanza_Vecchia;
			}
			else if (Stanza_Vecchia->nextRIGHT == Stanza_Nuova) {
				cout << "La porta OVEST è già stata aperta";
			}
			else {
				cout << "ERRORE, stai sovrascrivendo la stanza a OVEST" << endl;
				return (Stanza_Vecchia);
			}
		}
	}
	else {
		cout << "ERRORE, inserita direzione sbagliata" << endl;
		return (Stanza_Vecchia);
	}
	return (Stanza_Nuova);
}

int Stanza::getRandom() {
	return (valoreRandom);
}

void Stanza::azzeraRandom_eCibo() {
	cibo = 0;
	valoreRandom = 0;
}

void Stanza::impCibo() {
	//da 1 a 5 = nulla
	//da 6 a 8 = 5 cibo
	//da 9 a 10 = 10 cibo
	//11       = 20 cibo
	if (valoreRandom == 11) {
		cibo = 20;
	}
	else if ((valoreRandom >= 9) && (valoreRandom <= 10)) {
		cibo = 10;
	}
	else if ((valoreRandom >= 6) && (valoreRandom <= 8)) {
		cibo = 5;
	}
	else {
		cibo = 0;
	}
}

int Stanza::getCibo() {
	return (cibo);
}