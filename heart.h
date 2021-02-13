/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui s'occupe de draw les coeurs à la bonne place pour chaque joueur
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
using namespace sf;


class heart
{
private:
	gameDataRef _data;
	Sprite  _hearts;						//Le sprite du coeur

public:
	heart(gameDataRef data);				//constructeur par default
	void draw(int nbHearts);				//draw les coeurs en bas de la fenetre
	void drawOpposite(int nbHearts);		//draw les coeurs en haut de la fenetre

};

