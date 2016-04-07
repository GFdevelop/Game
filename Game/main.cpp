#include <iostream>
#include "Stanza.hpp"
//#include "Giocatore.hpp"
#include "coordinate.hpp"
using namespace std;

int main()
{
	coordinate * c = new coordinate;
	coordinate * d = NULL;
	
	int dir;
	
	d = c->add(c, c, 0);
	cin >> dir;
	d = c->search(c, d, dir);
	cin >> dir;
	d = c->search(c, d, dir);
	//c->printList(c);
	cin >> dir;
	d->search(c, d, dir);
	c->rem(c);
}

