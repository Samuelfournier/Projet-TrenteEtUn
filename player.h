/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet la gestion des joueurs(humain et AI).
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <iostream>
#include <vector>
#include "deckOfCards.h"
#include "game.h"
using namespace sf;


class player
{
private:
	gameDataRef _data;
	vector<card> _hand;					//La main du joueur contenant les 3 cartes
	int _nbLife;						//Le nombre de vie du joueur
	int _score;

public:
	player(gameDataRef data);			//constructeur par default

	void addCard(const card& c);		//ajoute 1 carte au paquet
	card removeCard(int index);			//retire et retourne la carte enlever
	void clearHand();					//vide la main du joueur
	void draw(int offsetX, int offsetY);		//draw la main ouverte du joueur
	void drawHidden(int offsetX, int offsetY);	//draw la main cache du joueur

	Sprite getFirstCard()const;			//retourne le sprite de la premiere carte
	Sprite getSecondCard()const;		//retourne le sprite de la deuxieme carte
	Sprite getThirdCard()const;			//retourne le sprite de la troisieme carte
	Sprite getFourthCard()const;		//retourne le sprite de la quatrieme carte

	void setScore(int score);
	int getScore() const;

	vector<card> getHand()const;
	card getCard(int i)const;

	void dropLife();					//diminue de 1 le nombre de vie
	void setLife(int life);				//set le nombre de vie
	int getLife()const;					//retourne le nombre de vie
};

