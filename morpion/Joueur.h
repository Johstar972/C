//
// Created by johstar on 19/03/23.
//

#ifndef MORPION_JOUEUR_H
#define MORPION_JOUEUR_H

#include <iostream>
#include "Symbole.h"
#include "Plateau.h"

using namespace std;


class Joueur {

public:
    Joueur();
    Joueur(string name, char symbole);
    Joueur(Joueur &joueur);

    string getName() const;
    char getSymbole() const;

    void setName(string name);
    void setSymbole(char symbole);
    void debutDeJeu();
    void tourDeJeu(Plateau *plateau, Symbole symbole);

private:
    string name;
    char symbole;

};

inline void Joueur::setName(string name)
{
    this->name = name;
}

inline void Joueur::setSymbole(char symbole)
{
    this->symbole = symbole;
}
#endif //MORPION_JOUEUR_H
