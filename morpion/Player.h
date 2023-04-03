//
// Created by johstar on 19/03/23.
//

#ifndef MORPION_PLAYER_H
#define MORPION_PLAYER_H

#include <iostream>
#include "Symbole.h"
#include "Plateau.h"

using namespace std;


class Player {

public:
    Player();
    Player(string name, Symbole symbole);
    Player(Player &player);

    string getName() const;
    Symbole getSymbole() const;

    void setName(string name);
    void setSymbole(Symbole symbole);
    void afficherPlayer();
    void debutDeJeu();
    void tourDeJeu(Plateau *plateau);
    void victoire(Plateau *plateau);

private:
    string name;
    Symbole symbole;

};

inline void Player::setName(string name)
{
    this->name = name;
}

inline void Player::setSymbole(Symbole symbole)
{
    this->symbole = symbole;
}
#endif //MORPION_PLAYER_H
