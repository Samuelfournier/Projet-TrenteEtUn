/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de deckOfCards
*/
#include "deckOfCards.h"

//constructeur par default qui appel le init
deckOfCards::deckOfCards(gameDataRef data) : _data(data)
{

	string cardName[4] = { "cardClubs", "cardDiamonds", "cardHearts", "cardSpades" };
	string cardValue[13] = { "A","2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q","K" };
	int value[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };
	cardType typeCard[4] = { clubs,diamonds,hearts,spades };
		

	//Boucle 1 à 13, 4 fois.
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++) {	
			_deck.push_back(card(_data->assets.getTexture(cardName[i] + cardValue[j]), value[j], typeCard[i]));
		}

	shuffleCard();
}


//Mélange les cartes
void deckOfCards::shuffleCard()
{
	vector<card> v(_deck.begin(), _deck.end());
	random_shuffle(v.begin(), v.end());
	copy(v.begin(), v.end(), _deck.begin());
}

//Retourne le paquet de cartes
list<card>& deckOfCards::getDeck()
{
	return _deck;
}


