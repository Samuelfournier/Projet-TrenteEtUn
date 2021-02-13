/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de l'object hud
*/
#include "hud.h"

//constructeur par default
hud::hud(gameDataRef data) :_data(data)
{
	_lifeText.setFont(_data->assets.getFont("arial font"));				//Set tout les parametres du text
	_lifeText.setString("0");
	_lifeText.setCharacterSize(100);
	_lifeText.setFillColor(Color::Black);
	_lifeText.setOrigin(_lifeText.getGlobalBounds().width / 2,
		_lifeText.getGlobalBounds().height / 2);

	//l’image du texte sera centré sur l’écran grâce au point d’origine au milieu de l’image
	_lifeText.setPosition(_data->window.getSize().x / 2, (_data->window.getSize().y / 5) + 400);
}

//Update le nombre de vie
void hud::updateLife(int score)
{
	_lifeText.setString(to_string(score));
}

//draw le nombre de vie
void hud::draw() const
{
	_data->window.draw(_lifeText);
}