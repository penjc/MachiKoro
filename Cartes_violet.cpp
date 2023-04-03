#include "Cartes_violet.h"
//定义商业中心相关参数
centre_commercial::centre_commercial() {
	this->set_card("centre_commercial", 8, 0, 6, 6, Icon::establishment, Couleur::violet);
}

void centre_commercial::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) {
	// This one is going to be fun. Let the game manager handle it for now.
}
//定义体育馆相关参数
stade::stade() {
	this->set_card("stade", 6, 2, 6, 6, Icon::establishment, Couleur::violet);
}
void stade::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) {
	p1->deposit(p2->withdraw(this->get_value()));
}
//定义电视台相关参数
station_de_television::station_de_television() {
	this->set_card("station_de_television", 7, 5, 6, 6, Icon::retaurant, Couleur::violet);
}
void station_de_television::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) {
	p1->deposit(p2->withdraw(this->get_value()));
}
//以下为港口拓展包内容
//定义税务局相关参数
regie::regie() {
    this->set_card("regie", 4, 4, 8, 9, Icon::establishment, Couleur::violet);
}
void regie::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) {
//    p1->deposit(p2->withdraw(this->get_value()));
}
//定义出版社相关参数
maison_de_edition::maison_de_edition() {
    this->set_card("maison_de_edition", 5, 1, 7, 7, Icon::establishment, Couleur::violet);
}
void maison_de_edition::action(Banque *p1, Banque *p2, Cartes *c1, Cartes *c2, int val) {
//    p1->deposit(p2->withdraw(this->get_value()));
}