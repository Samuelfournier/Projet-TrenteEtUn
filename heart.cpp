/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de heart.h
*/
#include "heart.h"

//constructeur par default
heart::heart(gameDataRef data) : _data(data)
{
	_hearts.setTexture(_data->assets.getTexture("hearts"));
	_hearts.setPosition((((SCREEN_WIDTH / 2) - _hearts.getGlobalBounds().width / 2) + 392),
		((SCREEN_HEIGHT / 2) -
			_hearts.getGlobalBounds().height / 2) + 392);
}

//draw les coeurs en bas de la fenetre
void heart::draw(int nbHearts)
{
	int spaceBetweenHearts = 70;
	for (int i = 0; i < nbHearts; i++) {
		
		_hearts.setPosition(((SCREEN_WIDTH / 2) - _hearts.getGlobalBounds().width / 2) + 392 - (i * spaceBetweenHearts),
			((SCREEN_HEIGHT / 2) -
				_hearts.getGlobalBounds().height / 2) + 392);
		_data->window.draw(_hearts);
	}
}

//draw les coeurs en haut de la fenetre
void heart::drawOpposite(int nbHearts)
{
	int spaceBetweenHearts = 70;
	for (int i = 0; i < nbHearts; i++) {

		_hearts.setPosition(((SCREEN_WIDTH / 2) - _hearts.getGlobalBounds().width / 2) + 392 - (i * spaceBetweenHearts),
			((SCREEN_HEIGHT / 2) -
				_hearts.getGlobalBounds().height / 2) - 392);
		_data->window.draw(_hearts);
	}
}
