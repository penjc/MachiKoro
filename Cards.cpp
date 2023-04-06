#include "Cards.h"

using namespace machi;

void Cards::set_card(string name, int cost, int value, int low_roll, int high_roll, Icon icon, Color color)
{
	this->set_name(name);
	this->set_value(value);
	this->set_cost(cost);
	this->set_low_roll(low_roll);
	this->set_high_roll(high_roll);
	this->set_icon(icon);
	this->set_color(color);
}

void Cards::set_cost(int cost)
{
	this->cost = cost;
}
void Cards::set_value(int value)
{
	this->value = value;
}
void Cards::set_color(Color color)
{
	this->color = color;
}
void Cards::set_name(string name)
{
	this->name = name;
}
void Cards::set_renovation(bool renovation)
{
	this->renovation = renovation;
}
void Cards::set_low_roll(int low)
{
	this->low_roll = low;
}
void Cards::set_high_roll(int high)
{
	this->high_roll = high;
}
void Cards::set_icon(Icon icon)
{
	this->icon = icon;
}

int Cards::get_value()
{
	return this->value;
}
int Cards::get_cost()
{
	return this->cost;
}
Color Cards::get_color()
{
	return this->color;
}
bool Cards::get_renovation()
{
	return this->renovation;
}
string Cards::get_name()
{
	return this->name;
}
Icon Cards::get_icon()
{
	return this->icon;
}
int Cards::get_low_roll()
{
	return this->low_roll;
}
int Cards::get_high_roll()
{
	return this->high_roll;
}
string Cards::get_string_color()
{
	switch (this->get_color())
	{
	case Color::blue:
		return "blue";
	case Color::green:
		return "green";
	case Color::red:
		return "red";
	case Color::violet:
		return "violet";
	case Color::yellow:
		return "yellow";
	}
}