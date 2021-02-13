/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 D�cembre 2020
	Programme : Fen�tre gameOver qui affiche qui a gagner, et qui propose de rejouer pour renvoyer � la fen�tre mainMenu
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "hud.h"
#include "mainMenuState.h"
#include "state.hpp"
#include <iostream>
using namespace std;
using namespace sf;



class gameOverState : public state
{
private:
	gameDataRef _data;				//chaque state recevra le pointeur sur la gameData qui
									//donne acc�s au stateMachine, au RenderWindow, au
									//assertManager et au inputManager

	Sprite _background;				//le sprite pour la background
	Sprite _playButton;				//le sprite pour le bouton jouer
	int _winner;

	Text _winnerText;


public:
	gameOverState(gameDataRef data, int winner);	//constructeur par default
	~gameOverState();								//destructeur par default

	void init();									//initialise tous la fenetre
	void handleInput();								//S'occupe des clics dans l'ecran
	void update(float dt);							//ne fait rien pour cette fenetre
	void draw(float dt) const;						//draw la fenetre et tous ses sprites
};
