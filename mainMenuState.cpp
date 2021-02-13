/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de l'object mainMenuState
*/
#include "mainMenuState.h"


//le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
mainMenuState::mainMenuState(gameDataRef data) : _data(data)
{
	_hud = nullptr;
	_nbLife = 3;
}

//destructeur par default
mainMenuState::~mainMenuState()
{
	delete _hud;
}

//load l’image du background et tous les sprites/text associer a cette fenetre
void mainMenuState::init()
{
	//load la texture pour le background
	_data->assets.loadTexture("logo main menu background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("logo main menu background"));

	//load la texture pour le titre et le positionne dans la fenetre
	_data->assets.loadTexture("titre", GAME_TITLE_FILEPATH);
	_gameTitle.setTexture(_data->assets.getTexture("titre"));
	_gameTitle.setPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	_gameTitle.setOrigin(_gameTitle.getLocalBounds().width / 2.0f, (_gameTitle.getLocalBounds().height / 2.0f) + 250);
	
	//load la texture pour le play button et le positionne dans la fenetre
	_data->assets.loadTexture("play button", PLAY_BUTTON_FILEPATH);
	_playButton.setTexture(_data->assets.getTexture("play button"));
	_playButton.setTexture(_data->assets.getTexture("play button"));
	_playButton.setPosition((SCREEN_WIDTH / 2) - _playButton.getGlobalBounds().width / 2,
		(SCREEN_HEIGHT / 2) -
		_playButton.getGlobalBounds().height / 2);


	//load la texture pour le + sign et le positionne dans la fenetre
	_data->assets.loadTexture("+ sign", PLUS_SIGN_FILEPATH);
	_plusSign.setTexture(_data->assets.getTexture("+ sign"));
	_plusSign.setPosition(((SCREEN_WIDTH / 2) - _plusSign.getGlobalBounds().width / 2) + 175,
		((SCREEN_HEIGHT / 2) -
		_plusSign.getGlobalBounds().height / 2) + 125);

	//load la texture pour le - sign et le positionne dans la fenetre
	_data->assets.loadTexture("- sign", MINUS_SIGN_FILEPATH);
	_minusSign.setTexture(_data->assets.getTexture("- sign"));
	_minusSign.setPosition(((SCREEN_WIDTH / 2) - _minusSign.getGlobalBounds().width / 2) + 175,
		((SCREEN_HEIGHT / 2) -
			_minusSign.getGlobalBounds().height / 2) + 225);

	//load le font pour le text
	_data->assets.loadFont("arial font", ARIAL_FONT_FILEPATH);

	//déclaration du pointeur pour le text de vie
	_hud = new hud(_data);
	_hud->updateLife(_nbLife);

	//Set toute les caractéristiques pour le texte du nombre de vie et le positionne
	_nbLifeText.setFont(_data->assets.getFont("arial font"));
	_nbLifeText.setString("Nombre de vie : ");
	_nbLifeText.setCharacterSize(56);
	_nbLifeText.setFillColor(Color::Black);
	_nbLifeText.setOrigin(_nbLifeText.getGlobalBounds().width / 2,
		_nbLifeText.getGlobalBounds().height / 2);
	_nbLifeText.setPosition((_data->window.getSize().x / 2) - 225, (_data->window.getSize().y / 5) + 415);

}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void mainMenuState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();

		else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window)) {
			//create the new stage main screen
			_data->machine.addState(stateRef(new gameState(_data, _nbLife, _nbLife)), true);
		}

		//si on clique sur +
		else if (_data->input.isSpriteClicked(_plusSign, Mouse::Left, _data->window)) {
			//Augmente le nombre de vie
			if (_nbLife < 12)
			_nbLife++;
			_hud->updateLife(_nbLife);

		}

		//si on clique sur -
		else if (_data->input.isSpriteClicked(_minusSign, Mouse::Left, _data->window)) {
			//Augmente le nombre de vie
			if(_nbLife > 3)
				_nbLife--;
			_hud->updateLife(_nbLife);
		}
	}
}

//ne fait rien pour cette fenetre
void mainMenuState::update(float dt)
{
	
}

//clear, dessine le background et display la fenêtre avec tous ses sprites
void mainMenuState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_gameTitle);
	_data->window.draw(_playButton);
	_data->window.draw(_plusSign);
	_data->window.draw(_minusSign);
	_hud->draw();
	_data->window.draw(_nbLifeText);
	_data->window.display();
}
