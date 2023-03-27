//
// Created by johstar on 19/03/23.
//

#include "Symbole.h"
#include <iostream>

using namespace std;

Symbole::Symbole(): charactere('O'), position(0,0){}

Symbole::Symbole(const Symbole &symbole): charactere(symbole.charactere), position(symbole.position) {}

Symbole::Symbole(char charactere, Position position): charactere(charactere), position(position) {}

char Symbole::getCharactere() const
{
    return this->charactere;
}

Position Symbole::getPosition() const
{
    return this->position;
}

void Symbole::afficherSymbole() const
{
    cout << this->charactere << "en (" << this->position.getX() << ";" << this->position.getY() << ")" <<endl;
}

