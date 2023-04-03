#pragma once

#include "Cartes.h"

using namespace machi;

class Cartes_vert : public Cartes {
public:
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
	void set_multiplier_icon(Icon icon);
private:
	Icon multiplier = Icon::none;
};
//面包店
class boulangerie : public Cartes_vert {
public:
	boulangerie();
};
//便利店
class petite_boutique : public Cartes_vert {
public:
	petite_boutique();
};
//芝士工厂
class fromagerie : public Cartes_vert {
public:
	fromagerie();
};
//家具工厂
class usine_de_meubles : public Cartes_vert {
public:
	usine_de_meubles();
};
//果蔬超市
class boutique_de_fruits : public Cartes_vert {
public:
	boutique_de_fruits();
};
//花店
class magasin_de_fleurs : public Cartes_vert {
public:
    magasin_de_fleurs();
};
//食品市场
class Marche_alimentaire : public Cartes_vert {
public:
    Marche_alimentaire();
};