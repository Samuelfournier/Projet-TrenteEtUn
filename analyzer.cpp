/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 Décembre 2020
	Programme : Définition des méthodes d'analyzer
*/
#include "analyzer.h"
#include <algorithm>

using namespace std;

//methode qui analyse la main d'un joueur et retourne le score correspondant
int analyzer::getScore(const vector<card>& playerHand)
{
    int type = 0;
    int lastCardType = 0;

    //si les 3 cartes de la main du joueur sont identiques, score de 30 
    if ((playerHand[0].value + playerHand[1].value + playerHand[2].value) == (playerHand[0].value * 3)) {
       return 30;
    }
       
    
    //si un type de carte est dominant (2 cartes de meme type dans la main), on met la valeur associer a ce type dans une variable
    if (playerHand[0].type == playerHand[1].type || playerHand[0].type == playerHand[2].type)
    {
        type = playerHand[0].type;
    }
    else if (playerHand[1].type == playerHand[2].type)
    {
        type = playerHand[1].type;
    }
    //sinon aucun type de carte n'est dominant donc on choisi la carte qui possede la valeur la plus haute
    else
    {
        int tab[] = { playerHand[0].value, playerHand[1].value, playerHand[2].value };
        int maxValue = 0;

        for (int i = 0; i < 3; i++)
        {
            if (maxValue < tab[i])
                maxValue = tab[i];
        }

        return maxValue;
    }

    int score = 0;

    for (int i = 0; i < 3; i++)
    {
        //on additionne la valeur des cartes possedant le meme type
        if (playerHand[i].type == type)
            score += playerHand[i].value;
    }

    return score;

}

//methode qui analyse 3 cartes distinctes et retourne le score auquel elles correspondent
int analyzer::getScore(const card card1, const card card2, const card card3)
{
    //on cree un vecteur de carte qui agira comme la main d'un joueur 
    //dans laquelle nous mettons les 3 cartes envoyes en parametre
    vector<card> playerHand;

    playerHand.push_back(card1);
    playerHand.push_back(card2);
    playerHand.push_back(card3);

    int type = 0;
    int lastCardType = 0;

    if (playerHand[0].value == playerHand[1].value == playerHand[2].value)
        return 30;

    if (playerHand[0].type == playerHand[1].type || playerHand[0].type == playerHand[2].type)
    {
        type = playerHand[0].type;
    }
    else if (playerHand[1].type == playerHand[2].type)
    {
        type = playerHand[1].type;
    }
    else
    {
        int tab[] = { playerHand[0].value, playerHand[1].value, playerHand[2].value };
        int maxValue = 0;

        for (int i = 0; i < 3; i++)
        {
            if (maxValue < tab[i])
                maxValue = tab[i];
        }

        return maxValue;
    }

    int score = 0;

    for (int i = 0; i < 3; i++)
    {
        if (playerHand[i].type == type)
            score += playerHand[i].value;
    }

    return score;

}
