/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 D�cembre 2020
	Programme : Object qui permet de g�rer les inputs joueurs
*/
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class inputManager
{
public:
	bool isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window);
	Vector2i getMousePosition(RenderWindow& window) const;
};

