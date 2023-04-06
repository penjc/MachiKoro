#pragma once

#include "Cards.h"

using namespace machi;

class Cartes_jaune : public Cartes {
public:
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
	bool active;
private:
};
//游乐场
class parc_de_loisirs : public Cartes_jaune {
public:
	parc_de_loisirs();
private:
};
//电视塔
class tour_de_tele : public Cartes_jaune {
public:
	tour_de_tele();
private:
};
//商业中心
class marche : public Cartes_jaune {
public:
	marche();
private:
};
//火车站
class gare : public Cartes_jaune {
public:
	gare();
private:
};
//市政厅
class hotel_de_ville : public Cartes_jaune{
public:
    hotel_de_ville();
};
//机场
class aeroport : public Cartes_jaune{
public:
    aeroport();
};
//港口
class port : public Cartes_jaune{
public:
    port();
};