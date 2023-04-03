#include "Cartes_jaune.h"

void Cartes_jaune::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val)
{
	// Nothing to really do here yet because jaune cards dont perform actions in the same manner
}

gare::gare() {
	this->active = false;
	this->set_card("gare", 4, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

marche::marche() {
	this->active = false;
	this->set_card("marche", 10, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

parc_de_loisirs::parc_de_loisirs() {
	this->active = false;
	this->set_card("parc_de_loisirs", 16, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

tour_de_tele::tour_de_tele() {
	this->active = false;
	this->set_card("tour_de_tele", 22, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

port::port() {
    this->active = false;
    this->set_card("port", 2, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

aeroport::aeroport() {
    this->active = false;
    this->set_card("aeroport", 30, 0, 0, 0, Icon::establishment, Couleur::jaune);
}

hotel_de_ville::hotel_de_ville() {
    this->active = false;
    this->set_card("hotel_de_ville", 0, 0, 0, 0, Icon::establishment, Couleur::jaune);
}
