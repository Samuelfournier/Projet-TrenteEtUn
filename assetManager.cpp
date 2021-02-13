/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes de l'objet assetManager
*/
#include "assetManager.h"

//loald la texture et la met dans la map
void assetManager::loadTexture(string name, string fileName)
{
	Texture tex;
	if (tex.loadFromFile(fileName)) {
		_textures[name] = tex;
	}
}

//retourne la texture de la map correspondant au nom reçu
Texture& assetManager::getTexture(string name)
{
	return _textures.at(name);
}

//loald le font et la met dans la map
void assetManager::loadFont(string name, string fileName)
{
	Font font;
	if (font.loadFromFile(fileName)) {
		_fonts[name] = font;
	}
}

//retourne le font de la map correspondant au nom reçu
Font& assetManager::getFont(string name)
{
	return _fonts.at(name);
}
