/*
	Auteur : Samuel Fournier, Olivier Vigneault, William Goupil
	Date : 18 D�cembre 2020
	Programme : Object qui permet la gestion de tous les autres states.
*/
#pragma once
#include <memory>
#include <stack>
#include "state.hpp"
using namespace std;

typedef unique_ptr<state> stateRef;				//un smartPointer de state

class stateMachine {
private:
	stack<stateRef> _states;				//pile de pointeur pour empiler les fen�tres du jeu
	stateRef _newState;						//la fen�tre active
	bool _isRemoving;						//flag pour savoir ce qui se passe ds la fen�tre
	bool _isAdding;
	bool _isReplacing;
public:
	void addState(stateRef newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();
	stateRef& getActiveState();				//pas de const pour ce getteur, car il est setteur aussi
};

