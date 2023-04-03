#include "Cartes_vert.h"

void Cartes_vert::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val)
{
	int bonus = 0;
	if (c1 != NULL) bonus = 1;
	if (this->multiplier == Icon::none)
	{
		p1->deposit(this->get_value() + bonus);
	}
	else
	{
		p1->deposit((this->get_value() * val) + bonus);
	}
}

void Cartes_vert::set_multiplier_icon(Icon icon)
{
	this->multiplier = icon;
}

boulangerie::boulangerie() {
	this->set_card("boulangerie", 1, 1, 2, 3, Icon::bread, Couleur::vert);
	this->set_multiplier_icon(Icon::none);
}

petite_boutique::petite_boutique() {
	this->set_card("petite_boutique", 2, 3, 4, 4, Icon::bread, Couleur::vert);
	this->set_multiplier_icon(Icon::none);
}

fromagerie::fromagerie() {
	this->set_card("fromagerie", 5, 3, 7, 7, Icon::factory, Couleur::vert);
	this->set_multiplier_icon(Icon::cow);
}

usine_de_meubles::usine_de_meubles() {
	this->set_card("usine_de_meubles", 3, 3, 8, 8, Icon::bread, Couleur::vert);
	this->set_multiplier_icon(Icon::gear);
}

boutique_de_fruits::boutique_de_fruits() {
	this->set_card("boutique_de_fruits", 2, 2, 11, 12, Icon::bread, Couleur::vert);
	this->set_multiplier_icon(Icon::grain);
}

magasin_de_fleurs::magasin_de_fleurs(){
    this->set_card("magasin_de_fleurs", 1, 1, 6, 6, Icon::bread, Couleur::vert);
    this->set_multiplier_icon(Icon::none);
};

Marche_alimentaire::Marche_alimentaire(){
    this->set_card("Marche_alimentaire", 2, 2, 12, 13, Icon::factory, Couleur::vert);
    this->set_multiplier_icon(Icon::retaurant);
};