//
// Created by johstar on 19/03/23.
//

#include "Position.h"
#include <iostream>

using namespace std;

Position::Position(): _x(0), _y(0) {} //Implémentation constructeur par défaut

Position::Position(const Position &position): _x(position._x), _y(position._y) {} //Implémentation constructeur par copie

Position::Position(int x, int y): _x(x), _y(y) {} //Implémntation constructeur par parametre

int Position::getX() const
{
    return this -> _x; //Le suffixe const sert à dire qu'il s'agit d'un accesseur
}

int Position::getY() const
{
    return this-> _y;
}

void Position::afficherPosition() const {
    cout << "(" << this-> _x << ";" << this-> _y << ")" << endl;
}

