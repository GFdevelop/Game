#pragma once

class Stanza{
private:
    Stanza* nextUP;
    Stanza* nextDOWN;
    Stanza* nextRIGHT;
    Stanza* nextLEFT;
    Stanza* head;
public:
    Stanza();
    ~Stanza();
    Stanza* Aggiungi_Stanza(Stanza* Stanza_Vecchia, Stanza* Stanza_Nuova, int direzione);
    Stanza* getTesta();
};