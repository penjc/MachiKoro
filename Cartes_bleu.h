#pragma once

#include "Cartes.h"

using namespace machi;
//声明所有蓝色卡牌
class Cartes_bleu: public Cartes {
public:
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//麦田
class mais : public Cartes_bleu {
public:
	mais();
};
//农场
class ferme : public Cartes_bleu {
public:
	ferme();
};
//林场
class foret : public Cartes_bleu {
public:
	foret();
};
//矿场
class Mine : public Cartes_bleu {
public:
	Mine();
};
//果园
class verger : public Cartes_bleu {
public:
	verger();
};
//花田
class champ_de_fleurs : public Cartes_bleu {
public:
    champ_de_fleurs();
};
//鲭鱼船
class Bateau_maquereau : public Cartes_bleu {
public:
    Bateau_maquereau();
};
//金枪鱼船
class Thonier : public Cartes_bleu {
public:
    Thonier();
};