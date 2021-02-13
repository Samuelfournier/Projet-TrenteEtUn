/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : fenêtre qui permet la gestion de la fin de chaque round.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "hud.h"
#include "gameState.h"
#include "gameOverState.h"
#include "state.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class roundOverState : public state
{
private:
	gameDataRef _data;

	Sprite _background;
	player* _playerAI;
	player* _playerHumain;
	Text _winner;				//Le text pour afficher le gagnant de la round

	Clock _clock;

public:
	roundOverState(gameDataRef data, player* player[2]);	//constructeur de l'objet roundOverState
	~roundOverState();										//destructeur de l'objet roundOverState

	void init();				//methode qui initialise les proprietes de roundOverState								
	void handleInput();			//methode qui gere les inputs des joueurs
	void update(float dt);		//methode qui update l'objet roundOverState
	void draw(float dt)const;	//methode pour l'affichage des differentes proprietes du state									
};

