//
// Created by johstar on 19/03/23.
//

#include "Joueur.h"

Joueur::Joueur(): name("inconnu"), symbole(' ') {}

Joueur::Joueur(Joueur &joueur): name(joueur.name), symbole(joueur.symbole){}

Joueur::Joueur(string name, char symbole): name(name), symbole(symbole) {}


//Implémentation des getters
string Joueur::getName() const
{
    return this->name;
}

char Joueur::getSymbole() const
{
    return this->symbole;
}

//TODO:Finir cette méthode et revoir la classe joueur, doit-elle avoir en attribut un symbole ou pas si non changer le parametre de la méthode pour enlever le symbole
void Joueur::tourDeJeu(Plateau *plateau, Symbole symbole)
{
    //Demander la coordonner là ou le joeur veut mettre son symbole
    //ajouter le symbole du joueur et sa position dans la liste de symbole du plateau
    //modifier le tableau en ajoutant le symbole du joueur.
    int x, y;
    cout << "Choisissez votre case (c'est une position, vous entrerez le x puis le y ce celle-ci)" << endl;
    cout << "X :";
    cin >> x;
    cout << "Y :";
    cin >> y;

    plateau->getArray()[x*ARRAY_SIZE + y] = symbole.getCharactere();
    


}