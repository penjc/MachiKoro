#pragma once

#include "Cartes.h"

using namespace machi;

class Cartes_rouge : public Cartes {
public:
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//咖啡店
class Cafe : public Cartes_rouge {
public:
	Cafe();
};
//餐厅
class restaurant : public Cartes_rouge {
public:
	restaurant();
};
//寿司店
class sushis : public Cartes_rouge {
public:
    sushis();
};
//披萨店
class pizza : public Cartes_rouge{
public:
    pizza();
};
//汉堡店
class hamburger : public Cartes_rouge{
public:
    hamburger();
};