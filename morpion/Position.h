//
// Created by johstar on 19/03/23.
//

#ifndef MORPION_POSITION_H
#define MORPION_POSITION_H


class Position
{
    public:

        //Prototype Constructeur par défaut
        Position();

        //Constructeur par copie dont le parametre est passer par référence, cette référence doit être constante pour assurer la non modification de l'objet
        Position(const Position &position);

        //Constructeur par parametre.
        Position(int x, int y);

        // getter et setter
        int getX() const;//Le suffixe const sert à dire qu'il s'agit d'un accesseur
        void setX(int x);

        int getY() const;
        void setY(int y);

        //Autre methode
        void afficherPosition() const; //Methode défini dans le fichier source

    //attribut
    private:
        int _x, _y;
};


inline void Position::setX(int x) //Mehtode set avec le prefixe (inline) qui doit être déclaré dans le fichier d'entête pour permettre au compilateur de générer le code et de l'inserrer à chaque appel de la fonction
{
    this -> _x = x;
}

inline void Position::setY(int y)
{
    this -> _y = y;
}


#endif //MORPION_POSITION_H
