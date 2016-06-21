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
    // Precondition: Stanza_Vecchia non deve essere NULL Stanza_Nuova deve essere NULL direzione deve essere 2, 4, 6 o 8
    // Postcondition: ritorna la Stanza_Nuova
    
	void azzeraCibo();
    // Postcondition: mette il cibo a 0
    
	void setCibo();
    // Postcondition: imposta il cibo in base a un valore random autogenerato
    
	int getCibo();
    // Postcondition: ritorna il cibo
};

#endif
