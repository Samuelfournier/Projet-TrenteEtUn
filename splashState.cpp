/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 D�cembre 2020
	Programme : d�finition des m�thode de splash state
*/
#include "splashState.h"

//le constructeur utilise les : pour initialiser _data avant m�me l�ex�cution du contenu{}
splashState::splashState(gameDataRef data) : _data(data)
{
}
//load l�image du background � l�aide du assetManager ds _data et la set au Sprite
void splashState::init()
{
	_data->assets.loadTexture("logo state background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("logo state background"));
}
//fen�tre qui reste ouverte tant qu�elle n�est pas ferm�e
void splashState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
	}
}
//g�re le d�lai, apr�s 3 secondes, on veut afficher la prochaine fen�tre
void splashState::update(float dt)
{
	float currentTime = _clock.getElapsedTime().asSeconds();
	if (currentTime > LOGO_STATE_SHOW_TIME)
	{
		//todo call the menu state
		_data->machine.addState(stateRef(new mainMenuState(_data)), true);
	}
}
//clear, dessine le background et display la fen�tre
void splashState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}
