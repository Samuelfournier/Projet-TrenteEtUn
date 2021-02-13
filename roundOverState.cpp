/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de l'object roundOverState
*/
#include "roundOverState.h"

//constructeur de l'objet roundOverState
roundOverState::roundOverState(gameDataRef data, player* player[2]) : _data(data), _playerAI(player[0]), _playerHumain(player[1])
{

}

//destructeur de l'objet roundOverState
roundOverState::~roundOverState()
{
		delete _playerAI;
		delete _playerHumain;
}

//methode init du roundOverState
void roundOverState::init()
{
	// Set le background a la bonne image
	_background.setTexture(_data->assets.getTexture("logo main menu background"));

	//modification des parametres de la propriete Text _winner qui 
	//affiche si le joueur humain a gagner, perdu ou si c'est une manche nulle

	_winner.setFont(_data->assets.getFont("arial font"));

	if(_playerAI->getScore() > _playerHumain->getScore())
		_winner.setString("Vous avez perdu cette manche !");
	else if (_playerHumain->getScore() > _playerAI->getScore())
		_winner.setString("Vous avez gagné cette manche !");
	else
		_winner.setString("Manche nulle !");

	_winner.setCharacterSize(45);
	_winner.setFillColor(Color::White);
	_winner.setOrigin(_winner.getGlobalBounds().width / 2, _winner.getGlobalBounds().height / 2);
	_winner.setPosition((_data->window.getSize().x / 2), (_data->window.getSize().y / 2) - (_winner.getGlobalBounds().height / 2));
}

//methode qui gere les inputs des joueurs
void roundOverState::handleInput()
{

}

//methode qui update l'objet roundOverState
void roundOverState::update(float dt)
{
	//si le delai est depasser on commence une nouvelle manche ou on termine la partie (gameOverState)
	if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_NEXT_ROUND)
	{
		//si les 2 joueurs sont encore en vie
		if (_playerAI->getLife() > 0 && _playerHumain->getLife() > 0)
			_data->machine.addState(stateRef(new gameState(_data, _playerAI->getLife(), _playerHumain->getLife())), true);
		//si l'AI n'a plus de vie
		else if (_playerAI->getLife() == 0)
			_data->machine.addState(stateRef(new gameOverState(_data, 1)), true);
		//si le joueur humain n'a plus de vue
		else 
			_data->machine.addState(stateRef(new gameOverState(_data, 0)), true);
	}
}

//methode pour l'affichage des differentes proprietes du state
void roundOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_winner);
	_playerAI->draw(0, 110);
	_playerHumain->draw(0, SCREEN_HEIGHT - 300);
	_data->window.display();
}
