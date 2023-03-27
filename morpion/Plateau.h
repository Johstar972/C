//
// Created by johstar on 19/03/23.
//

#ifndef MORPION_PLATEAU_H
#define MORPION_PLATEAU_H
#define TAILLE_TABLEAU 9

#include <vector>
#include "Symbole.h"

using namespace std;


class Plateau {
public:
    //Constructeur par défaut
    Plateau();

    //getter setter
    char* getTableau(); //retourne un pointeur vers le 1er élement du tableau mais en lecture seul, sans possibilité de le modifier

    vector<Symbole> getListeSymbole() const;

    void setTableau(char *tableau); // Prend pointeur vers l'adresse du premiere élement du tableau

    void setListSymbole(vector<Symbole> listeSymbole);

    //Autre methode
    void initTableau() const;
    void afficherTableau() const;

private:
    char *tableau;
    vector<Symbole> listeSymbole;

};

inline void Plateau::setTableau(char *tableau)
{
    for(int i = 0; i < TAILLE_TABLEAU; i++)
    {
        this->tableau[i] = tableau[i];
    }
}

inline void Plateau::setListSymbole(vector<Symbole> listeSymbole)
{
    this->listeSymbole.assign(listeSymbole.begin(), listeSymbole.end()); // on remplace grâce à assign les éléments de vector par les élément mis en parametre

}

#endif //MORPION_PLATEAU_H
