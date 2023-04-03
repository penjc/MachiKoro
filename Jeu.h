#pragma once
#include <vector>
#include "Cartes.h"
#include "Banque.h"
#include "Deck.h"
#include "Singleton.h"

using namespace std;

class Joueur {
public:
	string nom;
	Banque *banque;
	vector<Cartes_bleu*> Cartes_bleu;
	vector<Cartes_vert*> Cartes_vert;
	vector<Cartes_rouge*> Cartes_rouge;
	vector<Cartes_violet*> Cartes_violet;
	vector<Cartes_jaune*> Cartes_jaune;
};

class Jeu :public Singleton<Jeu>{
public:
    friend Singleton<Jeu>;
	int version;
	int turn;
	bool gameover;
	void deal();
	Deck* get_deck();
	vector<vector<Cartes *>> get_slot();
	vector<Joueur*> players;
	void create_player(string name);
	void rolldice();
	void red_card_check();
	void blue_card_check();
	void green_card_check();
	void purple_card_check();
	void buy_property();
	void end_of_turn();
	void view_slot_cards(bool cls);
	void view_player_cards(int index, bool cls);
private:
    Jeu();
    Jeu(const Jeu&);
    Jeu& operator=(const Jeu&);
	int dice;
	int dice1;
	int dice2;
	void rolling_dice(int dice_count);
	int player_input(string message);
	vector<vector<Cartes *>> slot;
	int slot_count;
	Deck *d;
    int player_number=0;
    int ai_number=0;
};