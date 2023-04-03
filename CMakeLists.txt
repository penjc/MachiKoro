cmake_minimum_required(VERSION 3.24)
project(MachiKoro)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp Banque.cpp Banque.h Cartes_bleu.cpp Cartes_bleu.h Cartes.cpp Cartes.h ColorAndIcon.h
        Deck.cpp  Deck.h Jeu.cpp Jeu.h Cartes_vert.cpp Cartes_vert.h MachiKoro.cpp Cartes_violet.cpp
        Cartes_violet.h Cartes_rouge.cpp Cartes_rouge.h Cartes_jaune.cpp Cartes_jaune.h singleton.h)