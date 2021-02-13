/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet de calculer le score d'une main de carte selon leurs type et leurs valeur
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"
#include <vector>
#include "deckOfCards.h"

class analyzer
{
public:
	int getScore(const vector<card>& playerHand); //methode qui analyse la main d'un joueur et retourne le score correspondant
	int getScore(const card card1, const card card2, const card card3); //methode qui analyse 3 cartes distinctes et retourne le score auquel elles correspondent
};

