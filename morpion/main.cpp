#include <iostream>
#include "Plateau.h"
#include "Symbole.h"
#include "Player.h"

using namespace std;

void runGame(Player joueur1, Player joueur2, Plateau *plateau);


int main() {
    string name1, name2;
    Symbole symbole1, symbole2;
    int choix;

    Plateau plateau = Plateau();

    cout << "Joueur 1:\nChoisissez votre pseudo :";
    cin >> name1;
    cout << "Choisissez votre symbole :" << endl; cout << "1. X  2. O" << endl;
    cin >> choix;

    if(choix = 1)
    {
        symbole1.setCharactere('X');
    }
    else
    {
        symbole1.setCharactere('O');
    }

    Player joueur1(name1,symbole1);

    cout << "Joueur 2:\nChoisissez votre pseudo :";
    cin >> name2;
    if(symbole1.getCharactere() == 'X')
    {
        symbole2.setCharactere('O');
    }
    else
    {
        symbole2.setCharactere('X');
    }

    Player joueur2(name2, symbole2);

    joueur1.afficherPlayer();
    joueur2.afficherPlayer();

    runGame(joueur1, joueur2, &plateau);


    return 0;
}

void runGame(Player joueur1, Player joueur2, Plateau *plateau)
    {
    if(joueur1.getSymbole().getCharactere() == 'X')
    {
        plateau->afficherArray();
        cout << "C'est au tour de :" + joueur1.getName() << endl;
        joueur1.tourDeJeu(plateau);
    }
    else{
        plateau->afficherArray();
        cout << "C'est au tour de :" + joueur2.getName() << endl;
        joueur2.tourDeJeu(plateau);
    }
    }
