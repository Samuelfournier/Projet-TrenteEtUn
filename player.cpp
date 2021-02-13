#include "player.h"

//constructeur par default
player::player(gameDataRef data) : _data(data)
{
	_nbLife = 0;
}

//ajoute 1 carte au paquet
void player::addCard(const card& c)
{
	_hand.push_back(c);
}

//retire et retourne la carte enlever
card player::removeCard(int index)
{
	card temp = _hand[index];
	vector<card>::iterator it = _hand.begin() + index;
	_hand.erase(it);
	return temp;
}

//vide la main du joueur
void player::clearHand()
{
	vector<card>::iterator it = _hand.begin();

	for (int i = 0; i < _hand.size(); i++) {
		it = _hand.erase(it);
	}
}

//draw la main du joueur
void player::draw(int offsetX, int offsetY)
{
	int spaceBetweenCard = 150;

	for (int i = 0; i < _hand.size(); i++) {
		_hand[i].spriteCard.setPosition(((SCREEN_WIDTH / 2) - _hand[i].spriteCard.getGlobalBounds().width / 2) - 150 + (i * spaceBetweenCard) + offsetX, offsetY);
		_data->window.draw(_hand[i].spriteCard);
	}
}

//draw la main cache du AI
void player::drawHidden(int offsetX, int offsetY)
{
	int spaceBetweenCard = 150;

	card temp(_data->assets.getTexture("back of card"), 0, spades);

	for (int i = 0; i < _hand.size(); i++) {
		_hand[i].spriteCard.setPosition(((SCREEN_WIDTH / 2) - _hand[i].spriteCard.getGlobalBounds().width / 2) - 150 + (i * spaceBetweenCard) + offsetX, offsetY);
		_data->window.draw(_hand[i].spriteCard);
	}

	for (int i = 0; i < _hand.size(); i++) {
		temp.spriteCard.setPosition(((SCREEN_WIDTH / 2) - temp.spriteCard.getGlobalBounds().width / 2) - 150 + (i * spaceBetweenCard) + offsetX, offsetY);
		_data->window.draw(temp.spriteCard);
	}
}

//retourne le sprite de la premiere carte
Sprite player::getFirstCard()const
{
	return _hand[0].spriteCard;
}

//retourne le sprite de la deuxieme carte
Sprite player::getSecondCard()const
{
	return _hand[1].spriteCard;
}

//retourne le sprite de la troisieme carte
Sprite player::getThirdCard()const
{
	return _hand[2].spriteCard;
}

Sprite player::getFourthCard() const
{
	return _hand[3].spriteCard;
}

void player::setScore(int score)
{
	_score = score;
}

int player::getScore() const
{
	return _score;
}

vector<card> player::getHand()const
{
	return _hand;
}
card player::getCard(int i)const
{
	return _hand[i];
}


//diminue de 1 le nombre de vie
void player::dropLife()
{
	_nbLife--;
}

//set le nombre de vie
void player::setLife(int life)
{
	_nbLife = life;
}

//retourne le nombre de vie
int player::getLife()const
{
	return _nbLife;
}
