//
// Created by johstar on 19/03/23.
//

#include "Player.h"

Player::Player(): name("inconnu"), symbole() {}

Player::Player(Player &player): name(player.name), symbole(player.symbole){}

Player::Player(string name, Symbole symbole): name(name), symbole(symbole) {}


//Implémentation des getters
string Player::getName() const
{
    return this->name;
}

Symbole Player::getSymbole() const
{
    return this->symbole;
}

//TODO:Finir cette méthode et revoir la classe Joueur, doit-elle avoir en attribut un symbole ou pas si non changer le parametre de la méthode pour enlever le symbole
void Player::tourDeJeu(Plateau *plateau)
{
    //Demander la coordonner là ou le joeur veut mettre son symbole
    //ajouter le symbole du joueur et sa position dans la liste de symbole du plateau
    //modifier le tableau en ajoutant le symbole du joueur.
    int x = 0, y = 0;
    cout << "Choisissez votre case (c'est une position, vous entrerez le x puis le y ce celle-ci)" << endl;
    cout << "X :";
    cin >> x;
    cout << "Y :";
    cin >> y;

    plateau->getArray()[x*ARRAY_SIZE+ y] = symbole.getCharactere();

}

//Methode permettat d'afficher un joueur
void Player::afficherPlayer()
{
    cout << "Nom du player:" + name + ", symbole: " +  symbole.getCharactere() << endl;
}