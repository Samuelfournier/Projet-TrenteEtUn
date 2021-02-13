/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet de simuler un paquet de carte, s'occupe de leur valeur, leur type et les images pour chaques carte. fonctionne avec une
				struct Card qui elle contient les valeurs, type et textures.
*/
#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <algorithm>
#include "game.h"
using namespace std;
using namespace sf;

//struct pour les cartes, contient leurs valeurs, leurs sprites et leurs types
struct card
{
	Sprite spriteCard;					
	int value;
	cardType type;

	card(const Texture& tx, int v, cardType t)			//constructeur de carte
	{
		spriteCard.setTexture(tx);
		value = v;
		type = t;
	}
};


class deckOfCards
{
private:
	gameDataRef _data;

	list<card> _deck;					//Liste pour le paquet de carte

public:

	deckOfCards(gameDataRef data);		//constructeur par default

	void shuffleCard();					//Mélange les cartes

	list<card>& getDeck();				//Retourne le paquet de cartes

};

