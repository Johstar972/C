//
// Created by johstar on 19/03/23.
//

#ifndef MORPION_SYMBOLE_H
#define MORPION_SYMBOLE_H
#include "Position.h"

class Symbole {

public:
    //Constructeur par défaut
    Symbole();

    //Constructeur par copie
    Symbole(const Symbole &symbole);

    //Constructeur par paramètre
    Symbole(char charactere, Position position);

    //getter et setter
    char getCharactere() const;

    Position getPosition() const;

    void setCharactere(char charactere);

    void setPosition(Position position);

    //Autre methode
    void afficherSymbole() const;

private:
    char charactere;
    Position position;

};

inline void Symbole::setCharactere(char charactere)
{
    this->charactere = charactere;
}

inline void Symbole::setPosition(Position position)
{
    this->position = position;
}


#endif //MORPION_SYMBOLE_H
