/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui s'occupe de la gestion du nombre de vie choisi par le joueur au début de la partie et la change en temps réels.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
using namespace sf;


class hud
{
private:
	gameDataRef _data;
	Text _lifeText;							//Texte pour le nombre de vie
public:
	hud(gameDataRef data);					//constructeur par default
	void updateLife(int nbLife);			//Update le nombre de vie
	void draw()const;						//draw le nombre de vie

};

