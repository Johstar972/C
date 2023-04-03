//
// Created by johstar on 19/03/23.
//

#include "Plateau.h"
#include <iostream>

using namespace std;

//Implémentation du constructeur par défaut
Plateau::Plateau()
{
    for(int i = 0; i < ARRAY_SIZE; i++)//Initialisation du tableau dans le constructeur par défaut
    {
        array[i] = ' ';
    }
    //La taille de mon vector est initialiser à null.
}

//Implémentation des getters
vector<Symbole> Plateau::getListeSymbole() const
{
    return this->listeSymbole;
}

char* Plateau::getArray()
{
    return this->array;
}



//Implémentation de la methode d'affichage du tableau
void Plateau::afficherArray() const
{
    cout << "|---|---|---|" << endl;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "| " << array[i] << " ";

        if ( i == 2 || i == 5 || i == 8)
        {
            cout << "|" <<endl;
            cout << "|---|---|---|" << endl;
        }
    }
}


