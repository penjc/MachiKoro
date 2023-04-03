#include "Cartes_rouge.h"

// Player 1 will take coins from Joueur 2
void Cartes_rouge::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val)
{
	int bonus = 0;
	if (c1 != NULL) bonus = 1;
	p1->deposit(p2->withdraw(this->get_value()+bonus));
}

Cafe::Cafe() {
	this->set_card("Cafe", 2, 1, 3, 3, Icon::retaurant, Couleur::rouge);
}

restaurant::restaurant() {
	this->set_card("restaurant", 3, 2, 9, 10, Icon::retaurant, Couleur::rouge);
}

sushis::sushis() {
    this->set_card("sushis", 2, 3, 1, 1, Icon::retaurant, Couleur::rouge);
}

pizza::pizza() {
    this->set_card("pizza", 1, 1, 7, 7, Icon::retaurant, Couleur::rouge);
}

hamburger::hamburger() {
    this->set_card("hamburger", 1, 1, 8, 8, Icon::retaurant, Couleur::rouge);
}