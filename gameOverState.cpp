/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de gameOverState
*/
#include "gameOverState.h"


//le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
gameOverState::gameOverState(gameDataRef data, int winner) : _data(data), _winner(winner)
{

}

//destructeur par default
gameOverState::~gameOverState()
{

}

//load l’image du background et tous les sprites/text associer a cette fenetre
void gameOverState::init()
{
	//load la texture pour le background
	_background.setTexture(_data->assets.getTexture("logo main menu background"));

	//load la texture pour le play button et le positionne dans la fenetre
	_playButton.setTexture(_data->assets.getTexture("play button"));
	_playButton.setTexture(_data->assets.getTexture("play button"));
	_playButton.setPosition((SCREEN_WIDTH / 2) - _playButton.getGlobalBounds().width / 2,
		(SCREEN_HEIGHT / 2) -
		_playButton.getGlobalBounds().height / 2);


	_winnerText.setFont(_data->assets.getFont("arial font")); //Set tout les parametres du text

	if (_winner == 0)
		_winnerText.setString("Vous avez perdu la partie !");
	else
		_winnerText.setString("Vous avez gagné la partie !");

	_winnerText.setCharacterSize(45);
	_winnerText.setFillColor(Color::White);
	_winnerText.setOrigin(_winnerText.getGlobalBounds().width / 2, _winnerText.getGlobalBounds().height / 2);
	_winnerText.setPosition((_data->window.getSize().x / 2), (_data->window.getSize().y / 2) - (_winnerText.getGlobalBounds().height / 2) - 200);

}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameOverState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();

		else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window)) {
			//retourne au main menu
			_data->machine.addState(stateRef(new mainMenuState(_data)), true);
		}
	}
}

//ne fait rien pour cette fenetre
void gameOverState::update(float dt)
{

}

//clear, dessine le background et display la fenêtre avec tous ses sprites
void gameOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_playButton);
	_data->window.draw(_winnerText);
	_data->window.display();
}

