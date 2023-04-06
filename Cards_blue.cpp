#include "Cards_blue.h"

void Cards_blue::action(Bank *p1, Bank *p2, Cards *c1, Cards *c2, int val)
{
	p1->deposit(this->get_value());
}

mais::mais()
{
	this->set_card("mais", 1, 1, 1, 1, Icon::grain, Color::bleu);
}

ferme::ferme()
{
	this->set_card("ferme", 1, 1, 2, 2, Icon::cow, Color::bleu);
}

foret::foret()
{
	this->set_card("foret", 3, 1, 5, 5, Icon::gear, Color::bleu);
}

Mine::Mine()
{
	this->set_card("mine", 6, 5, 9, 9, Icon::gear, Color::bleu);
}

verger::verger()
{
	this->set_card("verger", 3, 3, 10, 10, Icon::grain, Color::bleu);
}

champ_de_fleurs::champ_de_fleurs()
{
    this->set_card("champ_de_fleurs", 2, 1, 4, 4, Icon::grain, Color::bleu);
}

Bateau_maquereau::Bateau_maquereau()
{
    this->set_card("Bateau_maquereau", 2, 3, 8, 8, Icon::boat, Color::bleu);
}

Thonier::Thonier()
{
    this->set_card("Thonier", 5, 0, 12, 14, Icon::boat, Color::bleu);
}