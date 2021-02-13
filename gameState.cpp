/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : définition des méthode de gameState
	*/
#include "gameState.h"


//le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
gameState::gameState(gameDataRef data, int nbLifeJoueur1, int nbLifeJoueur2) : _data(data), _nbLifeJ1(nbLifeJoueur1), _nbLifeJ2(nbLifeJoueur2)
{
	_deck = nullptr;
	_openDeck = nullptr;
	_analyzer = nullptr;

	for (int i = 0; i < 2; i++) {
		_player[i] = nullptr;
		_hearts[i] = nullptr;
	}

	//on set le nb de tour a 0 lorsqu'on commence une partie
	_tour = 0;
	//on set le dernier tour de la manche a false
	_lastTurn = false;
	//on set le gameState a playing
	_gameState = playing;

	string cardName[4] = { "cardClubs", "cardDiamonds", "cardHearts", "cardSpades" };
	string cardValue[13] = { "A","2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q","K" };

	//Load toute les textures de cartes avec les bon noms, utilise les 2 tableaux ci-dessus pour les bons noms
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			_data->assets.loadTexture(cardName[i] + cardValue[j], CARDS_FILEPATH + cardName[i] + cardValue[j] + PNG);
		}
	}
	_data->assets.loadTexture("back of card", BACK_OF_CARD_FILEPATH);
	_data->assets.loadTexture("hearts", HEARTS_FILEPATH);
	_data->assets.loadTexture("knock button", KNOCK_BUTTON_FILEPATH);
	


}

//destructeur
gameState::~gameState()
{
	delete _deck;
	delete _openDeck;
	delete _analyzer;
	for (int i = 0; i < 2; i++) {
		delete _player[i];
		delete _hearts[i];
	}

	//on set le nb de tour a 0 lorsqu'on commence une partie
	_tour = 0;
	//on set le dernier tour de la manche a false
	_lastTurn = false;
	//on set le gameState a playing
	_gameState = gameOver;
}

//load l’image du background à l’aide du assetManager ds _data et la set au Sprite
void gameState::init()
{
	//Set le background a la bonne image
	_background.setTexture(_data->assets.getTexture("logo main menu background"));
	_knockButton.setTexture(_data->assets.getTexture("knock button"));

	_knockButton.setPosition(((SCREEN_WIDTH / 2) - _knockButton.getGlobalBounds().width / 2) - 395,
		((SCREEN_HEIGHT / 2) -
		_knockButton.getGlobalBounds().height / 2) + 320);

	_knockText.setFont(_data->assets.getFont("arial font"));				//Set tout les parametres du text
	_knockText.setString("Knock");
	_knockText.setCharacterSize(30);
	_knockText.setFillColor(Color::Black);
	_knockText.setOrigin(_knockText.getGlobalBounds().width / 2,
		_knockText.getGlobalBounds().height / 2);
	_knockText.setPosition((_data->window.getSize().x / 2) - 388, (_data->window.getSize().y / 5) + 520);

	_lastTurnText.setFont(_data->assets.getFont("arial font"));
	_lastTurnText.setString("Dernier tour !");
	_lastTurnText.setCharacterSize(30);
	_lastTurnText.setFillColor(Color::Black);
	_lastTurnText.setPosition((_data->window.getSize().x / 2) - 375, (_data->window.getSize().y / 2) - (_lastTurnText.getGlobalBounds().height / 2));
	

	//initialisation de tout les pointeurs
	_deck = new deckOfCards(_data);
	_player[0] = new player(_data);
	_player[1] = new player(_data);
	_hearts[0] = new heart(_data);
	_hearts[1] = new heart(_data);
	_openDeck = new openDeck(_data);
	_analyzer = new analyzer();

	//donne le bon nombre de vie choisis en fonction du parametre recu
		_player[0]->setLife(_nbLifeJ1);
		_player[1]->setLife(_nbLifeJ2);

	list<card>::iterator it = _deck->getDeck().begin();

	//Distribue les cartes au joueur et a l'AI
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
			_player[0]->addCard(*it);
		else
			_player[1]->addCard(*it);
		it++;
	}

	//remplis le paquet de carte fermer
	for (int i = 0; i < 45; i++) {
		_closeDeck.push(*it);
		it++;
	}
	_openDeck->addCard(*it);						//place 1 cartes dans le paquet ouvert
	

	//applique la texture de la carte retourner et place le paquet en millieu de jeux
	_closeDeckSprite.setTexture(_data->assets.getTexture("back of card"));
	_closeDeckSprite.setPosition(((SCREEN_WIDTH / 2) - _closeDeckSprite.getGlobalBounds().width / 2) - 75,
		(SCREEN_HEIGHT / 2) -
		_closeDeckSprite.getGlobalBounds().height / 2);


	if (!_knockSoundBuffer.loadFromFile(KNOCK_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	if (!_cardSoundBuffer.loadFromFile(CARD_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}

	_knockSound.setBuffer(_knockSoundBuffer);
	_cardSound.setBuffer(_cardSoundBuffer);

}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameState::handleInput()
{
	Event event;

	while (_data->window.pollEvent(event))
	{
			if (event.type == Event::Closed)
				_data->window.close();

		
				if (_tour % 2 == 0)
				{
					playerTurn();
				}
				else if (_tour % 2 != 0)
				{
					AITurn();
				}
	}
}

void gameState::playerTurn()
{

	if (_data->input.isSpriteClicked(_closeDeckSprite, Mouse::Left, _data->window))
	{
		_cardSound.play();
		_player[1]->addCard(_closeDeck.top());			//ajoute la carte au joueur
		_closeDeck.pop();								//enleve la carte du paquer fermer
		draw(0);										//draw le jeu
		Event e;

		//Tant que le joueur n'a pas refait un clic pour le jeter une carte
		while (_data->window.waitEvent(e))
		{
			//si un clic sur la premiere carte on la jete dans le paquet ouvert
			if (_data->input.isSpriteClicked(_player[1]->getFirstCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(0));
				break;
			}

			//si un clic sur la deuxieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getSecondCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(1));
				break;
			}

			//si un clic sur la troisieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getThirdCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(2));
				break;
			}

			//si un clic sur la quatrieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getFourthCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(3));
				break;
			}

		}
		if (_lastTurn)
			_gameState = gameStates::roundEnd;
		_tour++;
	}

	//si un clic sur le paquet ouvert
	else if (_data->input.isSpriteClicked(_openDeck->getTopCardSprite(), Mouse::Left, _data->window))
	{
		_cardSound.play();
		_player[1]->addCard(_openDeck->removeCard());			//ajoute la carte du paquet ouvert et l'enleve en meme temps du paquet ouvert
		draw(0);
		Event e;


		//Tant que le joueur n'a pas refait un clic pour le jeter une carte
		while (_data->window.waitEvent(e))
		{
			//si un clic sur la premiere carte on la jete dans le paquet ouvert
			if (_data->input.isSpriteClicked(_player[1]->getFirstCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(0));
				break;
			}

			//si un clic sur la deuxieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getSecondCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(1));
				break;
			}

			//si un clic sur la troisieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getThirdCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(2));
				break;
			}

			//si un clic sur la quatrieme carte on la jete dans le paquet ouvert
			else if (_data->input.isSpriteClicked(_player[1]->getFourthCard(), Mouse::Left, _data->window))
			{
				_cardSound.play();
				_openDeck->addCard(_player[1]->removeCard(3));
				break;
			}

		}
		if (_lastTurn)
			_gameState = gameStates::roundEnd;
		_tour++;
	}

	else if (_data->input.isSpriteClicked(_knockButton, Mouse::Left, _data->window))
	{
		_knockSound.play();
		_lastTurn = true;
		_tour++;
	}
}

void gameState::AITurn()
{
	int scoreInit = _analyzer->getScore(_player[0]->getHand());
	int indiceCard = 0;
	bool selectedDeck = false;


	//si score plus elever ou egal a 23 AI knock
	if (scoreInit >= 23)
	{
		if (!_lastTurn)
		{
			_knockSound.play();
			_lastTurn = true;
		}
		else
		{
			_gameState = gameStates::roundEnd;
		}
		_tour++;
		return;
	}
	//test de combinaison 1
	int firstScore = _analyzer->getScore(_player[0]->getCard(0), _player[0]->getCard(1), _openDeck->getTopCard());

	if (firstScore > scoreInit)
	{
		indiceCard = 2;
		selectedDeck = true;
	}
		
	//test de combinaison 2
	int secondScore = _analyzer->getScore(_player[0]->getCard(2), _player[0]->getCard(0), _openDeck->getTopCard());

	if (secondScore > scoreInit && secondScore > firstScore)
	{
		indiceCard = 1;
		selectedDeck = true;	
	}
		
	//test de combinaison 3
	int thirdScore = _analyzer->getScore(_player[0]->getCard(1), _player[0]->getCard(2), _openDeck->getTopCard());


	if (thirdScore > scoreInit && thirdScore > firstScore && thirdScore > secondScore)
	{
		indiceCard = 0;
		selectedDeck = true;
	}

	//si une de combinaison est plus grande que le score init prendre la bonne carte
	if(selectedDeck)
	{
		_player[0]->addCard(_openDeck->removeCard());

		sleep(milliseconds(1500));
		_cardSound.play();
		draw(0);
		sleep(milliseconds(2000));
	}

	//sinon regarder deck fermer
	else
	{
		_player[0]->addCard(_closeDeck.top());
		_closeDeck.pop();

		sleep(milliseconds(1500));
		_cardSound.play();
		draw(0);
		sleep(milliseconds(2000));

		//test de combinaison 1
		firstScore = _analyzer->getScore(_player[0]->getCard(0), _player[0]->getCard(1), _player[0]->getCard(3));

		if (firstScore > scoreInit)
			indiceCard = 2;

		//test de combinaison 2
		secondScore = _analyzer->getScore(_player[0]->getCard(2), _player[0]->getCard(1), _player[0]->getCard(3));

		if (secondScore > scoreInit && secondScore > firstScore)
			indiceCard = 0;

		//test de combinaison 3
		thirdScore = _analyzer->getScore(_player[0]->getCard(0), _player[0]->getCard(2), _player[0]->getCard(3));

		if (thirdScore > scoreInit && thirdScore > firstScore && thirdScore > secondScore)
			indiceCard = 1;

		//si aucune combinaison est plus grande que la combinaison init choisir la carte ajouter
		if (scoreInit > firstScore && scoreInit > secondScore && scoreInit > thirdScore)
			indiceCard = 3;
	}

	//supprimer la carte qui donne le plus petit score
	_cardSound.play();
	_openDeck->addCard(_player[0]->removeCard(indiceCard));

	if (_lastTurn)
		_gameState = gameStates::roundEnd;

	_tour++;

}



void gameState::update(float dt)
{
	

	if (_gameState == gameStates::roundEnd)
	{
		_player[0]->setScore(_analyzer->getScore(_player[0]->getHand()));
		_player[1]->setScore(_analyzer->getScore(_player[1]->getHand()));

		if (_player[0]->getScore() > _player[1]->getScore())
			_player[1]->dropLife();
		else if (_player[1]->getScore() > _player[0]->getScore())
			_player[0]->dropLife();

		if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_END_ROUND)
		{
			_data->machine.addState(stateRef(new roundOverState(_data, _player)), true);
		}

		_gameState = playing;
	}

}

//clear, dessine le background et tous les elements et display la fenêtre
void gameState::draw(float dt)const 
{
	_data->window.clear();
	_data->window.draw(_background);
	_player[0]->drawHidden(0, 110);
	_player[1]->draw(0, SCREEN_HEIGHT - 300);
	_hearts[0]->drawOpposite(_player[0]->getLife());
	_hearts[1]->draw(_player[1]->getLife());
	_data->window.draw(_closeDeckSprite);
	_openDeck->draw();
	_data->window.draw(_knockButton);
	_data->window.draw(_knockText);

	if (_lastTurn)
	_data->window.draw(_lastTurnText);

	_data->window.display();
}


