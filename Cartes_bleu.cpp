#include "Cartes_bleu.h"

void Cartes_bleu::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val)
{
	p1->deposit(this->get_value());
}
//定义麦田的相关参数
mais::mais()
{
	this->set_card("mais", 1, 1, 1, 1, Icon::grain, Couleur::bleu);
}
//定义农场的相关参数
ferme::ferme()
{
	this->set_card("ferme", 1, 1, 2, 2, Icon::cow, Couleur::bleu);
}
//定义林场相关参数
foret::foret()
{
	this->set_card("foret", 3, 1, 5, 5, Icon::gear, Couleur::bleu);
}
//定义矿场相关参数
Mine::Mine()
{
	this->set_card("mine", 6, 5, 9, 9, Icon::gear, Couleur::bleu);
}
//定义果园相关参数
verger::verger()
{
	this->set_card("verger", 3, 3, 10, 10, Icon::grain, Couleur::bleu);
}
//港口拓展包卡片
//定义花田相关参数
champ_de_fleurs::champ_de_fleurs()
{
    this->set_card("champ_de_fleurs", 2, 1, 4, 4, Icon::grain, Couleur::bleu);
}
//定义鲭鱼船相关参数
Bateau_maquereau::Bateau_maquereau()
{
    this->set_card("Bateau_maquereau", 2, 3, 8, 8, Icon::boat, Couleur::bleu);
}
//定义金枪鱼船相关参数
Thonier::Thonier()
{
    this->set_card("Thonier", 5, 0, 12, 14, Icon::boat, Couleur::bleu);
}