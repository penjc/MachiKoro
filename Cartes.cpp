#include "Cartes.h"

using namespace machi;

void Cartes::set_card(string name, int cost, int value, int low_roll, int high_roll, Icon icon, Couleur color)
{
	this->set_name(name);
	this->set_value(value);
	this->set_cost(cost);
	this->set_low_roll(low_roll);
	this->set_high_roll(high_roll);
	this->set_icon(icon);
	this->set_color(color);
}

void Cartes::set_cost(int cost)
{
	this->cost = cost;
}
void Cartes::set_value(int value)
{
	this->value = value;
}
void Cartes::set_color(Couleur color)
{
	this->color = color;
}
void Cartes::set_name(string name)
{
	this->name = name;
}
void Cartes::set_renovation(bool renovation)
{
	this->renovation = renovation;
}
void Cartes::set_low_roll(int low)
{
	this->low_roll = low;
}
void Cartes::set_high_roll(int high)
{
	this->high_roll = high;
}
void Cartes::set_icon(Icon icon)
{
	this->icon = icon;
}

int Cartes::get_value()
{
	return this->value;
}
int Cartes::get_cost()
{
	return this->cost;
}
Couleur Cartes::get_color()
{
	return this->color;
}
bool Cartes::get_renovation()
{
	return this->renovation;
}
string Cartes::get_name()
{
	return this->name;
}
Icon Cartes::get_icon()
{
	return this->icon;
}
int Cartes::get_low_roll()
{
	return this->low_roll;
}
int Cartes::get_high_roll()
{
	return this->high_roll;
}
string Cartes::get_string_color()
{
	switch (this->get_color())
	{
	case Couleur::bleu:
		return "bleu";
	case Couleur::vert:
		return "vert";
	case Couleur::rouge:
		return "rouge";
	case Couleur::violet:
		return "violet";
	case Couleur::jaune:
		return "jaune";
	}
}