#ifndef STANZA_HPP
#define STANZA_HPP

#include <iostream>
#include<ctime>
#include<cstdlib>

class Stanza{
private:
	Stanza* nextUP;
	Stanza* nextDOWN;
	Stanza* nextRIGHT;
	Stanza* nextLEFT;
	int cibo;
public:
	Stanza();
	~Stanza();
	Stanza* Aggiungi_Stanza(Stanza* Stanza_Vecchia, Stanza* Stanza_Nuova, int direzione);
	Stanza* creaTesta();
	void azzeraCibo();
	void imp_valoreRandom();
	void impCibo();
	int getCibo();
};

#endif
