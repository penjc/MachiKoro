#pragma once
#include <vector>
#include <iostream>
#include "Cartes.h"
#include "Cartes_bleu.h"
#include "Cartes_vert.h"
#include "Cartes_rouge.h"
#include "Cartes_violet.h"
#include "Cartes_jaune.h"

using namespace std;

class Deck {
public:
	Deck();
	vector<Cartes*> deck;
};

class Deckgangkou:public Deck {
public:
    Deckgangkou();
};
