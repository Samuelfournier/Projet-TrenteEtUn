#pragma once

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 857


#define LOGO_STATE_SHOW_TIME 3.0
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/img/splashArt.png"


#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/img/background4.png"
#define PLAY_BUTTON_FILEPATH "Resources/img/PlayButton.png"
#define GAME_TITLE_FILEPATH "Resources/img/31.png"
#define PLUS_SIGN_FILEPATH "Resources/img/plusSign.png"
#define MINUS_SIGN_FILEPATH "Resources/img/minusSign.png"

#define ARIAL_FONT_FILEPATH "Resources/fonts/arial.ttf"
#define CARDS_FILEPATH "Resources/img/Cards/"
#define PNG	".png"
#define BACK_OF_CARD_FILEPATH "Resources/img/Cards/cardBack_red4.png"

#define HEARTS_FILEPATH "Resources/img/heart pixel art 48x48.png"
#define KNOCK_BUTTON_FILEPATH "Resources/img/green-button.png"

#define KNOCK_SOUND_FILEPATH "Resources/sounds/knock.ogg"
#define CARD_SOUND_FILEPATH "Resources/sounds/cardSlide2.ogg"

#define TIME_BEFORE_END_ROUND 2.0f 
#define TIME_BEFORE_NEXT_ROUND 5.0f
#define SHOW_LAST_ROUND 5.0f


enum cardType { 
	spades, hearts, diamonds, clubs 
};

enum gameStates {
	playing,
	roundEnd,
	gameOver
};

