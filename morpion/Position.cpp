//
// Created by johstar on 19/03/23.
//

#include "Position.h"
#include <iostream>

using namespace std;

Position::Position(): x(0), y(0) {} //Implémentation constructeur par défaut

Position::Position(const Position &position): x(position.x), y(position.y) {} //Implémentation constructeur par copie

Position::Position(int x, int y): x(x), y(y) {} //Implémntation constructeur par parametre

int Position::getX() const
{
    return this -> x; //Le suffixe const sert à dire qu'il s'agit d'un accesseur
}

int Position::getY() const
{
    return this->y;
}

void Position::afficherPosition() const {
    cout << "(" << this->x << ";" << this->y << ")" << endl;
}

