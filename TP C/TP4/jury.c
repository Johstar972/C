//
// Created by johstar on 12/04/23.
//

#include <stdio.h>
#include<stdlib.h>
#include "moyenne.h"



int main(int argc, char* argv[])
{
    moyPromo moyennePromotion;
    if(argc > 2 || argc == 1)
    {
        printf("Utilisation : jury nom_fichier_moyennes\n");
    }
    else
    {
        //A changer par le nom du fichier
        lire_moyennes(argv[1],&moyennePromotion);
        printf("Nom du fichier: %s\n",argv[1]);
        int i;
        for (i = 0; i < moyennePromotion.nbEtudiants; i++) {
            free(moyennePromotion.etudiants[i].nom);
            free(moyennePromotion.etudiants[i].prenom);
        }
        free(moyennePromotion.etudiants);
    }
}