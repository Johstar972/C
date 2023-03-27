#include <iostream>
#include "Position.h"
#include "Plateau.h"
#include "Symbole.h"
#include "Joueur.h"
using namespace std;
int main() {
    string name1, name2;
    char symbole1, symbole2;
    int choix;

    cout << "Joueur 1:\nChoisissez votre pseudo :";
    cin >> name1;
    cout << "Choisissez votre symbole :" << endl; cout << "1. X  2. O" << endl;
    cin >> choix;

    if(choix = 1)
    {
        symbole1 = 'X';
    }
    else
    {
        symbole1 = 'O';
    }

    Joueur joueur1(name1,symbole1);

    cout << "Joueur 2:\nChoisissez votre pseudo :";
    cin >> name2;
    if(symbole1 == 'X')
    {
        symbole2 = 'O';
    }
    else
    {
        symbole2 = 'X';
    }

    Joueur joueur2(name2, symbole2);


    return 0;
}
