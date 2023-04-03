#pragma once
#include "Cartes.h"

using namespace machi;
//声明所有紫色卡牌
class Cartes_violet : public Cartes {
public:
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) = 0;
private:
};
//商业中心
class centre_commercial : public Cartes_violet {
public:
	centre_commercial();
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//体育馆
class stade : public Cartes_violet {
public:
	stade();
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//电视台
class station_de_television : public Cartes_violet {
public:
	station_de_television();
	virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//税务局
class regie : public Cartes_violet {
public:
    regie();
    virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};
//出版社
class maison_de_edition : public Cartes_violet {
public:
    maison_de_edition();
    virtual void action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val);
private:
};