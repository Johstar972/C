//
// Created by johstar on 12/04/23.
//

#ifndef TP4_MOYENNE_H
#define TP4_MOYENNE_H

typedef struct
{
    char *nom, *prenom;
    double *moyennes;
    int nbUEValide;
    char decision;
} moyEtu;

typedef struct
{
    int nbEtudiants, nbUE;
    moyEtu *etudiants;

}moyPromo;



void lire_moyennes(char nomfic[], moyPromo *m);
void decisionJury(moyPromo *m);
#endif //TP4_MOYENNE_H
