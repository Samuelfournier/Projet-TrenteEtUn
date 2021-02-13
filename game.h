/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Object qui permet de faire fonctionner tout les autres states et fenêtres (main loop).
*/
#pragma once
#include <string>
#include <memory>
#include "state.hpp"
#include "stateMachine.h"
#include "assetManager.h"
#include "inputManager.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

struct gameData {
	stateMachine machine;
	RenderWindow window;
	assetManager assets;
	inputManager input;
};
typedef shared_ptr<gameData> gameDataRef;


class game
{
private:
	const float dt = 1.0f / 60.0f; //temps pour chaque frame (60 frames par sec.)
	Clock _clock;
	gameDataRef _data; //Le pointeur sur la struct gameData

public:
	game(int width, int height, string title);
	void run();
};

