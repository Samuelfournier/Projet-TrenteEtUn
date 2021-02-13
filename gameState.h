/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Fenêtre game qui gère l'intégralité de la partie.(tour, roud, envoie vers gameOverState, etc.)
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <queue>
#include <stack>
#include "game.h"
#include "state.hpp"
#include "player.h"
#include "deckOfCards.h"
#include <SFML/Audio.hpp>
#include "heart.h"
#include "openDeck.h"
#include "roundOverState.h"
#include "hud.h"
#include "analyzer.h"
using namespace sf;


class gameState : public state
{
private:
	gameDataRef _data;				//chaque state recevra le pointeur sur la gameData qui
									//donne accès au stateMachine, au RenderWindow, au
									//assertManager et au inputManager

	Clock _clock;

	Sprite _background;				//le sprite pour la background
	Sprite _closeDeckSprite;		//le sprite pour le paquet de carte fermer
	Sprite _knockButton;			//le sprite pour le bouton qui permet de cogner sur la table
	Text _knockText;				//Le text pour le knock button
	Text _lastTurnText;				//le text pour mentionner que c'est le dernier tour de la manche

	int _nbLifeJ1;					//le nombre de vie
	int _nbLifeJ2;
	int _tour;
	bool _lastTurn;
	int _gameState;
	
	deckOfCards* _deck;				//Paquet de carte
	player* _player[2];				//les deux joueurs
	stack<card> _closeDeck;			//pile pour le paquet fermer
	heart* _hearts[2];				//coeur pour les 2 joueurs
	openDeck* _openDeck;			//pile pour le paquet ouvert
	analyzer* _analyzer;


	SoundBuffer _knockSoundBuffer;
	SoundBuffer _cardSoundBuffer;

	Sound _knockSound;
	Sound _cardSound;

public:
	gameState(gameDataRef data, int nbLifeJoueur1, int nbLifeJoueur2);	//constructeur par default
	~gameState();														//destructeur par default

	void init();											//Initialise tous la game
	void handleInput();										//s'occupe des clics pour faire avancer la game
	void playerTurn();
	void AITurn();
	void update(float dt);									
	void draw(float dt)const;									//draw toute la partie
};

