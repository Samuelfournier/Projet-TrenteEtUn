/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : fenêtre du menu orignial, permet de choisir le nombre de vie et de commencer la partie
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "hud.h"
#include "gameState.h"
#include "state.hpp"
#include <iostream>
using namespace std;
using namespace sf;



class mainMenuState : public state
{
private:
	gameDataRef _data;				//chaque state recevra le pointeur sur la gameData qui
									//donne accès au stateMachine, au RenderWindow, au
									//assertManager et au inputManager

	Sprite _background;				//le sprite pour la background
	Sprite _gameTitle;				//le sprite pour le titre
	Sprite _playButton;				//le sprite pour le bouton jouer
	Sprite _plusSign;				//Pour augmenter les vies
	Sprite _minusSign;				//pour diminuer les vies
		
	hud* _hud;						//Permet de choisir son nombre de vie avant
	int _nbLife;					//avant de commencer

	Text _nbLifeText;				//Texte du nombre de vie

public:
	mainMenuState(gameDataRef data);			//constructeur par default
	~mainMenuState();							//destructeur par default

	void init();								//initialise tous la fenetre
	void handleInput();							//S'occupe des clics dans l'ecran
	void update(float dt);						//ne fait rien pour cette fenetre
	void draw(float dt) const;					//draw la fenetre et tous ses sprites
};
