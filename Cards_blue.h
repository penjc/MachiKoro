#pragma once

#include "Cards.h"

using namespace machi;

class Cards_blue: public Cards {
public:
	virtual void action(Bank *p1, Bank *p2, Cards *c1, Cards *c2, int val);
private:
};
//麦田
class mais : public Cards_blue {
public:
	mais();
};
//农场
class ferme : public Cards_blue {
public:
	ferme();
};
//林场
class foret : public Cards_blue {
public:
	foret();
};
//矿场
class Mine : public Cards_blue {
public:
	Mine();
};
//果园
class verger : public Cards_blue {
public:
	verger();
};
//花田
class champ_de_fleurs : public Cards_blue {
public:
    champ_de_fleurs();
};
//鲭鱼船
class Bateau_maquereau : public Cards_blue {
public:
    Bateau_maquereau();
};
//金枪鱼船
class Thonier : public Cards_blue {
public:
    Thonier();
};