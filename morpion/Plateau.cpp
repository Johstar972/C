//
// Created by johstar on 19/03/23.
//

#include "Plateau.h"
#include <iostream>

using namespace std;

//Implémentation du constructeur par défaut
Plateau::Plateau()
{
    tableau = new char[TAILLE_TABLEAU];
    //La taille de mon vector est initialiser à null.
}

//Implémentation des getters
vector<Symbole> Plateau::getListeSymbole() const
{
    return this->listeSymbole;
}

char* Plateau::getTableau()
{
    return this->tableau;
}

//Implémentation de la méthode d'initialisation du tableau
void Plateau::initTableau() const
{
    for(int i = 0; i < TAILLE_TABLEAU; i++)
    {
        tableau[i] = ' ';
    }
}

//Implémentation de la methode d'affichage du tableau
void Plateau::afficherTableau() const
{
    for(int i = 0; i < TAILLE_TABLEAU; i++)
    {
        cout << "|" << tableau[i];

        if ( i == 2 || i == 5 || i == 8)
        {
            cout << "|" <<endl;
        }

    }
}
