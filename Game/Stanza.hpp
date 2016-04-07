#pragma once
#include <iostream>
#include<ctime>
#include<cstdlib>

class Stanza
{
private:
	Stanza* nextUP;
	Stanza* nextDOWN;
	Stanza* nextRIGHT;
	Stanza* nextLEFT;
	int valoreRandom;
	int cibo;
public:
	Stanza();
	~Stanza();
	Stanza* Aggiungi_Stanza(Stanza* Stanza_Vecchia, Stanza* Stanza_Nuova, int direzione);
	void Stampa();
	Stanza* creaTesta();
	int getRandom();
	void azzeraRandom_eCibo();
	void imp_valoreRandom();
	void impCibo();
	int getCibo();
};
