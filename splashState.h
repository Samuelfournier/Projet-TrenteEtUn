/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet l'affichage de splashSate.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "mainMenuState.h"
#include "state.hpp"
using namespace sf;

//chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
//un init, update, draw et handleInput différent pour chaque fenêtre.

class splashState : public state
{
private:

	gameDataRef _data;				//chaque state recevra le pointeur sur la gameData qui
									//donne accès au stateMachine, au RenderWindow, au
									//assertManager et au inputManager

	Clock _clock;					//1re fenêtre a besoin d’une clock car elle disparait
									//au bout de quelques secondes

	Sprite _background;				//le sprite pour la background

public:
	splashState(gameDataRef data);	//constructeur par default

	void init();					//initialise la fenetre
	void handleInput();				//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
	void update(float dt);			//change de fenetre apres 3 secondes
	void draw(float dt) const;		//draw le splashstate
};

