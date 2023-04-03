#include <sstream>
#include <algorithm>
#include "Deck.h"


using namespace std;

ostream& operator << (ostream& os, const Couleur& obj)
{
	os << static_cast<typename underlying_type<Couleur>::type>(obj);
	return os;
}
ostream& operator << (ostream& os, const Icon& obj)
{
	os << static_cast<typename underlying_type<Icon>::type>(obj);
	return os;
}
//在deck上生成所有卡片
Deck::Deck() {
    Cartes *c;
    for (int i = 0; i < 4; i++) { c = new tour_de_tele() ; this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new parc_de_loisirs(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new marche(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new gare(); this->deck.push_back(c); }

    for (int i = 0; i < 4; i++) { c = new stade(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new station_de_television(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new centre_commercial(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new restaurant(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new Cafe(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new boutique_de_fruits(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new usine_de_meubles(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new fromagerie(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new petite_boutique(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new boulangerie(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new verger(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new Mine(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new foret(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new ferme(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new mais(); this->deck.push_back(c); }

}
//港口拓展包
Deckgangkou::Deckgangkou()
{
    deck.clear();
	Cartes *c;
    for (int i = 0; i < 4; i++) { c = new hotel_de_ville(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new aeroport(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new port(); this->deck.push_back(c); }

    for (int i = 0; i < 4; i++) { c = new tour_de_tele() ; this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new parc_de_loisirs(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new marche(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new gare(); this->deck.push_back(c); }

    for (int i = 0; i < 4; i++) { c = new regie(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new maison_de_edition(); this->deck.push_back(c); }

    for (int i = 0; i < 4; i++) { c = new stade(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new station_de_television(); this->deck.push_back(c); }
    for (int i = 0; i < 4; i++) { c = new centre_commercial(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new sushis(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new pizza(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new hamburger(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new restaurant(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new Cafe(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new Marche_alimentaire(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new magasin_de_fleurs(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new boutique_de_fruits(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new usine_de_meubles(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new fromagerie(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new petite_boutique(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new boulangerie(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new Thonier(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new Bateau_maquereau(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new champ_de_fleurs(); this->deck.push_back(c); }

    for (int i = 0; i < 6; i++) { c = new verger(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new Mine(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new foret(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new ferme(); this->deck.push_back(c); }
    for (int i = 0; i < 6; i++) { c = new mais(); this->deck.push_back(c); }
}
