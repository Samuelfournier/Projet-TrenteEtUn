/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 D�cembre 2020
	Programme : Object qui permet l'affichage de splashSate.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "mainMenuState.h"
#include "state.hpp"
using namespace sf;

//chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
//un init, update, draw et handleInput diff�rent pour chaque fen�tre.

class splashState : public state
{
private:

	gameDataRef _data;				//chaque state recevra le pointeur sur la gameData qui
									//donne acc�s au stateMachine, au RenderWindow, au
									//assertManager et au inputManager

	Clock _clock;					//1re fen�tre a besoin d�une clock car elle disparait
									//au bout de quelques secondes

	Sprite _background;				//le sprite pour la background

public:
	splashState(gameDataRef data);	//constructeur par default

	void init();					//initialise la fenetre
	void handleInput();				//fen�tre qui reste ouverte tant qu�elle n�est pas ferm�e
	void update(float dt);			//change de fenetre apres 3 secondes
	void draw(float dt) const;		//draw le splashstate
};

