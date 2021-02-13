/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de l'object openDeck
*/
#include "openDeck.h"

openDeck::openDeck(gameDataRef data) : _data(data)
{

}

void openDeck::addCard(const card& c)
{
	_openDeck.push(c);
}

card openDeck::removeCard()
{
	card temp = _openDeck.top();
	_openDeck.pop();
	return temp;
}

card openDeck::getTopCard()
{
	return _openDeck.top();
}

Sprite openDeck::getTopCardSprite()
{
	return _openDeck.top().spriteCard;
}

void openDeck::draw()
{
	if (!_openDeck.empty()) {
		_openDeck.top().spriteCard.setPosition(((SCREEN_WIDTH / 2) - _openDeck.top().spriteCard.getGlobalBounds().width / 2) + 80,
			(SCREEN_HEIGHT / 2) -
			_openDeck.top().spriteCard.getGlobalBounds().height / 2);
		_data->window.draw(_openDeck.top().spriteCard);
	}
	
}
