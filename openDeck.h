/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet la gestion du paquet de carte ouvert sur la table.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <stack>
#include "deckOfCards.h"
#include "game.h"
using namespace sf;

class openDeck
{
private:
	gameDataRef _data;
	stack<card> _openDeck;

public:

	openDeck(gameDataRef data);
	void addCard(const card& c);		//ajoute 1 carte au paquet
	card removeCard();		
	card getTopCard();					//retire et retourne la carte enlever
	Sprite getTopCardSprite();
	void draw();						//draw le top du paquet
};

